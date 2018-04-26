/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:45:23 by lilam             #+#    #+#             */
/*   Updated: 2018/04/25 21:50:47 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int key_down(int key, t_mlx *mlx)
{
	key == 53 ? exit(EXIT_SUCCESS) : 0;
	key == 34 ? mlx->map->max_iter += 1 : 0;
	key == 31 ? mlx->map->max_iter -= 1 : 0;
	key == 6 ? mlx->map->zoom *= 1.50 : 0;
	key == 7 && (mlx->map->zoom / 1.50 > 0) ? mlx->map->zoom /= 1.50 : 0;
	key == 123 ? mlx->map->offset_x += 0.3/mlx->map->zoom : 0;
	key == 124 ? mlx->map->offset_x -= 0.3/mlx->map->zoom : 0;
	key == 125 ? mlx->map->offset_y -= 0.3/mlx->map->zoom : 0;
	key == 126 ? mlx->map->offset_y += 0.3/mlx->map->zoom : 0;
	key == 43 ? mlx->map->color += 1 : 0;
	key == 47 ? mlx->map->color -= 1 : 0;
	if (key == 53 || key == 34 || key == 31 || key == 6 || key == 7 ||
			(123 <= key && key <= 126) || key == 43 || key == 47)
		pthread(mlx);
	return (1);
}

int motion_hook(int x, int y, t_mlx *mlx)
{
	if ((mlx->map->fractol == 2 || mlx->map->fractol == 4) && x >= 0 && y >= 0)
	{
		mlx->mouse_x = (x - 640);
    	mlx->mouse_y = (y - 400);
		pthread(mlx);
	}
	return (0);
}

int	mouse(int mouse, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mouse == 5)
		mlx->map->zoom *= 1.50;
	else if (mouse == 4 && (mlx->map->zoom / 1.50 > 0))
		mlx->map->zoom /= 1.50;
	else
		return (0);
	pthread(mlx);
	return (1);
}
