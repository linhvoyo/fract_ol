/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:22:30 by lilam             #+#    #+#             */
/*   Updated: 2018/04/17 22:10:01 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_mlx	*init_mlx(char *str)
{
	t_mlx *tmp;
	tmp = malloc(sizeof(t_mlx));
	
	if (!tmp)
		return (NULL);	
	tmp->mlx_ptr = mlx_init();
	tmp->win_ptr = mlx_new_window(tmp->mlx_ptr, WIDTH, HEIGHT, str);
	tmp->img = mlx_new_image(tmp->mlx_ptr, WIDTH, HEIGHT);
	tmp->img_ptr = (int *)mlx_get_data_addr(tmp->img, &tmp->bbp, &tmp->stride, &tmp->endian);
	tmp->bbp /= 8;
	return (tmp);
}

void put_pixel(int *img_ptr, int x, int y, int color)
{
	int i;
	i = x + (y * WIDTH);
	img_ptr[i] = color;
}

int main()
{
	t_mlx	*mlx;
	mlx = init_mlx("hello");

	put_pixel(mlx->img_ptr, 100, 100, 0xFF00FF);

	mlx_key_hook(mlx->win_ptr, keys, (void *)0);	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
