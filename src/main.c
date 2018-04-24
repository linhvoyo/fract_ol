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
#include <math.h>

t_mlx	*init_mlx(char *str, double offset_x, int fractol)
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
	tmp->map->offset_x = offset_x;
	tmp->map->offset_y = 0 ;
	tmp->map->color = 1;
	tmp->map->j_c_re = -0.7;
	tmp->map->j_c_im = 0.27015;
	tmp->map->fractol = fractol;
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

	mlx->img_ptr[++i] = 0 + (n * mlx->map->color);

	mlx->img_ptr[++i] = n % 255;
}

void julia(t_mlx *mlx)
{
	double new_re, new_im, old_re, old_im;
	int x;
	int y = 0;
	int i;

	ft_bzero(mlx->img_ptr, WIDTH * HEIGHT * mlx->bbp);
	printf("max_iter %d zoom %f color %d\n", mlx->map->max_iter, mlx->map->zoom, mlx->map->color);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			new_re = 1.5 * (x - WIDTH / 2) / (0.5 * mlx->map->zoom * WIDTH) + mlx->map->offset_x;
			new_im = (y - HEIGHT / 2) / (0.5 * mlx->map->zoom * HEIGHT) + mlx->map->offset_y;
			i = 0;
			while (i < mlx->map->max_iter)
			{
				old_re = new_re;
				old_im = new_im;

				new_re = old_re * old_re - old_im * old_im + mlx->map->j_c_re;
				new_im = 2 * old_re * old_im + mlx->map->j_c_im;

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
	printf("max_iter %d zoom %f color %d\n", mlx->map->max_iter, mlx->map->zoom, mlx->map->color);
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
			if (i < mlx->map->max_iter)
				test_put_pixel(mlx, x, y, 265 * i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}




void burning_ship(t_mlx *mlx)
{

	double pr, pi;
	double new_re, new_im, old_re, old_im;
	ft_bzero(mlx->img_ptr, WIDTH * HEIGHT * mlx->bbp);
	printf("max_iter %d zoom %f color %d\n", mlx->map->max_iter, mlx->map->zoom, mlx->map->color);
	if (mlx->map->zoom < 1)
		mlx->map->zoom = 1;
	int y = 0;
	while (y < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH)
		{
			pr = 1.5 *(x - WIDTH / 2) / (0.25 * mlx->map->zoom * WIDTH) + mlx->map->offset_x;
			pi = (y - HEIGHT / 2) / (0.25 * mlx->map->zoom * HEIGHT) + mlx->map->offset_y;
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
				new_im = 2 * fabs(old_re * old_im) + pi;
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

void print_error()
{
	ft_putstr("usage: ./fractol <image>\n\n");
	ft_putstr("--images:\n\tmandelbrot\n\tjulia\n\tburningship\n");
}
int main(int argc, char **argv)
{
	t_mlx	*mlx;
	(void)argc;

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if ((ft_strcmp(argv[1],"mandelbrot") == 0) && (mlx = init_mlx(argv[1], -0.5, 1)))
		mandelbrot(mlx);
	else if ((ft_strcmp(argv[1],"julia") == 0) && (mlx = init_mlx(argv[1], 0, 2)))
		julia(mlx);
	else if ((ft_strcmp(argv[1],"burningship") == 0) && (mlx = init_mlx(argv[1], 0, 3)))
		burning_ship(mlx);
	else
	{
		print_error();
		return(0);
	}

	mlx_key_hook(mlx->win_ptr, keys, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
