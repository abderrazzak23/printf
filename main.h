#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct Format - Struct for format specifier and function pointer
 *
 * @frmt: The format specifier.
 * @f: The associated function.
 */
struct Format
{
	char frmt;
	int (*f)(va_list, char[], int, int, int, int);
};

typedef struct Format Format_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions for printing characters and strings */
int print_character(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_custom_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_symbol(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions for printing numbers */
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_num(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_num(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_num(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_num(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_uppercase(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

/* Function for printing non-printable characters */
int print_non_printable_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing memory addresses */
int print_pointer_address(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions for handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function for printing string in reverse */
int print_reversed_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing a string in ROT13 */
int print_rot13_encoded_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_char_printable(char);
int append_hexadecimal_code(char, char[], int);
int is_digit_char(char);

long int convert_signed_size_number(long int num, int size);
long int convert_unsigned_size_number(unsigned long int num, int size);

#endif /* PRINTF_H */

