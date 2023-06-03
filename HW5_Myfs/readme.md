# HW5 - Myfs

* 請根據附檔程式(myfs.c)修改，達成以下功能
1. 將檔案系統的跟目錄改為下列結構
```
/--+ input (dir)
   |   |
   |   +-- a (file)
   |   +-- b (file)
   |
   + output (dir)
       |
       +-- add (file)
       +-- sub (file)
```       
2. 可以透過 echo 數字 > /input/a 和 echo 數字 >/input/b 來設定a和b的值，數值大小0~255之間  
3. 可以透過 cat /output/add取得a+b的值，透過cat /output/sub取得a-b的值。

## Requirement: 
1.   
繳交項目:  
 * myfs.c  
 * myfs.ko  
 * 執行截圖  
    * $ insmod myfs.ko
    * $ lsmod
      * 需看到myfs.ko
    * $ mount -t myfs /dev/loop0 /mnt
    * $ mount
      * 需看到 /mnt的掛載資訊如 /dev/loop0 on /mnt type myfs (rw)
    * 
    ```
        # echo 3 >/mnt/input/a
        # cat /mnt/input/a
        # echo 2 > /mnt/input/b
        # cat /mnt/input/b
        # cat /mnt/output/add
        # cat /mnt/output/sub
        # cat /mnt/output/add
        # cat /mnt/output/sub
    ```

## Details:  

* Screenshot:  
<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW5_Myfs/hw5/capture1.jpg" width="1100" height="400" alt="syslog"/><br/>

<img src="https://github.com/frankkn/Linux_Kernel/blob/master/HW5_Myfs/hw5/capture2.jpg" width="1100" height="400" alt="syslog"/><br/>
