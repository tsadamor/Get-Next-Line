/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadamor <tsadamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:39 by tsadamor          #+#    #+#             */
/*   Updated: 2026/05/14 12:43:53 by tsadamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_include_newline(int fd, char *str);
char	*cut_at_newline(char *str);
char	*update_str(char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_until_include_newline(fd, str);
	if (!str)
		return (NULL);
	if (*str == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = cut_at_newline(str);
	str = update_str(str);
	return (line);
}

char	*read_until_include_newline(int fd, char *str)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(str), NULL);
		buff[bytes_read] = '\0';
		str = ft_strjoin_adv(str, buff);
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
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
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
		return (free(str), NULL);
	new_str = malloc(ft_strlen(str) - i + 1);
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (free(str), new_str);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
