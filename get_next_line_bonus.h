/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2023/04/02 12:26:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_fd_data
{
	int					fd;
	char				*buf;
	struct s_fd_data	*next;
}						t_fd_data;

int			get_next_line(int fd, char **line);
int			ft_strlen_nl_or_strcpy(char *buffer, char *src, int choice);
int			copy_buffer_in_line(char *buffer, char **line, int *eof, int value);
int			cpy_buf_in_l_or_free(char **buffer, char *tmp, int offset, \
			int choice);
char		*s_buf(char *ptr, char *buffer);
char		*schr_or_mset(const char *str, int ch, size_t n, int choice);
void		buffer_handler(char **buffer, char **line, int *fd, int eof);
void		free_elem_and_relink(t_fd_data **fd_data, int fd);
t_fd_data	*fd_handler(t_fd_data **t_fd_data, int fd);
t_fd_data	*new_elem(t_fd_data **fd_data, int fd);

#endif
