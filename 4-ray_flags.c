#include "main.h"

/**
 * get_flags - active flags
 * @format: Formatted string to print the arguments
 * @b: a parameter
 * Return: Flags:
 */

	int get_flags(const char *format, int *b)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_b;
	int flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_b = *b + 1; format[curr_b] != '\0'; curr_b++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_b] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*b = curr_b - 1;

	return (flags);
}
