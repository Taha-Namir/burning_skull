/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:48:51 by tnamir            #+#    #+#             */
/*   Updated: 2022/01/20 17:46:22 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	keypress(int key, void	*param)
{
	t_program	*program;

	program = (t_program *)param;
	program->direction = 'r';
	if (key == 53 || key == 65307)
		exit(0);
	else if (key == 13 || key == 126 || key ==  65362 || key == 119)
		program->character.pos.y -= 1;
	else if (key == 123 || key == 0 || key == 65361 || key == 97)
	{
		program->character.pos.x -= 1;
		program->direction = 'l';
	}
	else if (key == 124 || key == 2 || key == 65363 || key == 100)
	{
		program->character.pos.x += 1;
		program->direction = 'r';
	}
	else if (key == 125 || key == 1 || key == 65364 || key == 115)
		program->character.pos.y += 1;
	mapparsing(program->map, program, program->character.pos.x,
		program->character.pos.y);
	return (0);
}
