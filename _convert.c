#include "main.h"
/**
 * size_number - Casts a number to the specified size
 * @num: number to be casted.
 * @n_size: number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int size_number(long int num, int n_size)
{
	if (n_size == S_LONG)
	{
		return (num);
	}
	else if (n_size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}
#include "main.h"
/**
 * size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @n_size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int size_unsgnd(unsigned long int num, int n_size)
{
	if (n_size == S_LONG)
	{
		return (num);
	}
	else if (n_size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
