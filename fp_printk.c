#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.3.0");

static int number;
static char *destination;
static int decimal_places;
module_param(number, int, 0660);
module_param(destination, charp, 0660);
module_param(decimal_places, int, 0660);

static int strlength(char *str)
{
	return sizeof(str) / sizeof(char);
}

static void memory_set_value(char *r, char value)
{
	for (int i = 0; i < strlength(r) - 1; i++) {
		*(r + i) = value;
	}
}

void fp_printk(void)
{
	static char buffer[32] = {0};
	static const int decimal_base = 10;

	int i = 30;
	for(; number && i; --i, number /= decimal_base) 
		buffer[i] = "0123456789"[number % decimal_base];

	destination = &buffer[i+1];
}

static int __init fp_printk_init(void)
{
	if (destination == NULL)
		return -EINVAL;
	fp_printk();
	return 0;
}

static void __exit fp_printk_exit(void)
{
	printk(KERN_INFO "module end");
}

module_init(fp_printk_init);
module_exit(fp_printk_exit);

EXPORT_SYMBOL(fp_printk);
