# HW3 - Process credentials

* 參考process.c與kernel source內的資料結構，列出每一個process的pid，uid，comm。

## Requirement: 

1.   
繳交項目:  
  1. module輸出(/var/log/syslog) 
  2. $ps -ax -opid,uid,comm的輸出
  3. module source code

2.  
參考資料結構:
  1. /include/linux/cred.h
  2. struct cred
  3. extern const struct cred *get_task_cred(struct task_struct *);
  4. /include/linux/sched.h
  5. struct task_struct

## Details:

Using [lxr.linux](https://lxr.linux.no/linux+v5.17/include/linux/cred.h) for searching cred-related data structure.  
Using [lxr.linux](https://lxr.linux.no/linux+v6.0.9/include/linux/sched.h) for searching task-related data structure.

ps output:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW3_Process_credentials/ps/ps1.jpg" width="400" height="300" alt="syslog"/><br/>
syslog output:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW3_Process_credentials/syslog/syslog1.jpg" width="400" height="300" alt="syslog"/><br/>