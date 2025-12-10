/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabrogi <pabrogi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:21 by pabrogi           #+#    #+#             */
/*   Updated: 2025/12/10 10:37:52 by pabrogi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int     ft_strlen(char *s);
char    *ft_strdup_n(char *s, int n);
char    *get_line(char *buffer);
void    shift_buffer(char *buffer, int i);
int     read_more(int fd, char *buffer);
char    *get_next_line(int fd);

#endif
