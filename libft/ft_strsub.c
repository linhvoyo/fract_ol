/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:39:50 by lilam             #+#    #+#             */
/*   Updated: 2017/12/01 20:18:02 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!(s))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (str)
	{
		while (i < len)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
