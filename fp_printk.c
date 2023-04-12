#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Guilherme Giacomo Simoes <trintaeoitogc@gmail.com>");
MODULE_DESCRIPTION("This lib will show float-point in printk()");
MODULE_LICENSE("MIT");
MODULE_VERSION("0.3.0");

static float number;
static char *destination;
module_param(number, float, 0660);
module_param(destination, charp, 0660);

int strlength(char *str)
{
	return sizeof(str) / sizeof(char);
}

void memory_set_value(char *r, char value)
{
	for (int i = 0; i < strlength(r) - 1; i++) {
		*(r + i) = value;
	}
}

void fp_printk(void)
{
	char result[100];

	int d_val = number, dec = (int)(number * 100) % 100, i = 3;

	memory_set_value(result, '0');
	result[0] = (dec % 10) + '0';
	result[1] = (dec / 10) + '0';
	result[2] = '.';

	while (d_val > 0) {
		result[i] = (d_val % 10) + '0';
		d_val /= 10;
		i++;
	}

	int index_destination = 0;
	int zero_fill = 1;
	for (i = strlength(result) - 1; i >= 0; i--) {
		if (result[i] != '0' || !zero_fill) {
			zero_fill = 0;
			*(destination + index_destination) = result[i];
			index_destination++;
		}
	}
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
