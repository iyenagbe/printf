#include "main.h"

/**
 * get_precision - the precision for printing
 * @format: Formatted string to print the arguments
 * @b: arguments to be printed.
 * @list: the list of an arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *b, va_list list)
{
	int curr_b = *b + 1;
	int precision = -1;

	if (format[curr_b] != '.')
		return (precision);

	precision = 0;

	for (curr_b += 1; format[curr_b] != '\0'; curr_b++)
	{
		if (it_digit(format[curr_b]))
		{
			precision *= 10;
			precision += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*b = curr_b - 1;

	return (precision);
}
