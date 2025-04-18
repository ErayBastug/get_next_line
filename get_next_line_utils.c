/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbastug <erbastug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:25:12 by erbastug          #+#    #+#             */
/*   Updated: 2025/01/01 16:54:24 by erbastug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_free(char *reads, char *buff)
{
	if (reads)
		free(reads);
	if (buff)
		free(buff);
	return (NULL);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_find_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_merge(char *reminder, char *buff)
{
	char		*result;
	ssize_t		i;
	ssize_t		j;
	ssize_t		len1;
	ssize_t		len2;

	len1 = ft_strlen(reminder);
	len2 = ft_strlen(buff);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (ft_free(reminder, NULL));
	i = -1;
	while (++i < len1)
		result[i] = reminder[i];
	j = -1;
	while (++j < len2)
		result[i++] = buff[j];
	result[i] = '\0';
	free(reminder);
	return (result);
}
