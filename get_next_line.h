/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palvare2 <palvare2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:32:30 by palvare2          #+#    #+#             */
/*   Updated: 2026/05/20 19:45:10 by palvare2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//get_next_line_utils_c
size_t	ft_len(char *str);
char *free_str(char **str);
int ft_strchr(char *str, char c);
int ft_strcat(char **str1, char *str2);

//get_next_line_h
char *get_out(char *line);
char *get_save(char *line);
char *ft_malloc(int fd);
char	*get_next_line(int fd);

#endif