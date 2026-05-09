/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadamor <tsadamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:20 by tsadamor          #+#    #+#             */
/*   Updated: 2026/05/09 17:35:15 by tsadamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_adv(char *str, char *buff)
{
	char	*joined;
	size_t	str_len;
	size_t	buff_len;

	str_len = ft_strlen(str);
	buff_len = ft_strlen(buff);
	joined = malloc(str_len + buff_len + 1);
	if (!joined)
		return (free(str), NULL);
	joined[0] = '\0';
	if (str)
		ft_strlcpy(joined, str, str_len + 1);
	ft_strlcat(joined, buff, str_len + buff_len + 1);
	free(str);
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = 0;
	while (src[s_len])
		s_len++;
	d_len = 0;
	while (dst[d_len])
		d_len++;
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	while (src[i] && (d_len + i + 1) < size)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[d_len + i] = '\0';
	return (s_len + d_len);
}
