/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:32:51 by lilam             #+#    #+#             */
/*   Updated: 2017/12/01 19:36:49 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[i])
			count++;
		i++;
	}
	return (count == i);
}
