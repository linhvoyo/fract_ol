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
	tmp->img_ptr = mlx_get_data_addr(tmp->img, &tmp->bbp, &tmp->stride, &tmp->endian);
	tmp->bbp /= 8;
	if (!(tmp->map = malloc(sizeof(t_map))))
		return (NULL);
	tmp->map->max_iter = 1;
	tmp->map->zoom = 1;
	return (tmp);
}

// void put_pixel(int *img_ptr, int x, int y, int color)
// {
// 	int i;
// 	i = x + (y * WIDTH);
// 	img_ptr[i] = color;
// }

void test_put_pixel(t_mlx *mlx, int x, int y, int n)
{
	int i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = (x * 4) + (y * mlx->stride);
	mlx->img_ptr[i] = n % 256;
	mlx->img_ptr[i] = 255;
	mlx->img_ptr[i] = 255 * n;
}

// void mandelbrot(int *img_ptr)
// {
// 	double c_re, c_im;
// 	double new_re, new_im, old_re, old_im;
//
// 	double zoom = 1;
// 	double movex = 0;
// 	double movey = 0;
//
// 	int color = 0xFF00FF;
// 	int max_iteration = 300;
//
//
// 	c_re = -0.7;
// 	c_im = 0.27015;
//
//
//
// 	int x = 0;
// 	int y = 0;
// 	int i;
//
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDTH)
// 		{
// 			new_re = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + movex;
// 			new_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + movey;
//
// 			i = 0;
//
// 			while (i < max_iteration)
// 			{
// 				old_re = new_re;
// 				old_im = new_im;
//
// 				new_re = old_re * old_re - old_im * old_im + c_re;
// 				new_im = 2 * old_re * old_im + c_im;
//
// 				if ((new_re * new_re + new_im * new_im) > 4)
// 					break;
//
// 				i++;
// 			}
//
// 			color = HSVtoRGB(ColorHSV(i%256,255,255 * (i < max_iteration)));
// 			put_pixel(img_ptr, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
//
// }


void mandelbrot(t_mlx *mlx)
{

	double pr, pi;
	double new_re, new_im, old_re, old_im;

 	int zoom = mlx->map->zoom;
	double movex = -0.5;
	double movey = 0;


	int max_iter = mlx->map->max_iter;

	printf("max_iter %d zoom %d\n", mlx->map->max_iter, zoom);
//	while (1)
//	{
		int y = 0;
		while (y < HEIGHT)
		{
			int x = 0;
			while (x < WIDTH)
			{
				pr = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + movex;
				pi = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + movey;
				new_re = 0;
				new_im = 0;
				old_re = 0;
				old_im = 0;

				int i = 0;
				while (i < max_iter)
				{
					old_re = new_re;
					old_im = new_im;

					new_re = old_re * old_re - old_im * old_im + pr;
					new_im = 2 * old_re * old_im + pi;
					if ((new_re * new_re + new_im * new_im) > 4)
						break;
						i++;
				}
				// printf("x: %d y: %d\n", x , y);
				if (i < max_iter)
					test_put_pixel(mlx, x, y, i);
				x++;
			}
			// printf("x: %d y: %d\n", x , y);
			// put_pixel(img_ptr, x, y, color);
			y++;
		}


//	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);

}


int main()
{
	t_mlx	*mlx;

	mlx = init_mlx("hello");


	mandelbrot(mlx);
	//
	// put_pixel(mlx->img_ptr, 100, 100, 0xFF00FF);

	// test_put_pixel(mlx, 100, 100, 2);
	mlx_key_hook(mlx->win_ptr, keys, mlx);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
