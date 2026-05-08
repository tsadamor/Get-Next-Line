/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadamor <tsadamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:20 by tsadamor          #+#    #+#             */
/*   Updated: 2026/05/08 17:52:17 by tsadamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}