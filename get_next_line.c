/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/30 12:58:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*persistant_buffer = NULL;
	static int	last_ret = 0;
	int			error;
	int			is_nl;
	int			read_ret;
	int			is_eof;
	char		*buffer;

	*line = NULL;
	is_nl = 0;
	is_eof = 0;
	if (persistant_buffer != NULL)
	{
		is_nl = copy_buffer_in_line(persistant_buffer, line);
		error = check_buffer(persistant_buffer, &persistant_buffer);
		if (error == 0)
		{
			free(persistant_buffer);
			persistant_buffer = NULL;
		}
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	read_ret = -1;
	while (is_nl == 0)
	{
		ft_memset(buffer, BUFFER_SIZE + 1);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 0)
			return (-1);
		error = check_buffer(buffer, &persistant_buffer);
		is_nl = copy_buffer_in_line(buffer, line);
		if (read_ret == 0)
		{
			if (is_eof != 1)
			{
				if (last_ret == 1)
				{
					free(buffer);
					last_ret = 0;
					return (empty_string(line));
				}
				printf("NULL\n");
				*line = NULL;
			}
			break ;
		}
		is_eof = 1;
	}
	last_ret = is_nl;
	free(buffer);
	return (is_nl); // return ?
}

/*
void print_gnl_result(char **line, int fd)
{
	int gnl_ret;

	printf(MAGENTA "====================================\n");
	printf(		   "==========   APPEL DE GNL  =========\n");
	printf(        "====================================\n" RESET);
	gnl_ret = get_next_line(fd, line);
	printf("%d", gnl_ret);
	printf(GREEN   "||%s||\n"                   RESET , *line);
	free(*line);
}

int main()
{
	int i;
	int fd;
	int ret_read;
	char *line;
	char *buffer;

	fd = open("lorem2", O_RDONLY);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	//return 0;
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
	print_gnl_result(&line, fd);
}
*/
