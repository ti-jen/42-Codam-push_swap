/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:51:22 by wouter            #+#    #+#             */
/*   Updated: 2026/05/14 16:42:31 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	finish_list(t_ab **lst_a, t_ab **lst_b);
t_ab	*find_max(t_ab *lst);
t_ab	*find_min(t_ab *lst, int highest);
void	push_select(t_ab **lst_a, t_ab **lst_b, t_ab *push_value);
int		num_items_lst(t_ab *lst);

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
		push_select(&lst_a, &lst_b, find_min(lst_a, highest));
		if (!lst_a)
			break ;
		push_select(&lst_a, &lst_b, find_max(lst_a));
		rotate_b(&lst_b);
	}
	finish_list(&lst_a, &lst_b);
}
