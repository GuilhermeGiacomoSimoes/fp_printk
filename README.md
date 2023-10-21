# int to float point string

## DESCRIPTION
This lib allows that you see in the kernel logs with `sudo dmesg`, number with float point. <br>
Although we can work with arithimetic using the kernel_fpu_begin(), we dont can see this in `dmesg`. <br>
int2fpstr convert the int to string for using in printk();<br><br>

## HOW TO USE
If you get my [fork kernel](https://github.com/GuilhermeGiacomoSimoes/linux), you has this lib and another changes. <br>
But if you run the kernel from linus, then you need move this lib to kernel, compile and move binary result <br>
to your `/boot`.

### MOVE THE LIB
Clone this repository: <br>
`git clone https://github.com/GuilhermeGiacomoSimoes/fp_printk` <br>

Then you need move the int2fpstr.h to kernel source code: <br>
`mv int2fpstr.h ${KERNEL_SOURCE_TREE}/include/kernel`<br>

This is enough to use the int2fpstr. But if you want the unittests, then you should move this to kernel source tree too:<br>
`mv int2fpstr_kunit.c ${KERNEL_SOURCE_TREE}/lib`<br>
Then, you need increment in the end files Makefile and Kconfig.debug the follow:<br>
Makefile<br>
`obj-$(CONFIG_INT2FPSTR_KUNIT_TEST) += int2fpstr_kunit.o`<br>

Kconfig.debug
```
config INT2FPSTR_KUNIT_TEST
	tristate "Test int2fpstr library" if !KUNIT_ALL_TESTS
	depends on KUNIT
	default KUNIT_ALL_TESTS
```
<br><br>


## RUN UNITTEST
To run this unittest in kernel linux, first you need dependency installs, and then
run this:<br>
`./tools/testing/kunit/kunit.py run "int2fpstr"`



## PROBLEMNS
This lib have problemns.<br>
The first is that you need use the `kfree` in the result before call int2fpstr function. <br>
If you is a experient dev, you know that pointers is a source bug a lot.
