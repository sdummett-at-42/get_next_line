/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/23 19:42:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char *readen_bytes = 0;
	int ret;

	ret = -1;
	if (readen_bytes == 0)
	{
		// EXEC READ_FD
	}
	else
	{
		if (check_nl_eof(readen_bytes, &ret));
	}
}



int main()
{
	int fd = open("file", O_RDONLY);
	printf("===\tfd = %d\t===\n", fd);

	return (0);
}
