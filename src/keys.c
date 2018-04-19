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

int keys(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 34)
		mlx->map->max_iter += 1;
	else if (key == 6)
		mlx->map->zoom += 1;
	else if (key == 7)
		mlx->map->zoom -= 1;
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
