#include <linux/init.h>
#include <linux/module.h>
  
#include <linux/sched/signal.h>
// #include <linux/sched.h>
  
MODULE_LICENSE("Dual BSD/GPL");
  
struct task_struct *task;  //Structure defined in sched.h for tasks/processes
struct task_struct *task_child; // Structure needed to iterate through task children
struct list_head *list; //Structure needed to iterate through the list in each task->children struct
  
static int process_init(void)
{
  printk(KERN_INFO "%s","LOADING MODULE\n");
  // for_each_process() MACRO for iterating through each task in the os located in linux/sched/signal.h
  for_each_process( task ){
    // log parent pid/uid(user id)/comm(command)  
    printk(KERN_INFO "PARENT PID: %d UID: %d PROCESS: %s\n",task->pid, get_task_cred(task)->uid, task->comm); 
    /* 
      // list_for_each MACRO to iterate through task->children      
      list_for_each(list, &task->children){
        // using list_entry to declare all vars in task_child struct
        task_child = list_entry( list, struct task_struct, sibling );
        // log child of which process[pid] and child pid/uid/comm
        printk(KERN_INFO "\tCHILD OF %s[%d] PID: %d UID: %d PROCESS: %s\n",
          task->comm, task->pid, task_child->pid, get_task_cred(task_child)->uid, task_child->comm); 
      }
    */
  printk("-----------------------------------------------------\n");
  }

  return 0;
}
  
static void process_exit(void)
{
  printk(KERN_INFO "%s","REMOVING MODULE\n");
}
  
module_init(process_init);
module_exit(process_exit);