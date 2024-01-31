#include "function_main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int num_counter = 0;
	int save_print = 0;
	int i, width, precision, flags, size;
	int b_index = 0;
	va_list ap;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b_index++] = format[i];
			if (b_index == BUFFER_SIZE)
				print_buffer(&b_index, buffer);
			num_counter++;
		}
		else
		{
			print_buffer(&b_index, buffer);
			flags = get_flags(format, &i);

			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			i++;
			save_print = _print(format, &i, ap,
			       buffer, flags, width, precision, size);
			if (save_print == -1)
				return (-1);
			num_counter += save_print;
		}
	}
	print_buffer(&b_index, buffer);
	va_end(ap);
	return (num_counter);
}
/************PRINT_BUFFER************************/
/**
 *print_buffer-Prints character buffer up to a specified index.
 *
 * @b_index: Pointer to an integer representing index.
 * @buffer: the character buffer to be printed.
 */
void print_buffer(int *b_index, char buffer[])
{
	if (*b_index > 0)
	{
		write(1, buffer, *b_index * sizeof(char));
		*b_index = 0;
	}
}
