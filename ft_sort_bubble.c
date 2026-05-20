/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:56:01 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/20 16:15:39 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_bubble_sort(t_ab *lst)
{
	int	change;
	int	num_items;

	change = 1;
	num_items = num_items_lst(lst);
	if (nasty_cases(lst) != NULL)
	{
		go_to_loc(&lst, nasty_cases(lst));
		swap_a(&lst);
	}
	if (nasty_cases2(lst) != NULL)
	{
		go_to_loc(&lst, nasty_cases2(lst));
		swap_a(&lst);
	}
	while (change != 0)
		bubble_pairs(&lst, num_items, &change);
}

void	bubble_pairs(t_ab **lst, int num_items, int *change)
{
	int	i;

	i = 0;
	*change = 0;
	if (num_items % 2 == 1)
		num_items++;
	while (i < num_items)
	{
		if (checkorder_sp(*lst)->content != find_min(*lst)->content)
		{
			go_to_loc(lst, checkorder_sp(*lst));
			swap_a(lst);
			*change = 1;
		}
		else
		{
			return_to_low(lst);
			*change = 0;
			break ;
		}
		i++;
	}
}

t_ab	*checkorder_sp(t_ab *lst)
{
	t_ab	*lowest;
	t_ab	*tmp;
	t_ab	*cont;

	lowest = find_min(lst);
	tmp = lowest;
	while (1)
	{
		cont = tmp;
		if (tmp->next == NULL)
			tmp = lst;
		else
			tmp = tmp->next;
		if (tmp->content == lowest->content)
			break ;
		if (cont->content > tmp->content)
			return (cont);
	}
	return (lowest);
}

t_ab	*closest_error(t_ab *lst)
{
	t_ab	*tmp;
	t_ab	*save;

	tmp = lst;
	while (1)
	{
		save = tmp;
		if (tmp->next == NULL)
			tmp = lst;
		else
			tmp = tmp->next;
		if (save->content > tmp->content && tmp->content)
			return (save);
	}
}

void	return_to_low(t_ab **lst)
{
	int	lowest;
	int	id;
	int	num_items;

	lowest = find_min(*lst)->content;
	id = find_min(*lst)->id;
	num_items = num_items_lst(*lst);
	while ((*lst)->content != lowest)
	{
		if (id < num_items / 2)
			rotate_a(lst);
		else
			reverse_rotate_a(lst);
	}
}
