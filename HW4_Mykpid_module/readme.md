# HW4 - Mykpid Module

* 參考myproc.c的myproc_write()，撰寫一個mykpid的module，功能如下:  
  執行下面兩行後:  
  echo PID > /proc/mykpid  (指定哪個PID接收signal    
  echo INT > /proc/mykpid  (指定要傳送什麼signal  
  process為PID的程式會收到SIGINT的signal，  
  接收signal的程式可以參考signal.c。
  
  Example:  
  假設signal.c編譯出來的程式為a.out，且其pid為2023
  ```
  echo 2023 > /proc/mykpid
  echo INT > /proc/mykpid


## Requirement: 
1.   
繳交項目:  
* 執行作業中，執行過程的畫面(截圖)，必須包含uname -a的訊息。  
* mykpid.c 與 mykpid.ko  

## Details:  

* Commands:  



