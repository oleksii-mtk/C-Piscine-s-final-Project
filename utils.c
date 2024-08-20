#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <stdio.h>
#include "h_header.h"


int get_str_len(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return i;
}


void write_error(char *error_msg)
{
    write(2, "map error", 9);
    if (error_msg)
    {
        write(2, ":  ", 2);
        write(2, error_msg, get_str_len(error_msg));
    }
    write(2, "\n", 1);
}


int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(47 < *str && *str < 58))
		{
			return (0);
		}
		str++;
	}
	return (1);
}



int	ft_char_is_printable(char c)
{

    if (c < 32 || c > 127)
    {
        return (0);
    }
	return (1);
}
