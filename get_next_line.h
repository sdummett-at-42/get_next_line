/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/24 17:41:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMPORARY INCLUDES
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
void print_bytes(char *buffer);

//MANDATORY PROJECTS INCLUDES

#include <fcntl.h> 		// open
#include <stdlib.h> 	// malloc, free
#include <sys/types.h>	// read
#include <sys/uio.h>	// //
#include <unistd.h> 	// //

typedef struct s_buffer
{
	int smthg_in_buffer; // 1 = YES | 0 = NO
	char *persist_buffer;
}				t_buffer;

int check_nl_eof(char *bytes, int *ret);
int read_on_fdesc(int fd, char *buffer);
int buffer_is_nl_eof(char *buffer, int *line_len);
int wipe_buffer(char *buffer, char **line_found, char *readen_bytes);
