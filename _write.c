#include "main.h"
/**
 * write_numbers - Prints a number
 * @_negative: Flag indicating if the number is negative
 * @index: Starting index in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int write_numbers(int _negative, int index, char buffer[],
		  int flags, int width, int precision, int size)
{
	int len = BUFFER_SIZE - index - 1;
	char pad = ' ', xtra_char = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (_negative)
		xtra_char = '-';
	else if (flags & F_PLUS)
		xtra_char = '+';
	else if (flags & F_SPACE)
		xtra_char = ' ';
	return (write_num(index, buffer, flags, width, precision,
			  len, pad, xtra_char));
}
#include "main.h"
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int index,
		 char buffer[],
		 int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padding = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding;
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) +
				write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) +
				write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}

#include "main.h"
/**
 * write_num - Writes to output
 *
 * @index: The starting index in the buffer.
 * @buffer: The buffer to write the number to.
 * @flags: The formatting flags.
 * @width: The minimum width of the output.
 * @precision: The precision (number of digits after the decimal point).
 * @length: The length of the number to be written.
 * @padding: The padding character.
 * @extra_c: An extra character to be added to the output.
 *
 * Return:  number of characters.
 */
int write_num(int index, char buffer[], int flags, int width, int precision,
	      int length, char padding, char extra_c)
{
	if (precision == 0 && index == BUFFER_SIZE - 2 &&
	    buffer[index] == '0' && width == 0)
		return (0);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding = ' ';

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
		buffer[--index] = '0', length++;

	if (extra_c != 0)
		length++;

	if (width > length)
	{
		return (write_num_helper(index, buffer, flags, width, precision,
					 length, padding, extra_c));
	}

	if (extra_c)
		buffer[--index] = extra_c;

	return (write(1, &buffer[index], length));
}

#include "main.h"
/**
 * write_num_helper - writing with  formatting
 *
 * @index: The starting index in the buffer.
 * @buffer:The buffer to write the number to.
 * @flags:The formatting flags.
 * @width:The minimum width of the output.
 * @precision:The precision (number of digits after the decimal point).
 * @length: The length of the number to be written.
 * @padding: The padding character.
 * @extra_c: An extra character to be added to the output.
 *
 * Return: The number of characters written to the output.
 */
int write_num_helper(int index, char buffer[], int flags, int width,
		     int precision, int length,
		     char padding, char extra_c)
{
	int i;
	int padd_start = 1;

	UNUSED(precision);

	for (i = 1; i < width - length + 1; i++)
		buffer[i] = padding;

	buffer[i] = '\0';

	if (flags & F_MINUS && padding == ' ')
	{
		if (extra_c)
			buffer[--index] = extra_c;

		return (write(1, &buffer[index], length) +
			write(1, &buffer[1], i - 1));
	}
	else if (!(flags & F_MINUS) && padding == ' ')
	{
		if (extra_c)
			buffer[--index] = extra_c;

		return (write(1, &buffer[1], i - 1) +
			write(1, &buffer[index], length));
	}
	else if (!(flags & F_MINUS) && padding == '0')
	{
		if (extra_c)
			buffer[--padd_start] = extra_c;

		return (write(1, &buffer[padd_start], i - padd_start) +
			write(1, &buffer[index], length - (1 - padd_start)));
	}
	return (0);
}
