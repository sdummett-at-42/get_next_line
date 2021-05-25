/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/25 18:42:26 by sdummett         ###   ########.fr       */
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
			perst_buf_copy(&perst_buf, line, line_len, 1);
			return (ret_type);
		}
		else
		{	
			perst_buf_copy(&perst_buf, line, perstbuf_len, 0);
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!buffer)
				return (-1);
			while (retwipebuffer == -1)
			{
				if (read_on_fdesc(fd, buffer) == -1)
					return (-1);
				retwipebuffer = wipe_buffer(buffer, line, &perst_buf);
			}
			free(buffer);
			return (retwipebuffer);
		}
	}
	return (-255);
}

int main()
{
	int fd = open("loremipsum", O_RDONLY);
	char *line;
	int gnl_ret;

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);
	return (0);
}
