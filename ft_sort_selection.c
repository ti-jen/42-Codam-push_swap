/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:51:22 by wouter            #+#    #+#             */
/*   Updated: 2026/05/20 15:46:25 by tkroon           ###   ########.fr       */
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
