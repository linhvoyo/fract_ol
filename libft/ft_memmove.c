/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:15:34 by lilam             #+#    #+#             */
/*   Updated: 2017/12/04 09:48:17 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	size_t overlap;

	i = -1;
	overlap = 0;
	while (++i <= len)
		if ((src + i == dst) || (src + i == dst + len))
		{
			if (dst - src > 0)
				overlap = 1;
			break ;
		}
	if (overlap == 1)
	{
		i = len;
		while ((int)--i >= 0)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	}
	return (dst);
}
