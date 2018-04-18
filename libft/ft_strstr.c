/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:16:38 by lilam             #+#    #+#             */
/*   Updated: 2017/11/29 22:52:38 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int little_length;

	i = 0;
	little_length = 0;
	if (!*little)
		return ((char*)big);
	while (little[little_length])
		little_length++;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == little_length)
			return ((char*)(big + i));
		i++;
	}
	return (0);
}
