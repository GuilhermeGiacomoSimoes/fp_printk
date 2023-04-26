#include "service.h"

char* int_to_fp_str(int number, int decimal_places) {
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

	return &buffer[buf_index + 1];
}