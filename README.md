# int to float point string

## DESCRIPTION
This module allows that you see in `dmesg` or in logs number with float point. <br>
Although we can work with arithimetic using the kernel_fpu_begin(), we dont can see he in `dmesg` or logs. <br>
int_to_fp_str convert the int to string for using in printk();<br><br>

## INSTALATION
Only run this sequence of commands:<br>
```
make //for compile
sudo insmod int_to_fp_str.ko
```
<br>
Well ... that's done 
