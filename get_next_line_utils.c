/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbastug <erbastug@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:16:09 by erbastug          #+#    #+#             */
/*   Updated: 2024/12/28 19:30:55 by erbastug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char *reads, char *buff)
{
	if (reads)
		free(reads);
	if (buff)
		free(buff);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*find_newline(char *str)
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

char	*merge(char *kontrol, char *buff)
{
	char		*result;
	int			i;
	int			j;
	int			len1;
	int			len2;

	len1 = ft_strlen(kontrol);
	len2 = ft_strlen(buff);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (ft_free(kontrol, NULL));
	i = -1;
	while (++i < len1)
		result[i] = kontrol[i];
	j = -1;
	while (++j < len2)
		result[i++] = buff[j];
	result[i] = '\0';
	free(kontrol);
	return (result);
}
