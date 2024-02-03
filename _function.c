#include "main.h"

/**
 * p_char - Prints a character.
 * @ch: The character to print.
 * @count: Pointer to the count of printed characters.
 * Return: void.
 */
void p_char(char ch, int *count)
{
	putchar(ch);
	(*count)++;
}

/**
 * p_string - Prints a string.
 * @string: Pointer to the string to print.
 * @total_count: Pointer to the total count of printed characters.
 * Return: void.
 */
void p_string(const char *string, int *total_count)
{
	if (string == NULL)
		string = "(null)";
	while (*string)
	{
		putchar(*string);
		(*total_count)++;
		string++;
	}
}

/**
 * p_num - Prints a number.
 * @num: The number to print.
 * @count: Pointer to the count of printed characters.
 * Return: void.
 */
void p_num(int num, int *count)
{
	int num_digits = 1;
	int temp = num;
	int i;
	int d_num = 1;

	if (num < 0)
	{
		putchar('-');
		(*count)++;
		num = -num;
	}

	while (temp /= 10)
		num_digits++;

	for (i = 1; i < num_digits; i++)
		d_num *= 10;

	while (d_num > 0)
	{
		int digit = num / d_num;

		putchar(digit + '0');
		(*count)++;
		num %= d_num;
		d_num /= 10;
	}
}
