/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:09:40 by lilam             #+#    #+#             */
/*   Updated: 2018/04/17 22:09:59 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 750

int keys(int key, void *param);


typedef struct	s_map
{
	int			scale_factor;

}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			*img_ptr;
	int			bbp;
	int			stride;
	int			endian;
	t_map		*map;
}				t_mlx;

#endif