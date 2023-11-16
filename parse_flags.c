#include "main.h"

/**
 * get_flags - Calculate active flags
 * @format: Formatted string to analyze
 * @index: Index value
 * Return: Calculated flags
 */
int get_flags(const char *format, int *index)
{
    int j, current_index;
    int flags = 0;
    const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
    {
        for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
        {
            if (format[current_index] == FLAGS_CHARS[j])
            {
                flags |= FLAGS_ARRAY[j];
                break;
            }
        }

        if (FLAGS_CHARS[j] == 0)
        {
            break;
        }
    }

    *index = current_index - 1;

    return (flags);
}

