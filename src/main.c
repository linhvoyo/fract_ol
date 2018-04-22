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
	tmp->map->max_iter = 50;
	tmp->map->zoom = 1;
	tmp->map->offset_x = -0.5 ;
	tmp->map->offset_y = 0 ;
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

	n =n + 0;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = (x * 4) + (y * mlx->stride);

	mlx->img_ptr[i] = 255 * n;

	mlx->img_ptr[++i] = 0 + n;

	mlx->img_ptr[++i] = n % 255;
}

void  julia(t_mlx *mlx)
{
	double c_re, c_im;
	double new_re, new_im, old_re, old_im;

	double zoom = 1;
	double movex = 0;
	double movey = 0;



	c_re = -0.7;
	c_im = 0.27015;


	int x;
	int y = 0;
	int i;

	printf("max_iter %d zoom %d\n", mlx->map->max_iter, mlx->map->zoom);

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			new_re = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + movex;
			new_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + movey;

			i = 0;

			while (i < mlx->map->max_iter)
			{
				old_re = new_re;
				old_im = new_im;

				new_re = old_re * old_re - old_im * old_im + c_re;
				new_im = 2 * old_re * old_im + c_im;

				if ((new_re * new_re + new_im * new_im) > 4)
					break;

				i++;
			}
			if (i < mlx->map->max_iter)
				test_put_pixel(mlx, x, y, 265 * i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}


void mandelbrot(t_mlx *mlx)
{

	double pr, pi;
	double new_re, new_im, old_re, old_im;





	ft_bzero(mlx->img_ptr, WIDTH * HEIGHT * mlx->bbp);
	printf("max_iter %d zoom %d\n", mlx->map->max_iter, mlx->map->zoom);

	if (mlx->map->zoom < 1)
		mlx->map->zoom = 1;

	int y = 0;
	while (y < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH)
		{
			pr = 1.5 *(x - WIDTH / 2) / (0.5 * mlx->map->zoom * WIDTH) + mlx->map->offset_x;
			pi = (y - HEIGHT / 2) / (0.5 * mlx->map->zoom * HEIGHT) + mlx->map->offset_y;
			new_re = 0;
			new_im = 0;
			old_re = 0;
			old_im = 0;

			int i = 0;
			while (i < mlx->map->max_iter)
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
			if (i < mlx->map->max_iter)
				test_put_pixel(mlx, x, y, 265 * i);
			// if (i == mlx->map->max_iter)
			// 	test_put_pixel(mlx, x, y, 1);
			// else
			// 	test_put_pixel(mlx, x, y, 265 * i);
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

	printf("wetwer\n");

	mandelbrot(mlx);
	// julia(mlx);

	//
	// put_pixel(mlx->img_ptr, 100, 100, 0xFF00FF);
	//
	// test_put_pixel(mlx, 100, 100, 1);
	mlx_key_hook(mlx->win_ptr, keys, mlx);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
