#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
 
static struct proc_dir_entry *proc_entry;
static ssize_t myproc_write(struct file *file, const char __user *buff, size_t len,  loff_t *pos);
static ssize_t myproc_read(struct file *filp,char __user *buff,size_t len, loff_t *pos);
static char msg[255];
static struct file_operations my_ops={
.read=myproc_read,
.write=myproc_write,
.owner=THIS_MODULE,
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
 
static ssize_t myproc_write(struct file *file, const char __user *buff, size_t len,  loff_t *pos)
{
    unsigned long len2 = len;
    if (len2>=sizeof(msg))
    len2=sizeof(msg)-1;
    if (raw_copy_from_user(msg, buff, len2))
        return -EFAULT;
    msg[len2] = '\0';
    return len;
}
 
static int __init myproc_init(void)
{
        proc_entry = proc_create("myproc", 0666, NULL,&my_ops);
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
