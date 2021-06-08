/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/08 15:07:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	cpy_buf_in_l_or_free(char **buffer, char *tmp, int offset, int choice)
{
	int	i;

	if (choice == 1)
	{
		i = 0;
		while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		{
			tmp[offset] = (*buffer)[i];
			offset++;
			i++;
		}
		tmp[offset] = '\0';
		if ((*buffer)[i] == '\n')
			return (1);
		return (0);
	}
	free(*buffer);
	*buffer = NULL;
	return (offset);
}

int	copy_buffer_in_line(char *buffer, char **line, int *eof, int value)
{
	int		offset;
	char	*tmp;

	*eof = value;
	value = value - value;
	if (*line == NULL)
		offset = ft_strlen_nl_or_strcpy(buffer, NULL, 1);
	else
		offset = ft_strlen_nl_or_strcpy(*line, NULL, 1) + \
				 ft_strlen_nl_or_strcpy(buffer, NULL, 1);
	tmp = (char *)malloc(sizeof(char) * (offset + 1));
	if (!tmp)
		return (-1);
	offset = 0;
	if (*line != NULL)
	{
		ft_strlen_nl_or_strcpy(tmp, *line, 3);
		while (tmp[offset] != '\0')
			offset++;
		free(*line);
	}
	if (cpy_buf_in_l_or_free(&buffer, tmp, offset, 1) == 1)
		value = 1;
	*line = tmp;
	return (value);
}

t_fd_data	*new_elem(t_fd_data **fd_data, int fd)
{
	t_fd_data	*elem;

	elem = (t_fd_data *)malloc(sizeof(t_fd_data) * 1);
	if (elem == NULL)
	{
		while (*fd_data)
		{
			elem = *fd_data;
			free(elem->buf);
			free(elem);
			*fd_data = (*fd_data)->next;
		}
		return (NULL);
	}
	elem->fd = fd;
	elem->buf = NULL;
	elem->next = NULL;
	if (*fd_data == NULL)
		*fd_data = elem;
	else
	{
		elem->next = *fd_data;
		*fd_data = elem;
	}
	return (elem);
}

void	buffer_handler(char **buffer, char **line, int *fd, int eof)
{
	int	ret;

	while (1)
	{
		schr_or_mset(*buffer, 0, BUFFER_SIZE + 1, 2);
		ret = read(*fd, *buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			*fd = cpy_buf_in_l_or_free(buffer, NULL, -1, 2);
			return ;
		}
		if (ret == 0)
		{
			if (eof == 1)
				copy_buffer_in_line(*buffer, line, &eof, 1);
			*fd = cpy_buf_in_l_or_free(buffer, NULL, 0, 2);
			return ;
		}
		if (copy_buffer_in_line(*buffer, line, &eof, 0))
			break ;
	}
	*buffer = s_buf(*buffer, schr_or_mset(*buffer, '\n', 0, 1) + 1);
	*fd = 0;
	if (line)
		*fd = 1;
}

int	get_next_line(int fd, char **line)
{
	static t_fd_data	*fd_data = NULL;
	t_fd_data			*cur;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	cur = fd_handler(&fd_data, fd);
	if (cur == NULL)
		return (-1);
	*line = NULL;
	if (cur->buf != NULL)
	{
		if (copy_buffer_in_line(cur->buf, line, &fd, fd))
		{
			cur->buf = s_buf(cur->buf, schr_or_mset(cur->buf, '\n', 0, 1) + 1);
			return (1);
		}
		free(cur->buf);
	}
	cur->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (cur->buf == NULL)
		return (-1);
	buffer_handler(&cur->buf, line, &fd, 1);
	if (fd == -1 || fd == 0)
		free_elem_and_relink(&fd_data, cur->fd);
	return (fd);
}
