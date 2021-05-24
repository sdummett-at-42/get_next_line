/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/24 16:53:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_buffer readen_bytes;
	readen_bytes.smthg_in_buffer = 0;
	//static char *readen_bytes = 0; //use struct in order to use one static
	//char *line_found = 0;
	char *buffer;
	int retwipebuffer;
	int ret;

	ret = -1;
	if (readen_bytes.persist_buffer == 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		if (read_on_fdesc(fd, buffer) == -1)
			return (-1);
		retwipebuffer = wipe_buffer(buffer, line, readen_bytes.persist_buffer);
		print_bytes(buffer);
		return (retwipebuffer);
	}
	else
	{
		//BELOW IS UNDER DEVELOPMENT
		return (-255);
		int line_len = 0;
		if (buffer_is_nl_eof(readen_bytes.persist_buffer, &line_len))
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
