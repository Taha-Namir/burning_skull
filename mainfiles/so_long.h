/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:21:29 by tnamir            #+#    #+#             */
/*   Updated: 2022/01/20 17:45:53 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../gnl/get_next_line.h"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct player
{
	t_vector	pos;
}	t_player;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	char		**map;
	t_player	character;
	char		direction;
}				t_program;

void		playerposition(int x, int y);
t_window	window(void *mlx, int widht, int height, char *name);
t_image		sprite(void *mlx, char *path);
int			keypress(int key, void *param);
void		mapparsing(char **map, t_program *program,
				int newx, int newy);
char		*mapreader(char	*path);
void		putimage(t_program *program, char *path);

#endif