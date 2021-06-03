/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/03 11:44:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
void	*ft_memset(void *s, int c, size_t n);
int		copy_buffer_in_line(char *buffer, char **line);
char	*ft_strchr(const char *str, int ch);
char	*save_buffer(char *ptr, char *buffer);
int		ft_strlen_nl_and_strcpy(char *buffer, char *src, int choice);
int		copy_buffer_in_line_bis(char *buffer, char *tmp, int offset);
int		get_next_line_bis(char *buffer, char **line, int fd);

#endif
