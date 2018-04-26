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
	tmp->start = 0;
	tmp->end = HEIGHT;
	tmp->error = 1;
	if (!(tmp->map = malloc(sizeof(t_map))))
		return (NULL);
	tmp->map->max_iter = 50;
	tmp->map->zoom = 1;
	tmp->map->offset_x = offset_x;
	tmp->map->offset_y = 0 ;
	tmp->map->color = 1;
	tmp->map->fractol = fractol;
	return (tmp);
}


void put_pixel(t_mlx *mlx, int x, int y, int n)
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

void* julia(void *img)
{
	t_mlx *mlx = (t_mlx *)img;
	double new_re, new_im, old_re, old_im;
	while (mlx->start < mlx->end)
	{
		int x = 0;
		while (x < WIDTH)
		{
			new_re = 1.5 * (x - 650) / (0.125 * mlx->map->zoom * WIDTH) + mlx->map->offset_x;
			new_im = (mlx->start - 400) / (0.125 * mlx->map->zoom * HEIGHT) + mlx->map->offset_y;
			int i = 0;
			while (i < mlx->map->max_iter)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + (-0.7 * mlx->mouse_x / 300);
				if (mlx->map->fractol == 4)
					new_im = fabs(2 * old_re * old_im) + (0.27015 * mlx->mouse_y / 300);
				else if (mlx->map->fractol == 2)
					new_im = 2 * old_re * old_im + (0.27015 * mlx->mouse_y / 300);
				if ((new_re * new_re + new_im * new_im) > 4)
					break;
				i++;
			}
			if (i < mlx->map->max_iter)
				put_pixel(mlx, x, mlx->start, 265 * i);
			x++;
		}
		mlx->start++;
	}
	return (NULL);
}


void* mandelbrot_set(void* img)
{
	t_mlx *mlx = (t_mlx *)img;
	double pr, pi;
	double new_re, new_im, old_re, old_im;
	int y = mlx->start;
	while (y < mlx->end)
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
				if (mlx->map->fractol == 1)
					new_im = 2 * old_re * old_im + pi;
				else if (mlx->map->fractol == 3)
					new_im = 2 * fabs(old_re * old_im) + pi;
				if ((new_re * new_re + new_im * new_im) > 4)
					break;
				i++;
			}
			if (i < mlx->map->max_iter)
				put_pixel(mlx, x, y, 265 * i);
			x++;
		}
		y++;
	}
	return(NULL);
}


int print_error()
{
	ft_putstr("usage: ./fractol <image>\n\n");
	ft_putstr("--images:\n\tmandelbrot\n\tjulia\n\tburningship\n\tdulia\n");
	return (0);
}

void pthread(t_mlx *mlx)
{
	int i;
	t_mlx win[4];
	pthread_t tid[4];

	ft_bzero(mlx->img_ptr, WIDTH * HEIGHT * mlx->bbp);
	i = -1;
	while (++i < 4 && (ft_memcpy((void*)&win[i], mlx, sizeof(t_mlx))))
	{
		win[i].start = i * 200;
		win[i].end = (i + 1) * 200;
	}
	i = -1;
	while(++i < 4)
		if (mlx->map->fractol == 1 || mlx->map->fractol == 3)
			pthread_create(&tid[i], NULL, mandelbrot_set, &win[i]);
		else if (mlx->map->fractol == 2 || mlx->map->fractol == 4)
			pthread_create(&tid[i], NULL, julia, &win[i]);
	while (--i >= 0)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xffffff, "iter:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 110, 10, 0xffffff, ft_itoa(mlx->map->max_iter));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 40, 0xffffff, "zoom:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 110, 40, 0xffffff, ft_itoa(mlx->map->zoom));
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (print_error());
	if ((ft_strcmp(argv[1],"mandelbrot") == 0))
		mlx = init_mlx(argv[1], 0, 1);
	else if ((ft_strcmp(argv[1],"julia") == 0))
		mlx = init_mlx(argv[1], 0, 2);
	else if ((ft_strcmp(argv[1],"burningship") == 0))
		mlx = init_mlx(argv[1], 0, 3);
	else if ((ft_strcmp(argv[1],"dulia") == 0))
		mlx = init_mlx(argv[1], 0, 4);
	else
		return (print_error());
	pthread(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_down, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, motion_hook, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
