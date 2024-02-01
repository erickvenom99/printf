#ifndef FUNCTION_MAIN_H
#define FUNCTION_MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 *struct dat - Struct op
 *
 * @ptr: The function associated.
 * @format: The format.
 */
struct dat
{
	char format;
	int (*ptr)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Struct op
*
*@dat: The format.
*@@data: The function associated.
*/
typedef struct dat data;

int _printf(const char *format, ...);
long int size_number(long int num, int size);
int _print(const char *frmt, int *i, va_list ap, char buffer[], int flags,
	   int width, int precision, int size);
int p_binary(va_list types, char buffer[],
		 int flags, int width, int precision, int size);
int format_specifier(const char *fmrt, int *index, va_list ap,
		      char buffer[], int flags, int width,
		      int precision, int size);
int unknown_specifier(const char *fmrt, int *index, char buffer[], int width);
int format_spec(const char *fmrt, int *index, va_list ap,
		char buffer[], int flags, int width,
		int precision, int size);
void p_buffer(int *b_index, char buffer[]);
int p_char(va_list arg, char buffer[], int flags,
	   int width, int precision, int size);
int p_string(va_list arg, char buffer[],
	     int flags, int width, int precision, int size);
int p_percent(va_list arg, char buffer[], int flags,
	      int width, int precision, int size);
int print_int(va_list arg, char buffer[], int flags,
	      int width, int precision, int size);

int print_unsigned(va_list ap, char buffer[],
		   int flags, int width, int precision, int size);
long int size_unsgnd(unsigned long int num, int n_size);
int print_octal(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int implement_char(char c, char buffer[], int flags,
		   int width, int precision, int size);
int write_numbers(int _negative, int index, char buffer[],
		  int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width,
	      int precision, int length, char padd, char extra_c);

int write_num_helper(int ind, char buffer[], int flags, int width, int prec,
		     int length, char padd, char extra_c);
int write_buffer(int start, char buffer[], int length);
int write_unsgnd(int is_negative, int ind,
		 char buffer[], int flags, int width, int precision, int size);
long int size_number(long int num, int n_size);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int is_digit(char c);
int print_d(va_list arg, char buffer[], int flags,
	    int width, int precision, int size);

#endif /* FUNCTION_MAIN_H */
