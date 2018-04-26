/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:09:40 by lilam             #+#    #+#             */
/*   Updated: 2018/04/26 00:08:29 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define WIDTH 1280
# define HEIGHT 800

typedef struct	s_map
{
	int			scale_factor;
	int			max_iter;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			color;
	int			fractol;
	double		zoom_inc;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_ptr;
	int			bbp;
	int			stride;
	int			endian;
	t_map		*map;
	int			start;
	int			end;
	double		mouse_x;
	double		mouse_y;
	int			error;
}				t_mlx;

t_mlx			*init_mlx(char *str, double offset_x, int fractol);
void			*mandelbrot_set(void *img);
void			*julia(void *img);
void			pthread(t_mlx *mlx);

int				key_down(int key, t_mlx *mlx);
int				mouse(int mouse, int x, int y, t_mlx *mlx);
int				motion_hook(int mouse, int x, t_mlx *mlx);
void			put_pixel(t_mlx *mlx, int x, int y, int n);
int				print(int error, t_mlx *mlx);
#endif
