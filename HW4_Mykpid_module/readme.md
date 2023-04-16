# HW4 - Mykpid Module

* 參考myproc.c的myproc_write()，  
  撰寫一個mykpid的module，  
  功能如下:  
  >執行下面兩行後  
  echo PID > /proc/mykpid  (指定哪個PID接收signal    
  echo INT > /proc/mykpid  (指定要傳送什麼signal  
  process為PID的程式會收到SIGINT的signal，  
  接收signal的程式可以參考signal.c。
      
  Example:  
  假設signal.c編譯出來的程式為a.out，且其pid為2023
  ```
  echo 2023 > /proc/mykpid
  echo INT > /proc/mykpid
  ```

## Requirement: 
1.   
繳交項目:  
* 執行作業中，執行過程的畫面(截圖)，必須包含uname -a的訊息。  
* mykpid.c 與 mykpid.ko  

## Details:  

* Screenshot:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW4_Mykpid_module/HW4/signal.jpg" width="1100" height="400" alt="syslog"/><br/>

* Commands:
```
# sudo su -
# sudo mount -t vboxsf shared_folder /home/frank/Desktop/data
# cd /home/frank/Desktop/data/HW4
# ./a.out
```
```
# sudo su -
# cd /home/frank/Desktop/data/HW4
# make
# insmod mykpid.ko
# lsmod | grep mykpid
# ps auwx | grep a.out  // search pid of a.out
# ls /proc/mykpid // confirmed folder: mykpid is created 
# echo 2292 > /proc/mykpid
# echo INT > /proc/mykpid
# uname -a
```


