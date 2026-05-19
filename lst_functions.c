/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:50:58 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/19 11:59:16 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*ft_find_higlow(t_ab *lst_a, bool ishigh)
{
	t_ab	*temp;

	temp = lst_a;
	while (lst_a)
	{
		if (ishigh)
		{
			if (lst_a->content > temp->content)
				temp = lst_a;
		}
		else
			if (lst_a->content < temp->content)
				temp = lst_a;
		lst_a = lst_a->next;
	}
	return (temp);
}

int	checkorder_f(t_ab *lst_a, int (*f)(int, int, bool), int mult)
{
	t_ab	*temp;

	temp = lst_a;
	while (lst_a->next)
	{
		temp = lst_a->next;
		if (f(lst_a->content, mult, false) > f(temp->content, mult, false))
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

static void	mulrotate(t_ab **lst, int op, int dir)
{
	if (op < 0)
	{
		if (dir < 0)
			rotate_a(lst);
		else
			reverse_rotate_a(lst);
	}
	else
	{
		if (dir < 0)
			rotate_b(lst);
		else
			reverse_rotate_b(lst);
	}
}

int	shortest_path(t_ab **lst_a, int max, int min, int dir)
{
	int		rot;
	int		rev;
	t_ab	*temp;

	rot = 0;
	rev = 1;
	temp = *lst_a;
	while (!(temp->content <= max && temp->content >= min))
	{
		temp = temp->next;
		if (!temp)
			return (0);
	}
	rot = temp->id;
	while (temp->next)
		temp = temp->next;
	while (rot && !(temp->content <= max && temp->content >= min) && rev++)
		temp = temp->prev;
	if (rot < rev)
		while (rot--)
			mulrotate(lst_a, dir, -1);
	else
		while (rev--)
			mulrotate(lst_a, dir, 1);
	return (1);
}

int	checkorder(t_ab *lst_a)
{
	t_ab	*temp;

	temp = lst_a;
	while (lst_a->next)
	{
		temp = lst_a->next;
		if (lst_a->content > temp->content)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}
