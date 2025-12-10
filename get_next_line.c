/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabrogi <pabrogi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:20:07 by pabrogi           #+#    #+#             */
/*   Updated: 2025/12/10 10:58:13 by pabrogi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *get_line(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (ft_strdup_n(buffer, i + 1));
    return (NULL);
}

void shift_buffer(char *buffer, int i)
{
    int j;

    j = 0;
    while (buffer[i])
    {
        buffer[j] = buffer[i];
        j++;
        i++;
    }
    buffer[j] = '\0';
}

int read_more(int fd, char *buffer)
{
    int len_resto;
    int bytes;

    len_resto = ft_strlen(buffer);
    bytes = read(fd, buffer + len_resto, BUFFER_SIZE - len_resto);
    if (bytes <= 0 && len_resto == 0)
        return (-1);
    buffer[len_resto + bytes] = '\0';
    return (bytes);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *line;
    int         i;

    if (fd < 0)
        return (NULL);
    line = get_line(buffer);
    if (line)
    {
        i = ft_strlen(line);
        shift_buffer(buffer, i);
        return (line);
    }
    if (read_more(fd, buffer) == -1)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
    {
        line = ft_strdup_n(buffer, i + 1);
        shift_buffer(buffer, i + 1);
        return (line);
    }
    line = ft_strdup_n(buffer, ft_strlen(buffer));
    buffer[0] = '\0';
    return (line);
}
