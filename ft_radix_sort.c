/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:08:33 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/12 18:23:31 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_push_a(t_ab **lst_a, t_ab **lst_b, int max, int sub)
{
	int	numb;

	numb = max;
	while (*lst_b)
	{
		while (!shortest_path(lst_b, numb, numb - sub, 1))
		{
			numb = numb - sub;
		}
		while (*lst_b && shortest_path(lst_b, numb, numb - sub, 1))
			push_a(lst_a, lst_b);
	}
}

void	ft_push_b(t_ab **lst_a, t_ab **lst_b, int min, int sub)
{
	int	numb;

	numb = min;
	while (*lst_a)
	{
		while (!shortest_path(lst_a, numb, min, -1))
		{
			numb = numb + sub;
		}
		while (*lst_a && shortest_path(lst_a, numb, min, -1))
			push_b(lst_a, lst_b);
	}
}

void	ft_simple_sort(t_ab **lst_a, t_ab **lst_b)
{
	int	high;

	while (*lst_b)
	{
		high = ft_find_higest(*lst_b)->content;
		shortest_path(lst_b, high, high - 1, 1);
		push_a(lst_a, lst_b);
	}
}

int	roundup(int numb, bool ismin)
{
	int	max;

	max = 1;
	while (numb / max)
		max = max * 10;
	if (numb < 0)
	{
		if (ismin)
			return (-max);
		else
			return (0);
	}
	if (ismin)
		return (0);
	else
		return (max);
}

void	ft_radix_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	int		max;
	int		min;
	int		sub;

	lst_b = NULL;
	max = roundup(ft_find_higest(lst_a)->content, false);
	min = roundup(ft_find_lowest(lst_a)->content, true);
	if (max > -min)
		sub = max / 10;
	else
		sub = -min / 10;
	while (sub && !checkorder(lst_a))
	{
		ft_push_b(&lst_a, &lst_b, min, sub);
		sub = sub / 10;
		if (sub <= 1)
		{
			ft_simple_sort(&lst_a, &lst_b);
			break ;
		}
		ft_push_a(&lst_a, &lst_b, max, sub);
		sub = sub / 10;
	}
}
