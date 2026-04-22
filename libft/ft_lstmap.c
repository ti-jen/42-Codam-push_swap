/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:45:53 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 13:26:30 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	new = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		temp = NULL;
		temp = f(lst->content);
		if (!temp)
			del(temp);
		if (temp)
			ft_lstadd_back(&new, ft_lstnew(temp));
		lst = lst-> next;
	}
	return (new);
}
