/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabrogi <pabrogi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:28:36 by pabrogi           #+#    #+#             */
/*   Updated: 2025/12/10 11:00:10 by pabrogi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup_n(char *s, int n)
{
    char    *new;
    int     i;

    new = malloc(n + 1);
    if (!new)
        return (NULL);
    i = 0;
    while (i < n)
    {
        new[i] = s[i];
        i++;
    }
    new[n] = '\0';
    return (new);
}
