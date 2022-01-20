/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:09:47 by tnamir            #+#    #+#             */
/*   Updated: 2022/01/19 15:11:47 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putimage(t_program *program, char *path)
{
	program->sprite = sprite(program->mlx, path);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
}
