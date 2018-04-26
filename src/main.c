/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:22:30 by lilam             #+#    #+#             */
/*   Updated: 2018/04/26 00:00:08 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define VS t_mlx *mlx=(t_mlx *)img; int x,i; double c[4]; t_map *map=mlx->map
#define MS int x,i; t_mlx *mlx = (t_mlx *)img; double c[6];
#define INIT c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0;

t_mlx	*init_mlx(char *str, double offset_x, int fractol)
{
	t_mlx *tmp;

	if (!(tmp = malloc(sizeof(t_mlx))))
		return (NULL);
	tmp->mlx_ptr = mlx_init();
	tmp->win_ptr = mlx_new_window(tmp->mlx_ptr, WIDTH, HEIGHT, str);
	tmp->img = mlx_new_image(tmp->mlx_ptr, WIDTH, HEIGHT);
	tmp->img_ptr = mlx_get_data_addr(tmp->img, &tmp->bbp,
			&tmp->stride, &tmp->endian);
	tmp->bbp /= 8;
	tmp->start = 0;
	tmp->end = HEIGHT;
	tmp->error = 1;
	if (!(tmp->map = malloc(sizeof(t_map))))
		return (NULL);
	tmp->map->max_iter = 50;
	tmp->map->zoom = 1;
	tmp->map->offset_x = offset_x;
	tmp->map->offset_y = 0;
	tmp->map->color = 1;
	tmp->map->fractol = fractol;
	return (tmp);
}

void	*julia(void *img)
{
	VS;
	while (mlx->start < mlx->end)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c[0] = 1.5 * (x - 640) / (160 * map->zoom) + map->offset_x;
			c[1] = (mlx->start - 400) / (100 * map->zoom) + map->offset_y;
			i = -1;
			while (++i < map->max_iter)
			{
				c[2] = c[0];
				c[3] = c[1];
				c[0] = c[2] * c[2] - c[3] * c[3] + (-0.7 * mlx->mouse_x / 300);
				map->fractol == 4 ? (c[1] = fabs(2 * c[2] *
					c[3]) + (0.27015 * mlx->mouse_y / 300)) : (c[1] = 2
					* c[2] * c[3] + (0.27015 * mlx->mouse_y / 300));
				if ((c[0] * c[0] + c[1] * c[1]) > 4)
					break ;
			}
			(i < map->max_iter) ? put_pixel(mlx, x, mlx->start, 265 * i) : 0;
		}
		mlx->start++;
	}
	return (NULL);
}

void	*mandelbrot_set(void *img)
{
	MS;
	while (mlx->start < mlx->end && (x = -1))
	{
		while (++x < WIDTH && (i = -1))
		{
			c[0] = 1.5 * (x - 640) / (320 * mlx->map->zoom) +
				mlx->map->offset_x;
			c[1] = (mlx->start - 400) / (200 * mlx->map->zoom) +
				mlx->map->offset_y;
			INIT;
			while (++i < mlx->map->max_iter)
			{
				c[4] = c[2];
				c[5] = c[3];
				c[2] = c[4] * c[4] - c[5] * c[5] + c[0];
				mlx->map->fractol == 1 ? (c[3] = 2 * c[4] * c[5] + c[1]) :
					(c[3] = 2 * fabs(c[4] * c[5]) + c[1]);
				if ((c[2] * c[2] + c[3] * c[3]) > 4)
					break ;
			}
			i < mlx->map->max_iter ? put_pixel(mlx, x, mlx->start, 265 * i) : 0;
		}
		mlx->start++;
	}
	return (NULL);
}

void	pthread(t_mlx *mlx)
{
	int			i;
	t_mlx		win[4];
	pthread_t	tid[4];

	ft_bzero(mlx->img_ptr, WIDTH * HEIGHT * mlx->bbp);
	i = -1;
	while (++i < 4 && (ft_memcpy((void*)&win[i], mlx, sizeof(t_mlx))))
	{
		win[i].start = i * 200;
		win[i].end = (i + 1) * 200;
	}
	i = -1;
	while (++i < 4)
		if (mlx->map->fractol == 1 || mlx->map->fractol == 3)
			pthread_create(&tid[i], NULL, mandelbrot_set, &win[i]);
		else if (mlx->map->fractol == 2 || mlx->map->fractol == 4)
			pthread_create(&tid[i], NULL, julia, &win[i]);
	while (--i >= 0)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	print(1, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (print(0, mlx = NULL));
	if ((ft_strcmp(argv[1], "mandelbrot") == 0))
		mlx = init_mlx(argv[1], 0, 1);
	else if ((ft_strcmp(argv[1], "julia") == 0))
		mlx = init_mlx(argv[1], 0, 2);
	else if ((ft_strcmp(argv[1], "burningship") == 0))
		mlx = init_mlx(argv[1], 0, 3);
	else if ((ft_strcmp(argv[1], "dulia") == 0))
		mlx = init_mlx(argv[1], 0, 4);
	else
		return (print(0, mlx = NULL));
	pthread(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_down, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, motion_hook, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
