/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:51:22 by wouter            #+#    #+#             */
/*   Updated: 2026/05/12 14:51:42 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void finish_list(t_ab **lst_a, t_ab **lst_b);
t_ab   *find_max(t_ab *lst);
t_ab   *find_min(t_ab *lst, int highest);
void push_select(t_ab **lst_a, t_ab **lst_b, t_ab *push_value);
int num_items_lst(t_ab *lst);

void	ft_selection_sort(t_ab *lst_a)
{
	t_ab *lst_b;
	int highest;
	int i;
	
	lst_b = NULL;
	i =0;
	while (lst_a)
	{
		highest = find_max(lst_a)->content;
		push_select(&lst_a,&lst_b, find_min(lst_a, highest));
		if(!lst_a)
			break;
		push_select(&lst_a,&lst_b, find_max(lst_a));
		rotate_b(&lst_b);
		i++;
	}
	finish_list(&lst_a,&lst_b);


	//ft_lstprint(lst_a, lst_b);
}

t_ab   *find_max(t_ab *lst)
{
	t_ab *tmp;
	int highest;
	
	highest = 0;
	if (!lst)
	 	return(NULL);
	if (lst->next == NULL)
	 	return(lst);
	while(1)
	{
		if (lst->content > highest)
		{
			highest = lst->content;
			tmp = lst;
		}
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
	return(tmp);
}


t_ab   *find_min(t_ab *lst, int highest)
{
	t_ab *tmp;
	int lowest;
	
	lowest = highest;
	if (!lst)
	 	return(NULL);
	if (lst->next == NULL)
	 	return(lst);
	while(1)
	{
		if (lst->content < lowest)
		{
			lowest = lst->content;
			tmp = lst;
		}
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
	return(tmp);
}

void push_select(t_ab **lst_a, t_ab **lst_b, t_ab *push_value)
{
	int num_items;
	int highest;
	int location;
	
	num_items = num_items_lst(*lst_a);
	location = push_value->id;
	highest = push_value->content;
	while(1)
	{
		if ((*lst_a)->content == highest)
		{
			push_b(lst_a,lst_b);
			break;
		}
		
		if (location < 2/ num_items)
			rotate_a(lst_a);
		else
			reverse_rotate_a(lst_a);
	}
}

int num_items_lst(t_ab *lst)
{
	int i;

	i = 0;
	if (!lst)
			return(0);
	while (1)
	{
		if (lst->next == NULL)
			break;
		lst = lst->next;
		i++;	
	}
	return(i);
}


void finish_list(t_ab **lst_a, t_ab **lst_b)
{
	int lowest;
	while (*lst_b)
		push_b(lst_b, lst_a);
	
	lowest = find_min(*lst_a, find_max(*lst_a)->content)-> content;
	while(1)
	{
		if ((*lst_a)->content == lowest)
			break;
		reverse_rotate_a(lst_a);
	}
}


