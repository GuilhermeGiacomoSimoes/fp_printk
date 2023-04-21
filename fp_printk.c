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
module_param(decimal_places, int, 0660);

void fp_printk(void)
{
	static char buffer[32] = {0};
	int buf_index = 30;
	int count_decimal_place = 0;
	int point_include = 0;

	for(; number && buf_index; --buf_index, number /= 10) {
		count_decimal_place++;
		if(!point && count_decimal_place > decimal_places) {
			buffer[i] = '.';
			i--;
			point_include = 1;
		}

		buffer[i] = "0123456789"[number % 10];
	}

	printk("%s", &buffer[buf_index+1]);
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
