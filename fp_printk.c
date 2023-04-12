#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.2.0");

static void __init fp_printk_init(void) 
{
    fp_printk();
}

int strlength(char* str) 
{
    return sizeof(str)/sizeof(char);
}

void memory_set_value(char *r, char value, int size) 
{
    for(int i=0; i < size; i++) {
        *(r + i) = value;
    }
}

void float_2_byte() 
{
    float number;
    char* destination;
    module_param(number, float, 0660);
    module_param(destination, char*, 0660);

    char result[100];

    int d_val = number, 
        dec = (int) (number * 100) % 100, 
        i=3;

    memory_set_value(result, '0', 100);
    result[0] = (dec % 10) + '0';
    result[1] = (dec / 10) + '0';
    result[2] = '.';

    while(d_val > 0) 
    {
        result[i] = (d_val % 10) + '0';
        d_val /= 10;
        i++;
    }

    int j = 0;
    int zero_fill = 1;
    for(i=strlength(result)-1; i>=0; i--) {
        if(result[i] != '0' || !zero_fill) {
            zero_fill = 0;
            *(destination + j) = result[i];
            j++;
        }
    }
}

static void __exit fp_printk_exit(void) 
{
    printk(KERN_INFO "module end");
}

module_init(fp_printk_init);
module_exit(fp_printk_exit);

EXPORT_SYMBOL(fp_printk);