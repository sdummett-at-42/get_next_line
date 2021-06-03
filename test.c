/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:39:36 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/03 19:19:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*new_elem(t_fd_data **fd_data, int fd)
{
	t_fd_data *elem;

	elem = (t_fd_data *)malloc(sizeof(t_fd_data) * 1);
	elem->fd = fd;
	elem->buffer = NULL;
	elem->next = NULL;
	*fd_data = elem;
	return (elem->buffer);
}

char	*fd_handler(t_fd_data **fd_data, int fd)
{
	t_fd_data *curr;
	t_fd_data *elem;

	if (*fd_data == NULL)
	{
		printf("fd_data == NULL\n");
		return (new_elem(fd_data, fd));
	}
	else
	{
		printf("fd_data != NULL\n");
		curr = *fd_data;
		while (curr->fd != fd && curr->next != NULL)
			curr = curr->next;
		if (curr->fd != fd)
			return (new_elem(fd_data, fd));
		else
			return (curr->buffer);
	}
	return (NULL);
}

int main()
{
	static t_fd_data *fd_data = ;
	char *buffer;

	buffer = fd_handler(&fd_data, 1);

	return (0);
}
