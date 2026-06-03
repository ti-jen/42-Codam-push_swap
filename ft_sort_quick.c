/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:09:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/06/03 09:52:20 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static t_ab	*ft_lst_last(t_ab *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_super_swap(t_ab **lst_a, t_ab **lst_b)
{
	t_ab	*a_next;
	t_ab	*b_next;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	if (!*lst_b || !(*lst_b)->next)
	{
		if ((*lst_a)->next->content < (*lst_a)->content)
			swap_a(lst_a);
		return ;
	}
	a_next = (*lst_a)->next;
	b_next = (*lst_b)->next;
	if (a_next->content < (*lst_a)->content
		&& b_next->content > (*lst_b)->content)
		swap_ab(lst_a, lst_b);
	else if (a_next->content < (*lst_a)->content)
		swap_a(lst_a);
}

void	sort_quick_it(int max, int min, t_ab **lst_a, t_ab **lst_b)
{
	int	pivot;

	pivot = (max + min) / 2;
	while (shortest_path(lst_a, pivot, min, -1))
		push_b(lst_a, lst_b);
	if (pivot == min)
		return ;
	sort_quick_it(max, pivot, lst_a, lst_b);
	shortest_path(lst_a, ft_find_higlow(*lst_a, 0)->content,
		ft_find_higlow(*lst_a, 0)->content, -1);
	while (shortest_path(lst_b, max, min + 1, 1))
		push_a(lst_a, lst_b);
	if (pivot - 2 <= min)
		ft_super_swap(lst_a, lst_b);
	if (checkorder(*lst_a))
		return ;
	sort_quick_it(pivot, min, lst_a, lst_b);
}

void	ft_sort_quick(t_ab *lst_a)
{
	t_ab	*lst_b;

	lst_b = NULL;
	if (checkorder(lst_a))
		return ;
	if (num_items_lst(lst_a) < 10)
	{
		ft_bubble_sort(lst_a);
		return ;
	}
	sort_quick_it(ft_lst_last(lst_a)->id, 0, &lst_a, &lst_b);
	while (lst_b)
		push_a(&lst_a, &lst_b);
}
