/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbastug <erbastug@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:05:08 by erbastug          #+#    #+#             */
/*   Updated: 2024/12/30 18:45:34 by erbastug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

static	char	*read_line(int fd, char *kontrol)
{
	int		a;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(kontrol, NULL));
	a = 1;
	while (a > 0 && !find_newline(kontrol))
	{
		a = read(fd, buff, BUFFER_SIZE);
		if (a == -1)
			return (ft_free(kontrol, buff));
		buff[a] = '\0';
		kontrol = merge(kontrol, buff);
		if (!kontrol)
			return (ft_free(kontrol, buff));
	}
	ft_free(buff, NULL);
	return (kontrol);
}

static char	*update(char *kontrol)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!kontrol)
		return (NULL);
	while (kontrol[i] != '\n' && kontrol[i] != '\0')
		i++;
	if (kontrol[i] == '\0')
		return (ft_free(kontrol, NULL));
	str = (char *)malloc((ft_strlen(kontrol) - i) * sizeof(char));
	if (!str)
		return (ft_free(kontrol, NULL));
	j = 0;
	while (kontrol[++i] != '\0')
		str[j++] = kontrol[i];
	str[j] = '\0';
	ft_free(kontrol, NULL);
	return (str);
}

static	char	*ft_get_line(char *kontrol)
{
	char	*line;
	int		i;
	int		j;

	if (kontrol[0] == '\0')
		return (NULL);
	i = 0;
	while (kontrol[i] != '\n' && kontrol[i] != '\0')
		i++;
	if (kontrol[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (ft_free(kontrol, NULL));
	j = 0;
	while (j < i)
	{
		line[j] = kontrol[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*kontrol;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	kontrol = read_line(fd, kontrol);
	if (!kontrol)
		return (NULL);
	str = ft_get_line(kontrol);
	if (!str)
	{
		free(kontrol);
		kontrol = NULL;
		return (NULL);
	}
	kontrol = update(kontrol);
	return (str);
}
