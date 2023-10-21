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

Then you import the lib in your module `#include <linux/int2fpstr>`. Follow i show the simples use example:
```
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/int2fpstr.h>

MODULE_AUTHOR("SEU NOME <seu_email@email.com>");
MODULE_DESCRIPTION("Introducao a criacao de driver pra linux");

static int __init hello_world_init(void)
{
    int int_number = 1234;
    int count_decimal_places = 2;

    //str_number contain value = "12.34"
    char *str_number = int2fpstr(int_numer, count_decimal_places);
    pr_info("%s", str_number);

    return 0;
}

static void __exit hello_world_exit(void)
{
    pr_info("Adeus mundo cruel\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
```
This is enough to use the int2fpstr. But if you want the unittests, then you read section follow.
<br><br>


## RUN UNITTEST
You should move the int2fpstr_kunit.c to kernel source tree too:<br>
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
To run this unittest in kernel linux, first you need dependency installs, and then
run this:<br>
`./tools/testing/kunit/kunit.py run "int2fpstr"` <br><br>



## PROBLEMNS
This lib have problemns.<br>
The first is that you need use the `kfree` in the result after call int2fpstr function. <br>
If you is a experient dev, you know that pointers is a source of bug.
