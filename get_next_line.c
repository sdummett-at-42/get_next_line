/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/26 12:49:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	//static t_buffer *perst_buf = 0;
	static t_buffer perst_buf;
	char *buffer;
	int is_nl_or_eof;
	int ret;

	perst_buf.persist_buffer = 0;
	// INIT *line a NULL;
	*line = 0;
	ret = -1;
	is_nl_or_eof = -1;

	if (perst_buf.persist_buffer == 0)
	{
		//// A mettre dans une fonction ? ////
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		while (is_nl_or_eof == -1)
		{
			if (read_on_fdesc(fd, buffer) == -1)
				return (-1);
			is_nl_or_eof = wipe_buffer(buffer, line, &perst_buf);
			if (*line == 0)
				return (-1);
		}
		free(buffer);
		//// A mettre dans une fonction ? ////
		printf("1 - is_nl_or_eof == %d\n", is_nl_or_eof);
		return (is_nl_or_eof);
	}
	else
	{
		// test
		/*
		int i = 0;
		char *tmp = perst_buf->persist_buffer;
		while (tmp[i] != -1)
		{
			printf("[%d]", tmp[i]);
			i++;
		}
		printf("\n");
		*/
		//test
		int perstbuf_len = 0;
		while (perst_buf.persist_buffer[perstbuf_len])
			perstbuf_len++;
		int line_len = -1;
		int buffer_len = 0;
		is_nl_or_eof = buffer_is_nl_eof(perst_buf.persist_buffer, &line_len);
		if (is_nl_or_eof != -1)
		{
			perst_buf_copy(&perst_buf, line, line_len, 1);
			printf("2 - is_nl_or_eof == %d\n", is_nl_or_eof);
			return (is_nl_or_eof);
		}
		else
		{
			perst_buf_copy(&perst_buf, line, perstbuf_len, 0);
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!buffer)
				return (-1);
			while (is_nl_or_eof == -1)
			{
				if (read_on_fdesc(fd, buffer) == -1)
					return (-1);
				is_nl_or_eof = wipe_buffer(buffer, line, &perst_buf);
			}
			free(buffer);
			printf("3 - is_nl_or_eof == %d\n", is_nl_or_eof);
			return (is_nl_or_eof);
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
//return 0;
	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	
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
//return 0;
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
//return 0;		
	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);
return 0;	
	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, &line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , line);
	free(line);
	return (0);
}
