/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/22 19:49:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMPORARY INCLUDES
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

//MANDATORY PROJECTS INCLUDES

#include <fcntl.h> 		// open
#include <stdlib.h> 	// malloc, free
#include <sys/types.h>	// read
#include <sys/uio.h>	// //
#include <unistd.h> 	// //

typedef struct s_gnl_datas
{
	int ret;			//valeurs de retours (1, 0, -1) / (-2) valeur par defaut ?
	char *remaining_bytes;	//octets lus
	t_gnl_datas *next;
}				t_gnl_datas;

int get_next_line(int fd, char **line)
{
	
}

int main()
{
	int fd = open("loremipsum", O_RDONLY);
	printf("fd = %d\n", fd);

	return (0);
}
