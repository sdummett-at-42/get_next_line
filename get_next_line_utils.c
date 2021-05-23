/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/23 17:24:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

		//////////////
void print_bytes(char *str)
{
	int len;

	len = 0;
	while (str[len] != -1)
		len++;
	printf("len = %d\n", len);
	write(1, str, len);
}

void open_fdesc(int fd)
{
	int ret;
	char buf[50];

	ret = read(fd, buf, 1);
	if (ret < 0)
	{
		write(1, "Something wrong happened during the read.\n", 42);
		return ;
	}
	buf[ret] = -1;
	printf("ret = %d\n", ret);
	print_bytes(buf);
}
		///////////// A TESTER

void cat_bytes_found(char *line_found, char *tmp_bytes);

void read_on_fdesc(int fd, char **readen_bytes, char **line)
{
	char *tmp_bytes;
	char *line_found;
	

}

int	check_nl_eof(char *bytes, int *ret)
{
	int i;

	i = 0;
	while (bytes[i] != -1)
	{
		if (bytes[i] == '\n')
		{
			printf("i = %d\n", i);
			*ret = 1;
			return (1);
		}
		else if (bytes[i] == '\0')
		{
			printf("i = %d\n", i);
			*ret = 0;
			return (0);
		}
		i++;
	}
	return (-1);
}

int main()
{
	int fd = open("file", O_RDONLY);
	open_fdesc(fd);
	return (0);
}
