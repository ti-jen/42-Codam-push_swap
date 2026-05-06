/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:50:58 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 12:43:55 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

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

int	shortest_path(t_ab *lst_a, int max, int min)
{
	int	rot;
	int	rev;

	rot = 0;
	rev = 1;
	while (!(lst_a->content <= max && lst_a->content > min))
		lst_a = lst_a->next;
	rot = lst_a->id;
	while (lst_a->next)
		lst_a = lst_a->next;
	while (!(lst_a->content <= max && lst_a->content > min))
	{
		rev++;
		lst_a = lst_a->prev;
	}
	if (rot < rev)
		return (rot);
	else
		return (rev = -rev);
}