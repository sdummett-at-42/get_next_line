/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/05 14:43:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		if (*fd_data != NULL)
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

char	*ft_strchr_memset(const char *str, int ch, size_t n, int choice)
{
	if (choice == 1)
	{
		while (*str)
		{
			if (*str == (unsigned char)ch)
				return ((char *)str);
			str++;
		}
		if (*str == (unsigned char)ch)
			return ((char *)str);
		return (0);
	}
	if (choice == 2)
	{
		while (n)
		{
			*((unsigned char *)str + n - 1) = (unsigned char)ch;
			n--;
		}
		return ((char *)str);
	}
	return (0);
}

int	len_nl_cpy(char *buffer, char *src, int choice)
{
	int	len;

	len = 0;
	if (choice == 1)
	{
		while (buffer[len] != '\n' && buffer[len] != '\0')
			len++;
	}
	else if (choice == 2)
	{
		while (buffer[len] != '\0')
			len++;
	}
	else if (choice == 3)
	{
		while (src[len] != '\0')
		{
			buffer[len] = src[len];
			len++;
		}
		buffer[len] = '\0';
		return (0);
	}
	return (len);
}

char	*save_buffer(char *ptr, char *buffer)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (len_nl_cpy(buffer, NULL, 2) + 1));
	if (!tmp)
		return (NULL);
	ft_strchr_memset(tmp, 0, len_nl_cpy(buffer, NULL, 2) + 1, 2);
	i = 0;
	while (buffer[i] != '\0')
	{
		tmp[i] = buffer[i];
		i++;
	}
	tmp[i] = '\0';
	free(ptr);
	return (tmp);
}
