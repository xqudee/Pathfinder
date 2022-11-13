#include "../inc/libmx.h"

int mx_atoi(const char *str) {
	int number = 0;
	bool neg = false;
	
	while (mx_isspace(*str)) str++;
	if (*str == '-') {
		neg = true;
		str++;
	}
	while (*str != '\0') {
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (neg) number *= -1;
	return number;
}

