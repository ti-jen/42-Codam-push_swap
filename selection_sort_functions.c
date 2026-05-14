/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:43:06 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/14 16:44:53 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*find_max(t_ab *lst)
{
	t_ab	*tmp;
	int		highest;

	highest = 0;
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (1)
	{
		if (lst->content > highest)
		{
			highest = lst->content;
			tmp = lst;
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (tmp);
}

t_ab	*find_min(t_ab *lst, int highest)
{
	t_ab	*tmp;
	int		lowest;

	lowest = highest;
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

void	push_select(t_ab **lst_a, t_ab **lst_b, t_ab *push_value)
{
	int	num_items;
	int	highest;
	int	location;

	num_items = num_items_lst(*lst_a);
	location = push_value->id;
	highest = push_value->content;
	while (1)
	{
		if ((*lst_a)->content == highest)
		{
			push_b(lst_a, lst_b);
			break ;
		}
		if (location < num_items / 2)
			rotate_a(lst_a);
		else
			reverse_rotate_a(lst_a);
	}
}

int	num_items_lst(t_ab *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (1)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
		i++;
	}
	return (i);
}

void	finish_list(t_ab **lst_a, t_ab **lst_b)
{
	int	lowest;

	while (*lst_b)
		push_a(lst_a, lst_b);
	lowest = find_min(*lst_a, find_max(*lst_a)->content)-> content;
	while (1)
	{
		if ((*lst_a)->content == lowest)
			break ;
		reverse_rotate_a(lst_a);
	}
}
