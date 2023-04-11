#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.1");

//static void __init fp_printk_init(float number) 
//{
//    fp_printk();
//}
//
static char* fp_printk(float number) 
{
    number += 0.005;
    char result[100];

    int d_val = number, 
        dec = (int) (number * 100) % 100, 
        i=3;

    memset(result, 0, 100);
    result[0] = (dec % 10) + '0';
    result[1] = (dec / 10) + '0';
    result[2] = '.';

    while(d_val > 0) 
    {
        result[i] = (d_val % 10) + '0';
        d_val /= 10;
        i++;
    }

    return result;
}

//static void __exit fp_printk_exit(void) 
//{
//}

//module_init(fp_printk);
//module_exit();

EXPORT_SYMBOL(fp_printk);