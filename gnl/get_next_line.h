/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:14 by tnamir            #+#    #+#             */
/*   Updated: 2021/11/30 15:44:14 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(char	*s);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlen(const char	*s);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	**ft_split(char	*s, char c);
int		indexof(char *str, char c);
char	*ft_itoa(int n);

#endif