/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:33:43 by tnamir            #+#    #+#             */
/*   Updated: 2022/10/11 20:55:52 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <errno.h>

static t_vector	windowdimensions(char *p)
{
	int			fd;
	t_vector	dimensions;
	char		*line;

	fd = open(p, O_RDONLY);
	line = get_next_line(fd);
	dimensions.x = (int)ft_strlen(line) - 1;
	dimensions.y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		dimensions.y += 1;
	}
	close(fd);
	free(line);
	return (dimensions);
}

static int	wallcheckerleftright(char	**map)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map[y - 1][x])
		x++;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	wallcheckerupdown(char	**map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
		y++;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1')
			return (0);
		x++;
	}
	if (!wallcheckerleftright(map))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_program	program;
	t_vector	windim;

	if (argc == 2)
	{
		program.map = ft_split(mapreader(argv[1]), '\n');
		if (!program.map)
		{
			write(1, "Error : invalid map", 19);
			exit(0);
		}
		if (!wallcheckerupdown(program.map))
		{
			write(1, "Error : invalid map", 19);
			exit(0);
		}
		program.mlx = mlx_init();
		windim = windowdimensions(argv[1]);
		program.window = window(program.mlx, windim.x * TILE_SIZE,
				windim.y * TILE_SIZE, "BurningSkull!");
		mapparsing(program.map, &program, 0, 0);
		mlx_key_hook(program.window.reference, *keypress, &program);
		// mlx_loop_hook(program.mlx, *keypress, &program);
		mlx_loop(program.mlx);
	}
	return (0);
}
