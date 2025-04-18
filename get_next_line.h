/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbastug <erbastug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:25:41 by erbastug          #+#    #+#             */
/*   Updated: 2025/01/01 16:52:33 by erbastug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

char	*get_next_line(int fd);
char	*ft_free(char *reads, char *buff);
char	ft_find_newline(char *s);
char	*ft_merge(char *remainder, char *buff);
ssize_t	ft_strlen(char *str);
#endif
