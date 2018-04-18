/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 01:45:57 by lilam             #+#    #+#             */
/*   Updated: 2017/11/29 02:03:10 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		i;

	temp = (char*)malloc(sizeof(*temp) * (ft_strlen(s1) + 1));
	i = -1;
	if (temp)
	{
		while (s1[++i])
			temp[i] = s1[i];
		temp[i] = '\0';
	}
	return (temp);
}
