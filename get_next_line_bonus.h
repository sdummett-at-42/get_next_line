/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/05 11:55:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// TEMPORARY INCLUDES /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>

void	print_gnl_result(int fd, char **line);

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

////////////////////////////////////////////////////////////////////////////////

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_fd_data
{
	int					fd;
	char				*buffer;
	struct s_fd_data	*next;
}						t_fd_data;

int			get_next_line(int fd, char **line);
int			get_next_line_bis(char *buffer, char **line, int fd);
int			buffer_handler(char **buffer, char **line, int fd, int eof);
int			copy_buffer_in_line(char *buffer, char **line);
int			copy_buffer_in_line_bis(char **buffer, char *tmp, int offset, \
			int choice);
char		*save_buffer(char *ptr, char *buffer);
int			ft_strlen_nl_and_strcpy(char *buffer, char *src, int choice);
char		*ft_strchr_memset(const char *str, int ch, size_t n, int choice);
t_fd_data	*fd_handler(t_fd_data **t_fd_data, int fd);
t_fd_data	*new_elem(t_fd_data **fd_data, int fd, int choice);

#endif
