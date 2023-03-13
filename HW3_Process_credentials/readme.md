# HW3 - Process credentials

* 參考process.c與kernel source內的資料結構，列出每一個process的pid，uid，comm。

## Requirement: 

1. 繳交項目:
* module輸出(/var/log/syslog)
* $ ps -ax -opid,uid,comm的輸出
* module source code

2. 參考資料結構:
* /include/linux/cred.h
* struct cred
* extern const struct cred *get_task_cred(struct task_struct *);
* /include/linux/sched.h
* struct task_struct

## Details:

Using [/include/linux/cred.h](https://lxr.linux.no/linux+v5.17/include/linux/cred.h) for searching cred-related data structure.  
Using [/include/linux/sched.h](https://lxr.linux.no/linux+v6.0.9/include/linux/sched.h) for searching task-related data structure.


* Syslog output:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW3_Process_credentials/syslog/syslog1.jpg" width="800" height="600" alt="syslog"/><br/>
* ps output:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW3_Process_credentials/ps/ps1.jpg" width="800" height="600" alt="syslog"/><br/>
* Commands:
```
# sudo su -
# sudo mount -t vboxsf shared_folder /home/frank/Desktop/data
# cd /home/frank/homework3
# cp /home/frank/Desktop/data/process_pid_uid_comm.c .
# make 
# insmod process_pid_uid_comm.ko
# lsmod | grep process_pid_uid_comm
# cat var/log/stslog
# id frank
# ps -ax -opid,uid,comm