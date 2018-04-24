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
	if (key == 126)
		mlx->map->offset_y -= 0.05/mlx->map->zoom;
	else if (key == 125)
		mlx->map->offset_y += 0.05/mlx->map->zoom;
	else if (key == 123)
		mlx->map->offset_x -= 0.05/mlx->map->zoom;
	else if (key == 124)
		mlx->map->offset_x += 0.05/mlx->map->zoom;
}

int keys(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 34)
		mlx->map->max_iter += 1;
	else if (key == 6)
	{
		mlx->map->zoom += mlx->map->zoom * 1;
		printf("%f\n",mlx->map->zoom);
		// int n = mlx->map->max_iter / 100;
		mlx->map->max_iter += 2 + ((mlx->map->zoom / mlx->map->max_iter) * (0.01));

		// if (mlx->map->zoom / mlx->map->max_iter > 2)
		// {
		// 	printf("hey\n");
		// 	mlx->map->max_iter += 2;
		// }
	}
	else if (key == 7)
	{
		mlx->map->zoom -= mlx->map->zoom * 1;
		// mlx->map->max_iter += 5;
	}
	else if (key >= 123 && key <= 126)
		shift_img(mlx, key);
	else if (key == 43)
		mlx->map->color += 1;
	else if (key == 47)
		mlx->map->color -= 1;
	else
	{
		printf("%d\n", key);
		return (0);

	}
	if (mlx->map->fractol == 1)
		mandelbrot(mlx);
	else if (mlx->map->fractol == 2)
		julia(mlx);
	return (1);
	// printf("%d\n", key);
	// return (0);
}
