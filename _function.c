#include "main.h"
/**
 * p_char - Prints character
 * @arg: argument in list
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int p_char(va_list arg, char buffer[],
	   int flags, int width, int precision, int size)
{
	char c = va_arg(arg, int);

	return (implement_char(c, buffer, flags, width, precision, size));
}
#include "main.h"
/**
 * p_string - Prints a string
 * @ap: List of arguments
 * @buffer: Buffer array to handle print (not used in this function)
 * @flags: Calculates active flags (not used in this function)
 * @width: Width specification (not used in this function)
 * @precision: Precision specification (not used in this function)
 * @size: Size specifier (not used in this function)
 * Return: Number of characters printed
 */
int p_string(va_list ap, char buffer[], int flags,
	     int width, int precision, int size)
{
	int j, len = 0;
	char *str;

	str = va_arg(ap, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 5)
			str = "     ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= len && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (j = width - len; j > 0; j--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, &str[0], len));
}
/****** PRINT*******/
#include "main.h"
/**
 * p_percent - Prints a percent sign
 * @arg: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int p_percent(va_list arg, char buffer[],
	 int flags, int width, int precision, int size)
{
	UNUSED(arg);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/****** PRINT INT *************************/
#include "main.h"
/**
 *print_int - Print integer
 * @arg: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list arg, char buffer[], int flags,
	  int width, int precision, int size)
{
	int negative_no = 0;
	int k = BUFFER_SIZE - 2;
	unsigned long int numero;
	long int num = va_arg(arg, long int);

	num = size_number(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	numero = (unsigned long int)num;

	if (num < 0)
	{
		numero = (unsigned long int)((-1) * num);
		negative_no = 1;
	}

	while (numero > 0)
	{
		buffer[k--] = (numero % 10) + '0';
		numero /= 10;
	}

	k++;

	return (write_numbers(negative_no, k, buffer,
			  flags, width, precision, size));
}
