#include "main.h"

void print_to_buffer(char buffer[], int *buff_index);

/**
 * _printf - Custom printf function
 * @format: The format string.
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args_list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFFER_SIZE)
				print_to_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			print_to_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args_list);
			precision = get_precision(format, &i, args_list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args_list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_to_buffer(buffer, &buff_index);

	va_end(args_list);

	return (printed_chars);
}

/**
 * print_to_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buff_index: Index at which to add the next characte
 * represents the length.
 */
void print_to_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index =
