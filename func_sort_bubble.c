/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:35:35 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/06/03 15:48:02 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	go_to_loc(t_ab **lst, t_ab *lst_loc)
{
	int	loc;
	int	id;
	int	num_items;

	loc = lst_loc->content;
	id = lst_loc->id;
	num_items = num_items_lst(*lst);
	if (num_items % 2 == 1)
		num_items++;
	while ((*lst)->content != loc)
	{
		if (id < num_items / 2)
			rotate_a(lst);
		else
			reverse_rotate_a(lst);
	}
}

t_ab	*find_min(t_ab *lst)
{
	t_ab	*tmp;
	int		lowest;

	lowest = find_max(lst)->content;
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (1)
	{
		if (lst->content < lowest)
		{
			lowest = lst->content;
			tmp = lst;
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (tmp);
}
