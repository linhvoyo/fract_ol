/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:45:23 by lilam             #+#    #+#             */
/*   Updated: 2018/04/17 21:29:51 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>


void	shift_img(t_mlx *mlx, int key)
{
	if (key == 125)
		mlx->map->offset_y -= 0.05/mlx->map->zoom;
	else if (key == 126)
		mlx->map->offset_y += 0.05/mlx->map->zoom;
	else if (key == 124)
		mlx->map->offset_x -= 0.05/mlx->map->zoom;
	else if (key == 123)
		mlx->map->offset_x += 0.05/mlx->map->zoom;
}

int key_down(int key, t_mlx *mlx)
{
	// if (mlx->ctrl == 1)
	// 	mlx->map->max_iter--;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 34)
		mlx->map->max_iter += 1;
	else if (key == 31)
		mlx->map->max_iter -= 1;
	else if (key == 6)
	{
		// mlx->map->zoom_inc = mlx->map->zoom * 0.25;
		mlx->map->zoom += 0.25;
		printf("%f\n",mlx->map->zoom);
		// int n = mlx->map->max_iter / 100;
		mlx->map->max_iter += 2 + ((mlx->map->zoom / mlx->map->max_iter) * (0.01));
	}
	else if (key == 7)
	{
		mlx->map->zoom -= 0.25;
		// mlx->map->max_iter += 5;
	}
	else if (key >= 123 && key <= 126)
		shift_img(mlx, key);
	else if (key == 43)
		mlx->map->color += 1;
	else if (key == 47)
		mlx->map->color -= 1;
	else if (key == 256)
		mlx->ctrl = 1;
	else
	{
		printf("%d\n", key);
		return (0);
	}
	pthread(mlx);
	return (1);
}



int keys(int key, t_mlx *mlx)
{
	if (key == 256)
		mlx->ctrl = 1;
	pthread(mlx);
	return (0);
}

int motion_hook(int x, int y, t_mlx *mlx)
{
	printf("x: %d y:%d \n", x, y);
	mlx->mouse_x = x;
    mlx->mouse_y = y;
    pthread(mlx);
	return (0);
}

int	mouse(int mouse, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mouse == 5 && mlx->ctrl == 0)
		mlx->map->j_c_re += 0.1;
	else if (mouse == 5 && mlx->ctrl == 1)
		mlx->map->zoom += 0.5;
	else if (mouse == 4)
		mlx->map->j_c_re -= 0.1;
	else if (mouse == 1)
		mlx->map->j_c_im += 0.1;
	else if (mouse == 2)
		mlx->map->j_c_im -= 0.1;
	else
	{
		return (0);
	}
	printf("%d\n", mouse);
	pthread(mlx);
	return (1);
}
