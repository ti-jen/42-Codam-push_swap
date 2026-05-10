/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:56:01 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/10 16:13:26 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	num_items_lst(t_ab *lst);
void	bubble_pairs(t_ab *lst, int num_items, int *change);
void	pr_lst(t_ab *lst);

void	ft_bubble_sort(t_ab *lst)
{
	int	num_items;
	int	change;
		
	num_items = num_items_lst(lst);
	change = 1;
	pr_lst(lst);
	
	while (change != 0)
		bubble_pairs(lst, num_items, &change);
}

void	bubble_pairs(t_ab *lst, int num_items, int *change)
{
	int i;
	
	i = 0;
	*change = 0;
	while (i < num_items)
	{
		if (lst->content > lst->next->content)
		{
			swap_a(&lst);
			*change = 1;
			rotate_a(&lst);
		}
		else
				rotate_a(&lst);
		i++;
	}
	rotate_a(&lst);
}

int num_items_lst(t_ab *lst)
{
	int i;

	i = 0;
	while (1)
	{
		lst = lst->next;
		if (lst->next == NULL)
			break;
		i++;	
	}
	return(i);
}

void pr_lst(t_ab *lst)
{
 	while (1)
	{
		printf("\n%d - %d - %p",lst->id, lst->content, lst->next);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
	
}
