#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/fpu/api.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static char* __init fp_printk(float number) 
{

}

EXPORT_SYMBOL(fp_printk);