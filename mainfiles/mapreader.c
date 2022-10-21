/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:07:00 by tnamir            #+#    #+#             */
/*   Updated: 2022/02/14 12:22:22 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	lenghtchecker(char	*line, int lenght)
{
	if (line[lenght - 1] == '\n')
		lenght += 1;
	if ((int)ft_strlen(line) != lenght - 1)
		return (0);
	return (1);
}

static int	letters_checker(char	*text)
{
	int	x;
	int	player_nbr;
	int	collectibles_nbr;
	int	exit_nbr;

	player_nbr = 0;
	collectibles_nbr = 0;
	exit_nbr = 0;
	x = 0;
	while (text[x])
	{
		if (text[x] == 'P')
			player_nbr++;
		if (text[x] == 'C')
			collectibles_nbr++;
		if (text[x] == 'E')
			exit_nbr++;
		x++;
	}
	if (player_nbr > 1)
		return (0);
	if (collectibles_nbr == 0 || exit_nbr == 0)
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
	if (!line)
		return (0);
	lenght = ft_strlen(line);
	text = NULL;
	while (line)
	{
		if (!lenghtchecker(line, lenght))
			return (0);
		text = ft_strjoin(text, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!letters_checker(text))
		return (0);
	return (text);
}
