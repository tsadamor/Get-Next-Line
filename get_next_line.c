/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadamor <tsadamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:39 by tsadamor          #+#    #+#             */
/*   Updated: 2026/05/08 19:28:35 by tsadamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_untill_include_newline(int fd, char *str)
{
	char	*buff;
	int		read_bytes;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buff[read_bytes] = '\0';
		if (!str)
		{
			str = malloc(1);
			if (!str)
				return (NULL);
			str[0] = '\0';
		}
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*cut_at_newline(char *str)
{
	size_t	i;
	char	*line;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*update_str(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(ft_strlen(str) - i + 1);
	i++;
	j = 0;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}
	

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0)
		return (NULL);
	str = read_untill_include_newline(fd, str);
	line = cut_at_newline(str);
	
	return (line);
}