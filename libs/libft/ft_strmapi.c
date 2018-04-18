/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:15:09 by lilam             #+#    #+#             */
/*   Updated: 2017/12/01 19:23:34 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!(s && f))
		return (NULL);
	i = -1;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str)
	{
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
	}
	return (str);
}
