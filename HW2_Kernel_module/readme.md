# HW2 - Kernel Module

* 分別編譯並載入hello與hellop這兩個kernel modules。 
* 另外撰寫一個hellop3，可傳入整數a整數b和字串c，在載入時透過printk印出a*b次的c字串。

## Requirement: 
1.
依序執行下列指令，進行module的載入與卸除。
```
uname -a
insmod hello.ko
insmod hellop.ko howmany=5 whom="IIS"
insmod hellop3.ko a=3 b=2 c=module_text
lsmod | grep hello
rmmod hellop
rmmod hello
rmmod hellop3
lsmod | grep hello
```
2.   
繳交項目:  
  1. 執行作業中，指令的畫面(截圖)  
  2. 節錄指令`dmesg` or `cat /var/log/syslog`中所新增的內容(截圖或文字檔)  
  3. hellop3.c 與 hellop3.ko  