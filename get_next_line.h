/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/23 17:24:47 by sdummett         ###   ########.fr       */
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
	struct s_gnl_datas *next;
}				t_gnl_datas;


int check_nl_eof(char *bytes, int *ret);
