/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:00:17 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/20 11:32:48 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	getnewnumb(t_ab *lst, t_ab *temp)
{
	int		numb;
	t_ab	*sort;

	numb = 0;
	sort = temp->next;
	while (1)
	{
		if (!sort)
			sort = lst;
		if (sort == temp)
			break ;
		if (temp->content > sort->content)
			numb++;
		sort = sort->next;
	}
	return (numb);
}

t_ab	*cleanlist(t_ab *lst)
{
	t_ab	*temp;
	t_ab	*new;

	new = NULL;
	temp = lst;
	while (temp)
	{
		ft_intadd_back(&new, getnewnumb(lst, temp));
		temp = temp->next;
	}
	lst = free_lst(lst);
	fix_id(new);
	return (new);
}
