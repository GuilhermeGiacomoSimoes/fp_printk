#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.4.1");

void fp_printk(int number, int decimal_places)
{
	static char buffer[32] = { 0 };
	int buf_index = 30;
	int count_decimal_place = 0;
	int point_include = 0;

	for (; number && buf_index; --buf_index, number /= 10) {
		count_decimal_place++;
		if (!point_include && count_decimal_place > decimal_places) {
			buffer[buf_index] = '.';
			buf_index--;
			point_include = 1;
		}

		buffer[buf_index] = "0123456789"[number % 10];
	}

	printk("%s\n", &buffer[buf_index + 1]);
}

static int __init fp_printk_init(void)
{
	return 0;
}

static void __exit fp_printk_exit(void)
{
	printk(KERN_INFO "module end");
}

module_init(fp_printk_init);
module_exit(fp_printk_exit);

EXPORT_SYMBOL(fp_printk);
