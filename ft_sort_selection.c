/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:51:22 by wouter            #+#    #+#             */
/*   Updated: 2026/05/20 15:01:19 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_selection_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	int		highest;

	lst_b = NULL;
	if (checkorder(lst_a))
		return ;
	while (lst_a)
	{
		highest = find_max(lst_a)->content;
		push_select(&lst_a, &lst_b, find_min(lst_a));
		if (!lst_a)
			break ;
		push_select(&lst_a, &lst_b, find_max(lst_a));
		rotate_b(&lst_b);
	}
	finish_list(&lst_a, &lst_b);
}