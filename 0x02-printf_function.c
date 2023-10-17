#include "main.h"

/***Print Unsigned Number*****/
/**
 * print_unsigned - Print unsigned number
 * @types: List of arguments
 * @buffer: Arrays buffer to handle print
 * @flags:  Calculating flags
 * @width: Width
 * @precision: Specifying Precision
 * @size: specifying size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/*** Print Unsigned Number In Octal  ***/
/**
 * print_octal - Print an Unsigned Number In Octal
 * @types: List of arguments
 * @buffer: Array buffer to handle print
 * @flags: Calculating active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of char to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/***** Print Unsigned Number In Hexsdecimal ****/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: List of arguments
 * @buffer: Arrays buffer to handle print
 * @flags: Calculating active flags
 * @width: Width
 * @precision: Specifying precision
 * @size: Size specifying Size
 * Return: Number of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***** Print  Unsigned Number In Upper Hexadecimal *****/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal
 * @types: List of arguments
 * @buffer: Array buffer to  handle print
 * @flags:  Calculating active flags
 * @width: Width
 * @precision: Specifying Percission
 * @size: Specifying Size
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'x', width, precision, size));
}

/****  Print Hexx Num nN Lower Or Upper ****/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Arrays buffer to handle print
 * @flags: Calculating active flags
 * @flag_ch: Calculating active flags
 * @width: Width
 * @precision: Specifying percision
 * @size: Specifying sizes
 * @size: Specifying sizes
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

