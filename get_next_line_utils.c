/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palvare2 <palvare2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:40:56 by palvare2          #+#    #+#             */
/*   Updated: 2026/05/26 14:18:32 by palvare2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*free_str(char **str)
{
	int	i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[0][i])
	{
		str[0][i] = 0;
		i++;
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	if (c == 0)
		return (ft_len(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strcat(char **str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	if (!str1)
		return (-1);
	ret = malloc(sizeof(char) * (ft_len(*str1) + ft_len(str2) + 1));
	if (!ret)
		return (-1);
	i = 0;
	j = 0;
	while (*str1 && (*str1)[i])
	{
		ret[i] = (*str1)[i];
		i++;
	}
	while (str2 && str2[j])
		ret[i++] = str2[j++];
	ret[i] = '\0';
	free_str(str1);
	*str1 = ret;
	return (i);
}
