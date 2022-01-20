/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:07:00 by tnamir            #+#    #+#             */
/*   Updated: 2022/01/20 17:01:20 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenghtchecker(char	*line, int lenght)
{
	if (line[lenght - 1] == '\n')
		lenght += 1;
	if ((int)ft_strlen(line) != lenght - 1)
		return (0);
	return (1);
}

char	*mapreader(char *path)
{
	int		fd;
	char	*line;
	char	*text;
	int		lenght;

	lenght = ft_strlen(path);
	if (path[lenght - 1] != 'r' || path[lenght - 2] != 'e'
		|| path[lenght - 3] != 'b' || path[lenght - 4] != '.')
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	lenght = ft_strlen(line);
	while (line)
	{
		if (!lenghtchecker(line, lenght))
			return (0);
		text = ft_strjoin(text, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (text);
}
