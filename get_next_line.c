/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/25 16:52:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_buffer *perst_buf = 0;
	char *buffer;
	int retwipebuffer;
	int ret;

	// INIT *line a NULL;
	*line = 0;
	ret = -1;
	retwipebuffer = -1;

	if (perst_buf == 0)
	{
		//// A mettre dans une fonction ? ////
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		while (retwipebuffer == -1)
		{
			if (read_on_fdesc(fd, buffer) == -1)
				return (-1);
			retwipebuffer = wipe_buffer(buffer, line, &perst_buf);
			if (perst_buf == 0)
				printf("t_buffer *perst_buf EST NULL\n");
			else
				printf("t_buffer *perst_buf n'est pas NULL\n");
		}
		free(buffer);
		//// A mettre dans une fonction ? ////
		return (retwipebuffer);
	}
	else
	{
		int perstbuf_len = 0;
		while (perst_buf->persist_buffer[perstbuf_len])
			perstbuf_len++;
		int line_len = -1;
		int buffer_len = 0;
		int ret_type = buffer_is_nl_eof(perst_buf->persist_buffer, &line_len);
		if (ret_type != -1)
		{
			printf("Cut the line, and put it in *line && reajust *perst_buf.\n");
			printf("Return the right value.\n");
			perst_buf_copy(&perst_buf, line, line_len, 1);
			return (ret_type);
		}
		else
		{	
			printf("Put the readen bytes in *line && set *perst_buf at NULL.\n");
			perst_buf_copy(&perst_buf, line, perstbuf_len, 0);
			printf("LIIIIINE = >%s<\n", *line);
			if (perst_buf)
				printf("perst_buf not NULL\n");
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!buffer)
				return (-1);
			while (retwipebuffer == -1)
			{
				if (read_on_fdesc(fd, buffer) == -1)
					return (-1);
				retwipebuffer = wipe_buffer(buffer, line, &perst_buf);
				if (perst_buf == 0)
					printf("t_buffer *perst_buf EST NULL\n");
				else
					printf("t_buffer *perst_buf n'est pas NULL\n");
			}
			free(buffer);
			return (retwipebuffer);
		}
	}
	return (-255);
}

int main()
{
	int fd = open("file", O_RDONLY);
	printf("===\tfd = %d\t===\n", fd);

	char *line;
	int gnl_ret;
	gnl_ret = get_next_line(fd, &line);
	printf("~~~ gnl_ret = %d ~~~\n", gnl_ret);
	printf("line = >%s<\n", line);
	printf("====================================\n");
	printf("====================================\n");
	gnl_ret = get_next_line(fd, &line);
	printf("~~~ gnl_ret = %d ~~~\n", gnl_ret);
	printf("line = >%s<\n", line);
	return (0);
}
