#include "function_main.h"
/**
 *  format_specifier(- Handles the logic for known format specifiers
 * @fmrt: Format string
 * @index: Pointer to the current index in the format string
 * @ap: Variadic argument list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int  format_specifier(const char *fmrt, int *index, va_list ap,
		      char buffer[], int flags, int width,
		      int precision, int size)
{
	data array[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"\0", NULL}
		};
	int i;
	int num_counter = 0;

	for (i = 0; array[i].format != NULL; i++)
	{
		if (fmrt[*index] == *array[i].format)
		{
			return (array[i].ptr(ap, buffer, flags, width,
					     precision, size));
		}
	}

	return (num_counter);
}
#include "function_main.h"
/**
 * unknown_specifier - Handles the logic for unknown format specifiers
 * @fmrt: Format string
 * @index: Pointer to the current index in the format string
 * @buffer: Buffer array to handle print
 * @width: Width specifier
 *
 * Return: Number of characters printed
 */
int unknown_specifier(const char *fmrt, int *index,
				    char buffer[], int width)
{
	int unfixed_len = 0;

	UNUSED(buffer);
	if (fmrt[*index] == '\0')
	{
		return (-1);
	}

	unfixed_len = unfixed_len + write(1, "%%", 1);
	if (fmrt[*index - 1] == ' ')
	{
		unfixed_len = unfixed_len + write(1, " ", 1);
	}
	else if (width)
	{
		--(*index);
		while (fmrt[*index] != '%' && fmrt[*index] != '\0')
		{
			--(*index);
		}
		if (fmrt[*index] == ' ')
		{
			--(*index);
		}
		return (1);
	}
	unfixed_len = unfixed_len + write(1, &fmrt[*index], 1);

	return (unfixed_len);
}
#include "function_main.h"
/**
 * _print- Handles the format specifier and calls the appropriate handler
 * @fmrt: Format string
 * @index: Pointer to the current index in the format string
 * @ap: Variadic argument list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int _print(const char *fmrt, int *index, va_list ap, char buffer[],
	   int flags, int width, int precision, int size)
{
	int result = format_specifier(fmrt, index, ap, buffer, flags,
				      width, precision, size);

	if (result == 0)
	{
		result = (unknown_specifier(fmrt, index, buffer, width));
	}

	return (result);
}
/******implement_char********/
#include "function_main.h"
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
