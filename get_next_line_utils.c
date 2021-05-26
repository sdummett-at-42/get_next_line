/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/26 12:49:09 by sdummett         ###   ########.fr       */
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
			*line_len = i;
			return (1);
		}
		else if (buffer[i] == '\0')
		{
			*line_len = i;
			printf("RETURN 0\n");
			return (0);
		}
		i++;
	}
	// return 1 = LINE / 0 = EOF / -1 NO LINE FOUND
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

void perst_buf_copy(t_buffer *perst_buf, char **line, int line_len, int signal)
{
	int i;	
	t_buffer tmp;
	char *new_line;
	char *line_temp;
	int len;

	i = 0;
	//tmp = *perst_buf;	
	tmp = *perst_buf;
	line_temp = *line;
	if (!signal)
	{
		line_len = 0;
		while (tmp.persist_buffer[line_len] != -1)
			line_len++;
		line_temp = malloc(sizeof(char) * line_len + 1);
		while (i < line_len)
		{
			line_temp[i] = tmp.persist_buffer[i];
			i++;
		}
		line_temp[i] = 0;
		*line = line_temp;
		free(tmp.persist_buffer);
		//free(*perst_buf);
		//*perst_buf = 0;
	}
	else
	{
		new_line = malloc(sizeof(char) * line_len + 1);
		while (i < line_len)
		{
			new_line[i] = tmp.persist_buffer[i];
			i++;
		}
		new_line[i] = 0;
		*line = new_line;
		i = 0;
		while (tmp.persist_buffer[i + line_len] != -1)
		{
			i++;
		}
		new_line = malloc(sizeof(char) * i + 1);
		i = 0;
		while (tmp.persist_buffer[line_len + 1] != -1)
		{
			new_line[i] = tmp.persist_buffer[line_len + 1];
			i++;
			line_len++;
		}
		new_line[i] = -1;
		//print_buffer(new_line);
		free(tmp.persist_buffer);
		tmp.persist_buffer = new_line;
	}
}

/// CREER UNE FONCTION SPECIFIQUE POUR *line

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
		{
			len++;
		}
		if (len || line_len)
		{
			new_line = malloc(sizeof(char) * line_len + len + 1);
			i = 0;
			while (i < len)
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
		else
			*line = 0;
	}
}

int wipe_buffer(char *buffer, char **line, t_buffer *perst_buf)
{
	int i;
	int line_len = 0;
	int buffer_leng = buffer_len(buffer);
	int ret_nl_eof = buffer_is_nl_eof(buffer, &line_len);
	t_buffer tmp;

	tmp = *perst_buf;
	if (tmp.persist_buffer)
		print_buffer(tmp.persist_buffer);
	if (ret_nl_eof != -1)
	{
		buffer_copy(line, buffer, line_len);
		i = 0;
		while (buffer[i + line_len + 1] != -1)
			i++;
		if (i)
		{
			if (!tmp.persist_buffer)
			{
				tmp.persist_buffer = malloc(sizeof(t_buffer) * 1);
				if (!tmp.persist_buffer)
					return (-1);
			}
			tmp.persist_buffer = malloc(sizeof(char) * i + 1);
			i = 0;
			while (buffer[i + line_len + 1] != -1)
			{
				tmp.persist_buffer[i] = buffer[i + line_len + 1];
				i++;
			}
			tmp.persist_buffer[i] = -1;
			*perst_buf = tmp;
		}
	}
	else
	{
		buffer_copy(line, buffer, buffer_leng);
	}

	return (ret_nl_eof);

}

int read_on_fdesc(int fd, char *buffer)
{
	int ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
	{
		write(1, "Something wrong happened during the read.\n", 42);
		return (-1);
	}
	buffer[ret ] = -1;
	/// test
	int i = 0;
	while (buffer[i] != -1)
	{
		printf("[%d]", buffer[i]);
		i++;
	}
	printf("ret = %d | i = %d\n", ret, i);
	printf("\n");
	/// test
	return (0);
}

//////////////

void print_buffer(char *buffer)
{
	write(1, buffer, buffer_len(buffer));
}

///////////
