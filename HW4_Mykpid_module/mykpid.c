#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
 
static struct proc_dir_entry *proc_entry;
static ssize_t myproc_write(struct file *file, const char __user *buff, size_t len,  loff_t *pos);
static ssize_t myproc_read(struct file *filp,char __user *buff,size_t len, loff_t *pos);
static char msg[255];
// static struct file_operations my_ops={
static struct proc_ops my_ops={
    .proc_read=myproc_read,
    .proc_write=myproc_write,
    //.owner=THIS_MODULE,
};
 
static ssize_t myproc_read(struct file *filp,char __user *buff,size_t count, loff_t *pos)
{
    unsigned int len=strlen(msg);
    unsigned long p = *pos;
    if(p>=len)
        return 0;
    if (count > len-p)
        count = len-p;
 
    if(raw_copy_to_user(buff+p,msg+p, count))
        return -EFAULT;
 
    *pos+=count;
 
    printk("read pos:%ld,count:%ld\n",p,count);
    return count;
}

  
static int send_signal(int pid) {
    int ret;
    struct kernel_siginfo info;
    struct task_struct *t;

    // Set the signal 
    memset(&info, 0, sizeof(struct kernel_siginfo));
    info.si_signo = SIGINT;
    info.si_code = SI_QUEUE;
    rcu_read_lock();

    // Find process with given pid
    t = pid_task(find_pid_ns(pid, &init_pid_ns), PIDTYPE_PID);  
    
    if(t == NULL){
        pr_err("No such pid\n");
        rcu_read_unlock();
        return -ENODEV;
    } 
    /*
    else{  
   	    printk("PID Confirmed %d", t->pid); 
    }
    */

    rcu_read_unlock();
 
    // Send the signal  
    ret = send_sig_info(SIGINT, &info, t);
    if (ret < 0) {
        pr_err("error sending signal\n");
        return ret;
    }   
    return 0;
}
 
static ssize_t myproc_write(struct file *file, const char __user *buff, size_t len,  loff_t *pos)
{
    unsigned long len2 = len;
    if (len2>=sizeof(msg))
    len2=sizeof(msg)-1;
    if (raw_copy_from_user(msg, buff, len2)) 
        return -EFAULT;
    //msg[len2] = '\0';
    
    // TODO
    int pid;
    sscanf(msg, "%d", &pid);
    msg[sizeof(msg) - 1] = '\0';
    //printk("%s(#%d): pid(%d), sig(%d)\n",__func__, __LINE__, pid, sig);
    send_signal(pid);

    return len;
}
 
static int __init myproc_init(void)
{
        proc_entry = proc_create("mykpid", 0666, NULL,&my_ops);
        if (!proc_entry) {
                printk(KERN_ERR "Can't create /proc/myproc\n");
                return -1;
        }
        return 0;
}
 
static void __exit myproc_exit(void)
{
        remove_proc_entry("myproc", NULL);
}
 
module_init(myproc_init);
module_exit(myproc_exit);
