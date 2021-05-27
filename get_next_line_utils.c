/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/27 20:10:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void ft_memset(void *buffer, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		*((unsigned char *)buffer + i) = 0;
		i++;
	}
}

int buffer_len(char *buffer)
{
	int len;

	len = 0;
	while (buffer[len])
		len++;
	return (len);
}

int copy_buffer_in_line(char *buffer, char **line)
{
	int i;
	int j;
	char *line_tmp;
	char *new_line;

	i = 0;
	line_tmp = *line;
	if (line_tmp)
	{
		while (line_tmp[i] != '\0')
			i++;
		new_line = malloc(sizeof(char) * i + buffer_len(buffer) + 1);
		if (!new_line)
			return (-1);
		i = 0;
		while (line_tmp[i] != '\0')
		{
			new_line[i] = line_tmp[i];
			i++;
		}
	}
	else
	{
		new_line = malloc(sizeof(char) * buffer_len(buffer) + 1);
		if (!new_line)
			return (-1);
		ft_memset(new_line, buffer_len(buffer) + 1);
	}

	j = 0;
	while (buffer[j] != '\0' && buffer[j] != '\n')
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	new_line[i] = 0;
	*line = new_line;
	if (buffer[j] == '\n')
		return (1);
	return (0);
}

int check_buffer(char *buffer, char **new_buffer)
{
	int i;
	int buf_len;
	char *tmp;
	buf_len = buffer_len(buffer);

	tmp = *new_buffer;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (i + 1 == buf_len)
				return (0);
			else
			{
				tmp = malloc(sizeof(char) * buf_len - i + 1);
				if (!tmp)
					return (-1);
				buf_len = 0;
				i++;
				while (buffer[i])
				{
					tmp[buf_len] = buffer[i];
					buffer[i] = 0;
					buf_len++;
					i++;
				}
				tmp[buf_len] = 0;
				*new_buffer = tmp;
				return (1);
			}
		}
		i++;
	}
	return (-1);
}

int empty_string(char **line)
{
	char *new_line;

	new_line = malloc(sizeof(char) * 1);
	if (!new_line)
		return (-1);
	new_line[0] = '\0';
	*line = new_line;
	return (0);
}
