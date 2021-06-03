/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/03 12:09:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	copy_buffer_in_line_bis(char *buffer, char *tmp, int offset)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		tmp[offset] = buffer[i];
		offset++;
		i++;
	}
	tmp[offset] = '\0';
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

int	copy_buffer_in_line(char *buffer, char **line)
{
	int		nl;
	int		offset;
	char	*tmp;

	nl = 0;
	if (*line == NULL)
		offset = ft_strlen_nl_and_strcpy(buffer, NULL, 1);
	else
		offset = ft_strlen_nl_and_strcpy(*line, NULL, 1) + \
		ft_strlen_nl_and_strcpy(buffer, NULL, 1);
	tmp = (char *)malloc(sizeof(char) * (offset + 1));
	if (!tmp)
		return (-1);
	offset = 0;
	if (*line != NULL)
	{
		ft_strlen_nl_and_strcpy(tmp, *line, 3);
		while (tmp[offset] != '\0')
			offset++;
		free(*line);
	}
	if (copy_buffer_in_line_bis(buffer, tmp, offset) == 1)
		nl = 1;
	*line = tmp;
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	int			tmp_ret;
	int			eof;
	static char	*buffer = NULL;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (buffer != NULL)
	{
		if (copy_buffer_in_line(buffer, line))
		{
			buffer = save_buffer(buffer, ft_strchr_and_memset(buffer, '\n', \
						0, 1) + 1);
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
		ft_strchr_and_memset(buffer, 0, BUFFER_SIZE + 1, 2);
		tmp_ret = read(fd, buffer, BUFFER_SIZE);
		if (tmp_ret == -1)
		{
			free(buffer);
			buffer = NULL;
			return (-1);
		}
		if (tmp_ret == 0)
		{
			if (eof == 1)
			{
				copy_buffer_in_line(buffer, line);
				free(buffer);
				buffer = NULL;
				return (0);
			}
			free(buffer);
			buffer = NULL;
			return (tmp_ret);
		}
		if (copy_buffer_in_line(buffer, line))
			break ;
		eof = 0;
	}
	buffer = save_buffer(buffer, ft_strchr_and_memset(buffer, '\n', 0, 1) + 1);
	if (*line)
		return (1);
	else
		return (0);
}
