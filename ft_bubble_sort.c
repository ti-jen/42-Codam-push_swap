/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:56:01 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/06 12:48:32 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void ft_bubble_sort(t_ab **lst)
{
	t_ab *val1;
	t_ab *val2;
	t_ab *tmp;
	int save_val;
	int val_change;
	
	val_change = 1;
	val1 = *lst;
	val2 = val1->next;
	
	tmp = *lst;
	while (val_change != 0)
	{
		val_change = 0;
		val1 = *lst;
		val2 = val1->next;

		while(val2->next != NULL)
		{
			if (val1->content > val2->content)
			{
				swap_a(lst, 1);
				val_change = 1;
			}
			val1 = val1->next;
			val2 = val1->next;
		}
	}
	tmp = *lst;
	while(tmp->next != NULL)
	{
		printf("id:%d content:%d\n", tmp->id, tmp->content);
		tmp = tmp -> next;
	}
	printf("runs:%d\n", runs);
	
}
