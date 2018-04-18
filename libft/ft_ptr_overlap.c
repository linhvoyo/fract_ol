/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_overlap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 06:45:51 by linh              #+#    #+#             */
/*   Updated: 2017/12/03 16:05:08 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptr_overlap(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	while (i++ <= len)
		if ((src + i == dst || (src + i == dst + len)))
			return (1);
	return (0);
}
