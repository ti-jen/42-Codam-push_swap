/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:50:58 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/10 11:16:42 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*ft_find_higest(t_ab *lst_a)
{
	t_ab	*temp;

	temp = lst_a;
	while (lst_a)
	{
		if (lst_a->content > temp->content)
			temp = lst_a;
		lst_a = lst_a->next;
	}
	return (temp);
}

t_ab	*ft_find_lowest(t_ab *lst_a)
{
	t_ab	*temp;

	temp = lst_a;
	while (lst_a)
	{
		if (lst_a->content < temp->content)
			temp = lst_a;
		lst_a = lst_a->next;
	}
	return (temp);
}

int	shortest_path(t_ab **lst_a, int max, int min)
{
	int		rot;
	int		rev;
	t_ab	*temp;

	rot = 0;
	rev = 1;
	temp = *lst_a;
	while (!(temp->content <= max && temp->content > min))
	{
		temp = temp->next;
		if (!temp)
			return (0);
	}
	rot = temp->id;
	while (temp->next)
		temp = temp->next;
	while (!(temp->content <= max && temp->content > min) && rev++)
		temp = temp->prev;
	if (rot < rev)
		while (rot--)
			rotate_a(lst_a);
	else
		while (rev--)
			reverse_rotate_a(lst_a);
	return (1);
}
