/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort_bubble2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:13:44 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/06/03 15:49:53 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*nasty_cases(t_ab *lst)
{
	t_ab	*lowest;
	t_ab	*tmp;
	t_ab	*cont;
	int		start;

	lowest = lst;
	start = lst->content;
	tmp = lowest;
	while (1)
	{
		cont = tmp;
		if (tmp->next == NULL)
			tmp = lst;
		else
			tmp = tmp->next;
		if (cont->content == 0 && tmp->content == 4)
		{
			return (cont);
		}
		if (tmp->content == start)
			break ;
	}
	return (NULL);
}

t_ab	*nasty_cases2(t_ab *lst)
{
	int	nasty_combi[5];

	nasty_combi[0] = 0;
	nasty_combi[1] = 3;
	nasty_combi[2] = 4;
	nasty_combi[3] = 2;
	nasty_combi[4] = 1;
	return (test_nasty(nasty_combi, lst));
}

t_ab	*test_nasty(int *nasty_combi, t_ab *list)
{
	int		i;
	int		a;
	t_ab	*tmp;

	i = 0;
	a = 0;
	tmp = list;
	while (a < 6)
	{
		if (tmp->content == nasty_combi[i])
			i++;
		if (tmp->next == NULL)
			tmp = list;
		else
			tmp = tmp->next;
		if (i == 5)
			break ;
		a++;
	}
	return (find_value(i, list));
}

t_ab	*find_value(int i, t_ab *list)
{
	if (i == 5)
	{
		while (1)
		{
			if (list->content == 1)
				return (list);
			if (list->next == NULL)
				break ;
			list = list->next;
		}
	}
	return (NULL);
}
