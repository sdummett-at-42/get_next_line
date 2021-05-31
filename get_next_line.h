/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/31 18:34:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// TEMPORARY INCLUDES /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// MANDATORY INCLUDES /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int 	get_next_line(int fd, char **line);
void	*ft_memset(void *s, int c, size_t n);
int		copy_buffer_in_line(char *buffer, char **line);
char 	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *str, int ch);
char	*save_buffer(char *ptr, char *buffer);
int		ft_strlen_nl(char *buffer, int choice);
