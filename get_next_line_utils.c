/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/31 17:49:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
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

void	*ft_memset(void *s, int c, size_t n)
{
	while (n)
	{
		*((unsigned char *)s + n - 1) = (unsigned char)c;
		n--;
	}
	return (s);
}

int		ft_strlen_nl(char *buffer, int choice)
{
	int len;

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
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*save_buffer(char *ptr, char *buffer)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen_nl(buffer, 2));
	if (!tmp)
		return (NULL);
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

int		copy_buffer_in_line(char *buffer, char **line)
{
	int i;
	int nl;
	int offset;
	char *tmp;

	nl = 0;
	if (*line == NULL)
		offset = ft_strlen_nl(buffer, 1);
	else
		offset = ft_strlen_nl(buffer, 1) + ft_strlen_nl(buffer, 1);
	tmp = (char *)malloc(sizeof(char) * offset + 1 + 10000);	
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
