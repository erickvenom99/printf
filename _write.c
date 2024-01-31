#include "function_main.h"
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
#include "function_main.h"
/**
 * write_num - Writes a number using a buffer
 * @index: Index at which the number starts in the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @length: Number length
 * @padding: Padding character
 * @extra_c: Extra character
 * Return: Number of printed characters
 */
int write_num(int index, char buffer[], int flags, int width,
	      int precision, int length, char padding, char extra_c)
{
	if (should_skip_zero_number(index, buffer, width, precision, length))
		return (0);

	adjust_buffer_for_zero_precision(index, buffer,
					 width, precision, length, padding);

	if (extra_c != 0)
		length++;

	if (width > length)
	{
		if (flags & F_MINUS && padding == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write_buffer(index, buffer, length) +
				write_buffer(1, buffer, width - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write_buffer(1, buffer, width - 1) +
				write_buffer(index, buffer, length));
		}
	}

	if (extra_c)
		buffer[--index] = extra_c;

	return (write_buffer(index, buffer, length));
}

#include "function_main.h"
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
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
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
