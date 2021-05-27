/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/27 20:10:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMPORARY INCLUDES
#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//MANDATORY PROJECTS INCLUDES

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


int buffer_len(char *buffer);
void ft_memset(void *buffer, int size);
int copy_buffer_in_line(char *buffer, char **line);
int check_buffer(char *buffer, char **new_buffer);
int empty_string(char **line);
