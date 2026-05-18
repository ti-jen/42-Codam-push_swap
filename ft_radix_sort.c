/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:08:33 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/18 13:02:59 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	getnumb(int numb, int mult, bool ispostive)
{
	while (0 < mult--)
	{
		numb = numb / 10;
	}
	if (ispostive && numb < 0)
		numb = -numb;
	return (numb);
}

int	ft_lst_size(t_ab *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->id);
}

void	ft_push_a(t_ab **lst_a, t_ab **lst_b, int mult)
{
	t_ab	*high;
	t_ab	*temp;
	int		mid;
	int		rhigh;
	int		rtemp;

	while (*lst_b)
	{
		temp = *lst_b;
		high = temp;
		mid = ft_lst_size(*lst_b) / 2;
		while (temp)
		{
			rhigh = getnumb(high->content, mult, false);
			rtemp = getnumb(temp->content, mult, false);
			if ((rhigh < rtemp)
				|| (rhigh <= rtemp && (mid - getnumb(high->id, 0, true))
					< (mid - getnumb(temp->id, 0, true))))
				high = temp;
			temp = temp->next;
		}
		shortest_path(lst_b, high->content, high->content, 1);
		push_a(lst_a, lst_b);
	}
}

void	ft_push_b(t_ab **lst_a, t_ab **lst_b, int mult)
{
	t_ab	*high;
	t_ab	*temp;
	int		mid;
	int		rhigh;
	int		rtemp;

	while (*lst_a)
	{
		temp = *lst_a;
		high = temp;
		mid = ft_lst_size(*lst_a) / 2;
		while (temp)
		{
			rhigh = getnumb(high->content, mult, false);
			rtemp = getnumb(temp->content, mult, false);
			if ((rhigh > rtemp)
				|| (rhigh >= rtemp && (mid - getnumb(high->id, 0, true))
					< (mid - getnumb(temp->id, 0, true))))
				high = temp;
			temp = temp->next;
		}
		shortest_path(lst_a, high->content, high->content, -1);
		push_b(lst_a, lst_b);
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
	while (!checkorder(lst_a))
	{
		while (checkorder_f(lst_a, getnumb, mult))
			mult--;
		ft_push_b(&lst_a, &lst_b, mult--);
		ft_push_a(&lst_a, &lst_b, mult--);
	}
}
