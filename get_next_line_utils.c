/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/24 18:22:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	buffer_is_nl_eof(char *buffer, int *line_len)
{
	int i;

	i = 0;
	while (buffer[i] != -1)
	{
		if (buffer[i] == '\n')
		{
			printf("len of line(nl) = %d\n", i);
			*line_len = i;
			return (1);
		}
		else if (buffer[i] == '\0')
		{
			printf("len of line(eof) = %d\n", i);
			*line_len = i;
			return (0);
		}
		i++;
	}
	return (-1);
}

int buffer_len(char *buffer)
{
	int len;

	len = 0;
	while (buffer[len] != -1)
		len++;
	return (len);
}

void buffer_copy(char **line, char *buffer, int line_len)
{
	char *line_temp;
	char *new_line;
	int len;
	int i;


	if (*line == 0)
	{
		line_temp = malloc(sizeof(char) * line_len);
		i = 0;
		while (i < line_len)
		{
			line_temp[i] = buffer[i];
			i++;
		}
		line_temp[line_len] = 0;
		*line = line_temp;
	}
	else
	{
		len = 0;
		line_temp = *line;
		while (line_temp[len])
			len++;
		printf("line_len + len = %d\n", line_len + len);
		new_line = malloc(sizeof(char) * line_len + len);
		i = 0;
		while (line_temp[i] < len)
		{
			new_line[i] = line_temp[i];
			i++;
		}
		len = 0;
		while (len < line_len)
		{
			new_line[i] = buffer[len];
			i++;
			len++;
		}
		new_line[i] = 0;
		*line = new_line;
		free(line_temp);
	}
	//printf("line_len = %d, i = %d\n", line_len, i);
	//printf("line_temp = >%s<\n", line_temp);
}

int wipe_buffer(char *buffer, char **line, char *readen_bytes)
{
	int line_len = 0;
	int buffer_leng = buffer_len(buffer);
	int ret_nl_eof = buffer_is_nl_eof(buffer, &line_len);
	printf("ret_nl_eof = %d | line_len = %d\n", ret_nl_eof, line_len);
	if (ret_nl_eof != -1)
	{
		printf("*line = >%s<\n", *line);
		buffer_copy(line, buffer, line_len);	
		printf("after buffer_copy line = >%s<\n", *line);
	}
	return (ret_nl_eof);
}

//////////////

void print_bytes(char *buffer)
{
	/*int len;

	  len = 0;
	  while (str[len] != -1)
	  len++;*/
	printf("bufferlen = %d\n", buffer_len(buffer));
	write(1, buffer, buffer_len(buffer));
}

///////////

int read_on_fdesc(int fd, char *buffer)
{
	int ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
	{
		write(1, "Something wrong happened during the read.\n", 42);
		return (-1);
	}
	buffer[ret] = -1;
	return (0);
}
