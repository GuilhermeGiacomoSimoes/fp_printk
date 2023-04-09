#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.1");

static void __init fp_printk_init(float number) 
{
    fp_printk();
}

static char* fp_printk(float number) 
{

}

static void __exit fp_printk_exit(void) 
{
    size_t number_length = snprintf(NULL, 0, "%f", number);
    char number_in_str = malloc(number_length);
    snprinf(number_in_str, number_length+1, "%f", number);

    return buff;
}

module_init(fp_printk);
module_exit();

EXPORT_SYMBOL(fp_printk);