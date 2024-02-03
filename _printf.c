#include "main.h"
/**
 * _printf - similar to printf
 * @format: constant format
 * Return: length of format
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int k = 0,  total_count = 0;

	va_start(ap, format);
	while (format[k] != '\0')
	{
		if (format[k] == '%')
		{
			++k;
			switch (format[k])
			{
			case 's':
				p_string(va_arg(ap, char *), &total_count);
				break;
			case 'c':
				p_char(va_arg(ap, int), &total_count);
				break;
			case '%':
				putchar('%');
				total_count++;
				break;
			case 'i':
			case 'd':
				p_num(va_arg(ap, int), &total_count);
				break;
			default:
				putchar(format[k]);
				total_count++;
				break;
			}
		}
		else
		{
			putchar(format[k]);
			total_count++;
		}
		k++;
	}
	va_end(ap);
	return (total_count);
}
