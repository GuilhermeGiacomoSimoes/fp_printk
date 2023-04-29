#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "service.h"
#include "fp_printk.h"

#define OURMODNAME "fp_printk"

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.4.1");

void fp_printk(int number, int decimal_places, char* destination)
{
	char* str_result = int_to_fp_str(number, decimal_places);
	strcpy(destination, str_result);
}

static int __init fp_printk_init(void)
{
	printk(KERN_INFO "%s: initial execute module", OURMODNAME);
	return 0;
}

static void __exit fp_printk_exit(void)
{
	printk(KERN_INFO "%s: module end", OURMODNAME);
}

module_init(fp_printk_init);
module_exit(fp_printk_exit);

EXPORT_SYMBOL(fp_printk);
