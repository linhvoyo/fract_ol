/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:17:26 by lilam             #+#    #+#             */
/*   Updated: 2017/12/03 17:38:02 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_exp(long long n, long long power)
{
	long long	res;

	res = 1;
	while (power--)
		res = res * n;
	return (res);
}

static char			*if_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static long			numstr_length(int n)
{
	long long	temp;
	long		i;

	i = 0;
	temp = AB((long long)n);
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	long		i;
	long		j;
	long long	temp;
	char		*str;

	if (n == -0 || n == 0)
		return (if_zero());
	i = numstr_length(n) - 1;
	temp = AB((long long)n);
	if (n < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	j = 0;
	if (n < 0 && i--)
		str[j++] = '-';
	while (i >= 0)
	{
		str[j++] = temp / ft_exp(10, i) + '0';
		temp = temp % ft_exp(10, i--);
	}
	str[j] = '\0';
	return (str);
}
