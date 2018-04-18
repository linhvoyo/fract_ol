/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:20:06 by lilam             #+#    #+#             */
/*   Updated: 2017/12/04 17:07:11 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t little_length;

	i = 0;
	little_length = 0;
	if (!*little)
		return ((char*)big);
	while (little[little_length] && little_length <= len)
		little_length++;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (j == little_length)
			return ((char*)(big + i));
		i++;
	}
	return (0);
}
