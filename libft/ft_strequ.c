/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:25:06 by lilam             #+#    #+#             */
/*   Updated: 2017/12/04 17:04:18 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;
	int count;

	if (!(s1 && s2))
		return (0);
	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
			count++;
		i++;
	}
	return (count == i && ft_strlen(s1) == ft_strlen(s2));
}
