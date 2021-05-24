/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/24 19:43:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_buffer *perst_buf = 0;
	char *buffer;
	int retwipebuffer;
	int ret;

	*line = 0;
	ret = -1;
	if (perst_buf == 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		if (read_on_fdesc(fd, buffer) == -1)
			return (-1);
		retwipebuffer = wipe_buffer(buffer, line, &perst_buf);
		print_buffer(buffer);
		return (retwipebuffer);
	}
	else
	{
		//BELOW IS UNDER DEVELOPMENT
		return (-255);
		int line_len = 0;
		if (buffer_is_nl_eof(perst_buf->persist_buffer, &line_len))
		{
			printf("Cut the line, and put it in *line_found && reajust *readen_bytes.\n");
			printf("Return the right value.\n");
			return (-255);
		}
		else
		{
			printf("Put the readen bytes in *line_found && set *readen at NULL.\n");
			read_on_fdesc(fd, buffer);
		}
	}
	return (-255);
}

int main()
{
	int fd = open("file", O_RDONLY);
	printf("===\tfd = %d\t===\n", fd);

	char *line;
	int gnl_ret = get_next_line(fd, &line);
	printf("~~~ gnl_ret = %d ~~~\n", gnl_ret);
	printf("line = >%s<", line);

	return (0);
}
