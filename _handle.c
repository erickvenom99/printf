#include "main.h"
#include <stdarg.h>
/**
 * _print - Prints an argument
 * @format: format string to print the arguments.
 * @index: index.
 * @ap: list of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: 1 or 2;
 */
int _print(const char *format, int *index, va_list ap, char buffer[],
		 int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, num_counter = -1;
	data array[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'i', print_int}, {'d', print_int}, {'b', p_binary},
		{'u', print_unsigned}, {'\0', NULL}
	};

	for (i = 0; array[i].format != '\0'; i++)
		if (format[*index] == array[i].format)
			return (array[i].ptr(ap, buffer, flags, width,
					    precision, size));
	if (array[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &format[*index], 1);
		return (unknown_len);
	}
	return (num_counter);
}
/******implement_char********/
#include "main.h"
/**
 * implement_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int implement_char (char c, char buffer[],
		      int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFFER_SIZE - i
						 - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1],
				      width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
