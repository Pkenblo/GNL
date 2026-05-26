/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palvare2 <palvare2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:29:22 by palvare2          #+#    #+#             */
/*   Updated: 2026/05/26 14:15:39 by palvare2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_out(char *line)
{
	char	*new;
	int		i;

	i = 0;
	if (line[i] == 0)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_save(char *line)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = 0;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\n') == -1)
		return (free_str(&line));
	while (line[i] != '\n')
		i++;
	i++;
	ret = malloc(sizeof(char) * ((ft_len(line) - i) + 1));
	if (!ret)
		return (free_str(&line));
	while (line[i])
		ret[j++] = line[i++];
	ret[j] = 0;
	free_str(&line);
	return (ret);
}

char	*ft_malloc(int fd)
{
	char	*buff;
	int		size;
	char	*ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	size = 1;
	ret = NULL;
	while (size != 0 && ft_strchr(buff, '\n') == -1)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (free_str(&buff));
		buff[size] = 0;
		ft_strcat(&ret, buff);
	}
	free_str(&buff);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (free_str(&line));
	}
	new_line = ft_malloc(fd);
	ft_strcat(&line, new_line);
	free_str(&new_line);
	if (line == NULL)
		return (NULL);
	out = get_out(line);
	line = get_save(line);
	return (out);
}
