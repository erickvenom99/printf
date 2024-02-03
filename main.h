#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
void p_string(const char *strings, int *total_count);
void p_char(char ch, int *count);
void p_num(int num, int *count);
#endif
