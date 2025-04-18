/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbastug <erbastug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:25:29 by erbastug          #+#    #+#             */
/*   Updated: 2025/01/01 16:58:55 by erbastug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static	char	*ft_read_line(int fd, char *remainder)
{
	ssize_t	a;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(remainder, NULL));
	a = 1;
	while (a > 0 && !ft_find_newline(remainder))
	{
		a = read(fd, buff, BUFFER_SIZE);
		if (a == -1)
			return (ft_free(remainder, buff));
		buff[a] = '\0';
		remainder = ft_merge(remainder, buff);
		if (!remainder)
			return (ft_free(remainder, buff));
	}
	ft_free(buff, NULL);
	return (remainder);
}

static char	*ft_update(char *remainder)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\0')
		return (ft_free(remainder, NULL));
	str = (char *)malloc((ft_strlen(remainder) - i) * sizeof(char));
	if (!str)
		return (ft_free(remainder, NULL));
	j = 0;
	while (remainder[++i] != '\0')
		str[j++] = remainder[i];
	str[j] = '\0';
	ft_free(remainder, NULL);
	return (str);
}

static	char	*ft_get_line(char *remainder)
{
	char	*line;
	ssize_t	i;
	ssize_t	j;

	if (remainder[0] == '\0')
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (ft_free(remainder, NULL));
	j = 0;
	while (j < i)
	{
		line[j] = remainder[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_read_line(fd, remainder);
	if (!remainder)
		return (NULL);
	str = ft_get_line(remainder);
	if (!str)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = ft_update(remainder);
	return (str);
}
