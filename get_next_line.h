/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/03 18:47:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
int		get_next_line(int fd, char **line);
int		get_next_line_bis(char *buffer, char **line, int fd);
int		buffer_handler(char **buffer, char **line, int fd, int eof);
int		copy_buffer_in_line(char *buffer, char **line);
int		copy_buffer_in_line_bis(char **buffer, char *tmp, int offset, \
		int choice);
char	*save_buffer(char *ptr, char *buffer);
int		ft_strlen_nl_and_strcpy(char *buffer, char *src, int choice);
char	*ft_strchr_memset(const char *str, int ch, size_t n, int choice);
char	*fd_handler(t_fd_data **t_fd_data, int fd);

#endif
