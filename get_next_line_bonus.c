/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/05 14:43:05 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	copy_buffer_in_line_bis(char **buffer, char *tmp, int offset, int choice)
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
		{
			return (1);
		}
		return (0);
	}
	if (choice == 2)
	{
		free(*buffer);
		*buffer = NULL;
		return (offset);
	}
	return (0);
}

int	copy_buffer_in_line(char *buffer, char **line)
{
	int		nl;
	int		offset;
	char	*tmp;

	nl = 0;
	if (*line == NULL)
		offset = len_nl_cpy(buffer, NULL, 1);
	else
		offset = len_nl_cpy(*line, NULL, 1) + \
				 len_nl_cpy(buffer, NULL, 1);
	tmp = (char *)malloc(sizeof(char) * (offset + 1));
	if (!tmp)
		return (-1);
	offset = 0;
	if (*line != NULL)
	{
		len_nl_cpy(tmp, *line, 3);
		while (tmp[offset] != '\0')
			offset++;
		free(*line);
	}
	if (copy_buffer_in_line_bis(&buffer, tmp, offset, 1) == 1)
		nl = 1;
	*line = tmp;
	return (nl);
}

int	buffer_handler(char **buffer, char **line, int fd, int eof)
{
	int	ret;

	while (1)
	{
		ft_strchr_memset(*buffer, 0, BUFFER_SIZE + 1, 2);
		ret = read(fd, *buffer, BUFFER_SIZE);
		if (ret == -1)
			return (copy_buffer_in_line_bis(buffer, NULL, -1, 2));
		if (ret == 0)
		{
			if (eof == 1)
			{
				copy_buffer_in_line(*buffer, line);
				return (copy_buffer_in_line_bis(buffer, NULL, 0, 2));
			}
			return (copy_buffer_in_line_bis(buffer, NULL, 0, 2));
		}
		if (copy_buffer_in_line(*buffer, line))
			break ;
		eof = 0;
	}
	*buffer = save_buffer(*buffer, ft_strchr_memset(*buffer, '\n', 0, 1) + 1);
	if (line)
		return (1);
	return (0);
}

t_fd_data	*fd_handler(t_fd_data **fd_data, int fd, int choice)
{
	t_fd_data	*curr;

	if (choice == 1)
	{
		if (*fd_data == NULL)
			return (new_elem(fd_data, fd, 1));
		curr = *fd_data;
		while (curr->fd != fd && curr->next != NULL)
			curr = curr->next;
		if (curr->fd != fd)
			return (new_elem(fd_data, fd, 1));
		else
			return (curr);
		return (NULL);
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static t_fd_data	*fd_data = NULL;
	t_fd_data			*curr;
	int					ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	curr = fd_handler(&fd_data, fd, 1);
	*line = NULL;
	if (curr->buffer != NULL)
	{
		if (copy_buffer_in_line(curr->buffer, line))
		{
			curr->buffer = save_buffer(curr->buffer, ft_strchr_memset(\
						curr->buffer, '\n', 0, 1) + 1);
			return (1);
		}
		free(curr->buffer);
	}
	curr->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!curr->buffer)
		return (-1);
	ret = buffer_handler(&curr->buffer, line, fd, 1);
	if (ret == -1 || ret == 0)
		new_elem(&fd_data, fd, 2);
	return (ret);
}
