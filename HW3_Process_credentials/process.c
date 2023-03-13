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
  for_each_process( task ){  // for_each_process() MACRO for iterating through each task in the os located in linux/sched/signal.h
    printk(KERN_INFO "PARENT PID: %d PROCESS: %s STATE: %ld\n",task->pid, task->comm, task->state); // log parent id/executable name/state
    list_for_each(list, &task->children){    //list_for_each MACRO to iterate through task->children
      task_child = list_entry( list, struct task_struct, sibling );    //using list_entry to declare all vars in task_child struct
      printk(KERN_INFO "\tCHILD OF %s[%d] PID: %d PROCESS: %s STATE: %ld\n",task->comm, task->pid, //log child of and child pid/nam
        task_child->pid, task_child->comm, task_child->state);
    }
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