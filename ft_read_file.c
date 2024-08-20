#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <stdio.h>
#include "h_header.h"

struct free_part
{
    int x1;
    int x2;
};

struct map_info
{
    int y;
    int x;
    char empty_char;
    char obstacle;
    char full;
};

char *extend_array(char *arr, int *size)
{
    int i;

    i = 0;
    *size *= 2;
    char *n_arr = malloc(*size);
    while (arr[i])
    {
        n_arr[i] = arr[i];
        i++;
    }
    free(arr);
    return n_arr;
}

int get_num_of_obstacles(char *line, char symbol)
{
    int i;
    
    i = 0;
    while (*line)
    {
        if (*line == symbol)
        {
            i ++;
        }
        line ++;
    }
    return i;
}

int parse_line(char *line, struct map_info map_info, struct free_part **result_save)
{
    struct free_part *parts;
    int x1;
    int i;
    int parts_i;
    struct free_part part;

    parts_i = 0;
    i = 0;
    x1 = 0;
    parts = malloc(sizeof(struct free_part) * (1 + get_num_of_obstacles(line, map_info.obstacle)));
    while (line[i])
    {
        if (line[i] == map_info.empty_char)
        {

        }
        else if (line[i] == map_info.obstacle)
        {
            struct free_part part = {x1, i};
            parts[parts_i] = part;
            parts_i ++;
            x1 = i;
        }
        else
        {
            write_error("map has wrong characters");
            return -1;
        }
         
        i++;
    }
    struct free_part fpart = {x1, i};
    parts[parts_i] = fpart;
    *result_save = parts;
    return 0;
}

int read_map_info(char *line, struct map_info *map_info)
//maybe this could be prettier
{
    int errors;
    
    errors = 0;
    if (!ft_char_is_printable(line[0]))
        errors ++;
    else if (!ft_char_is_printable(line[1]))
        errors ++;
    else if (!ft_char_is_printable(line[2]))
        errors ++;
    else if (!ft_char_is_printable(line[3]))
        errors ++;
    else if (line[4] != '\0')
        errors ++;
    if (errors > 0)
    {
        write_error("first line error");
        return -1;
    }
    (*map_info).y = line[0];
    (*map_info).empty_char = line[1];
    (*map_info).obstacle = line[2];
    (*map_info).full = line[3];
    return 0;
}

char *read_line(int file)
{
    char buff;
    int i;
    int size;

    size = 256;
    char *line = malloc(size);
    i = 0;
    while (1)
    {
        read(file, &buff, 1);
        if (buff == '\n' || !buff)
        {
            line[i] = '\0';
            break;
        }
        line[i] = buff;
        i ++;
        if (i > (sizeof(line) - 1))
        {
            line = extend_array(line, &size);
        }
    }
    return line;

}



int	ft_read_file(char *fname, struct free_part **result)
{
	int		f;
	char	*line;
    int iteration;
    struct map_info map_info;
    struct free_part **lines;

	f = open(fname, O_RDONLY);
	if (f == -1)
	{
		write_error("wrong file name");
		return (-1);
	}
	else
	{
        iteration = 0;
        line = read_line(f);
        if (read_map_info(line, &map_info))
            return -1;
        lines = malloc(map_info.y * sizeof(struct free_part));
		while (iteration < map_info.y)
        {
            line = read_line(f);
            if (iteration == 0)
                map_info.x = get_str_len(line);
			if (parse_line(line, map_info, &lines[iteration]))
                return -1;
            iteration ++;
        }
	}
	close(f);
    result = lines;
	return (0);
}



int main()
{
    // write error test
    // write_error("wrong output");
    // write_error("");

    struct free_part **lines;
    ft_read_file("map.txt", lines);

    write(1, "asd", 1);
}

