/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 05:46:45 by linh              #+#    #+#             */
/*   Updated: 2017/12/03 16:55:11 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (!(new->next))
			return (NULL);
		new = new->next;
	}
	return (tmp);
}
