/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/05 13:22:21 by sdummett         ###   ########.fr       */
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
	if (copy_buffer_in_line_bis(&buffer, tmp, offset, 1) == 1)
	{
		nl = 1;
	}
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
		{
			return (copy_buffer_in_line_bis(buffer, NULL, -1, 2));
		}
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


t_fd_data	*fd_handler(t_fd_data **fd_data, int fd)
{
	t_fd_data *curr;

	if (*fd_data == NULL)
	{
		return (new_elem(fd_data, fd, 1));
	}
	else
	{
		curr = *fd_data;
		while (curr->fd != fd && curr->next != NULL)
			curr = curr->next;
		if (curr->fd != fd)
			return (new_elem(fd_data, fd, 1));
		else
			return (curr);
	}
	return (NULL);
}

t_fd_data	*new_elem(t_fd_data **fd_data, int fd, int choice)
{
	t_fd_data	*elem;
	t_fd_data	*previous;

	if (choice == 1)
	{
		elem = (t_fd_data *)malloc(sizeof(t_fd_data) * 1);
		elem->fd = fd;	
		elem->buffer = NULL;
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
	previous = NULL;
	elem = *fd_data;
	while (elem->fd != fd && elem->next != NULL)
	{
		previous = elem;
		elem = elem->next;
	}
	if (previous == NULL)
	{
		if (elem->next != NULL)
			*fd_data = elem->next;
		else
			*fd_data = NULL;
	}
	else
		previous->next = elem->next;
	free(elem);
	return (NULL);	
}

int	get_next_line(int fd, char **line)
{
	static t_fd_data	*fd_data = NULL;
	t_fd_data			*curr;
	int					ret;

	curr = fd_handler(&fd_data, fd);
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (curr->buffer != NULL)
	{
		if (copy_buffer_in_line(curr->buffer, line))
		{
			curr->buffer = save_buffer(curr->buffer, ft_strchr_memset(curr->buffer, \
						'\n', 0, 1) + 1);
			return (1);
		}
		free(curr->buffer);
	}
	curr->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!curr->buffer)
		return (-1);
	ret = buffer_handler(&curr->buffer, line, fd, 1);
	if (ret == -1 || ret == 0)
	{
		new_elem(&fd_data, fd, 2);
	}
	return (ret);
}

void print_gnl_result(int fd, char **line)
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
	int fd2;
	char *line;

	fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	fd2 = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//return 0;
	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);

	//fd = open("file6", O_RDONLY);
	print_gnl_result(fd, &line);
	//fd = open("file7", O_RDONLY);
	print_gnl_result(fd2, &line);
	return 0;
}
