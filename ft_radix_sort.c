/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:08:33 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/15 10:49:57 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	getnumb(int numb, int mult)
{
	while (mult--)
	{
		numb = numb / 10;
	}
	return (numb);
}

void	ft_push_a(t_ab **lst_a, t_ab **lst_b, int mult)
{
	int		high;
	t_ab	*temp;

	temp = *lst_b;
	while (*lst_b)
	{
		temp = *lst_b;
		high = temp->content;
		while (temp)
		{
			if (getnumb(high, mult) < getnumb(temp->content, mult))
				high = temp->content;
			temp = temp->next;
		}
		shortest_path(lst_b, high, high, 1);
		push_a(lst_a, lst_b);
	}
}

void	ft_push_b(t_ab **lst_a, t_ab **lst_b, int mult)
{
	int		high;
	t_ab	*temp;

	temp = *lst_a;
	while (*lst_a)
	{
		temp = *lst_a;
		high = temp->content;
		while (temp)
		{
			if (getnumb(high, mult) > getnumb(temp->content, mult))
				high = temp->content;
			temp = temp->next;
		}
		shortest_path(lst_a, high, high, -1);
		push_b(lst_a, lst_b);
	}
}

void	ft_simple_sort(t_ab **lst_a, t_ab **lst_b)
{
	int	high;

	while (*lst_b)
	{
		high = ft_find_higest(*lst_b)->content;
		shortest_path(lst_b, high, high, 1);
		push_a(lst_a, lst_b);
	}
}

void	ft_radix_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	t_ab	*temp;
	int		mult;

	lst_b = NULL;
	mult = 9;
	temp = lst_a;
	while (getnumb(temp->content, mult) == 0)
	{
		temp = temp->next;
		if (!temp)
		{
			mult--;
			temp = lst_a;
		}
	}
	while (!checkorder(lst_a))
	{
		ft_push_b(&lst_a, &lst_b, mult);
		mult--;
		if (mult < 1)
			ft_simple_sort(&lst_a, &lst_b);
		ft_push_a(&lst_a, &lst_b, mult);
		mult--;
	}
}
