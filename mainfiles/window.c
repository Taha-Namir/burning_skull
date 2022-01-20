/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:28:21 by tnamir            #+#    #+#             */
/*   Updated: 2022/01/19 15:43:43 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cclose(void)
{
	exit(0);
}

t_window	window(void *mlx, int width, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, cclose, 0);
	return (window);
}
