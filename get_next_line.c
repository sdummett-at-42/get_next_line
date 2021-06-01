/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/01 04:16:51 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	copy_buffer_in_line(char *buffer, char **line)
{
	int		i;
	int		nl;
	int		offset;
	char	*tmp;

	nl = 0;
	if (*line == NULL)
		offset = ft_strlen_nl(buffer, 1);
	else
		offset = ft_strlen_nl(*line, 1) + ft_strlen_nl(buffer, 1);
	tmp = (char *)malloc(sizeof(char) * (offset + 1));
	if (!tmp)
		return (-1);
	offset = 0;
	if (*line != NULL)
	{
		ft_strcpy(tmp, *line);
		while (tmp[offset] != '\0')
			offset++;
		free(*line);
	}
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		tmp[offset] = buffer[i];
		offset++;
		i++;
	}
	tmp[offset] = '\0';
	if (buffer[i] == '\n')
		nl = 1;
	*line = tmp;
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	int			tmp_ret;
	int			eof;
	static char	*buffer = NULL;

	*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (buffer != NULL)
	{
		if (copy_buffer_in_line(buffer, line))
		{
			buffer = save_buffer(buffer, ft_strchr(buffer, '\n') + 1);
			return (1);
		}
		free(buffer);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	eof = 1;
	while (1)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		tmp_ret = read(fd, buffer, BUFFER_SIZE);
		if (tmp_ret == -1)
		{
			free(buffer);
			buffer = NULL;
			return (-1);
		}
		if (tmp_ret == 0)
		{
			//if (*line == NULL && eof != 1)
			//{
			//	tmp_ret = 0;
			//}
		//	else
		//	{

				if (eof == 1)
				{
				copy_buffer_in_line(buffer, line);
					free(buffer);
					buffer = NULL;
					return (0);
				}
				//copy_buffer_in_line(buffer, line);
				//tmp_ret = 1;
				//	tmp_ret = 0;
		//	}
			free(buffer);
			buffer = NULL;
			return (tmp_ret);
		}
		if (copy_buffer_in_line(buffer, line))
			break ;
		eof = 0;
	}
	buffer = save_buffer(buffer, ft_strchr(buffer, '\n') + 1);
	if (*line)
		return (1);
	else
		return (0);
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
	int fd;
	int ret;
	char *line;

	fd = open("file5", O_RDONLY);
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
	return 0;
}
*/
