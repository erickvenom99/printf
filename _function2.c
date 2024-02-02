#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @ap: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list ap, char buffer[],
		   int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*************BINARY ****************/
#include "main.h"
/**
 * p_binary - Prints an unsigned number
 * @ap: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int p_binary(va_list ap, char buffer[],
		 int flags, int width, int precision, int size)
{
	unsigned int num, mod, i, sum;
	unsigned int a[32];
	int count;
	char x;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(ap, unsigned int);
	mod = 2147483648;
	a[0] = num / mod;
	for (i = 1; i < 32; i++)
	{
		mod /= 2;
		a[i] = (num / mod) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			x = '0' + a[i];

			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
