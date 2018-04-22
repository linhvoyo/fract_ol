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
		mlx->map->offset_y -= 1;
	else if (key == 125)
		mlx->map->offset_y += 1;
	else if (key == 123)
		mlx->map->offset_x -= 1;
	else if (key == 124)
		mlx->map->offset_x += 1;
}

int keys(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 34)
		mlx->map->max_iter += 1;
	else if (key == 6)
	{
		mlx->map->zoom += 1;
		mlx->map->max_iter += 1;
	}
	else if (key == 7)
	{
		mlx->map->zoom -= 1;
		// mlx->map->max_iter += 5;
	}
	else if (key >= 123 && key <= 126)
		shift_img(mlx, key);
	else
	{
		printf("%d\n", key);
		return (0);

	}
	mandelbrot(mlx);
	return (1);
	// printf("%d\n", key);
	// return (0);
}
