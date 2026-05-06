/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:45 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 17:00:47 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*store_swap(int type)
{
	static int	array[3];
	static int	sa = 0;
	static int	sb = 0;
	static int	ss = 0;

	if (type == 1)
	{
		write(1, "sa\n", 3);
		sa++;
	}
	else if (type == 2)
	{
		write(1, "sb\n", 3);
		sb++;
	}
	else if (type == 3)
	{
		write(1, "ss\n", 3);
		ss++;
	}
	array[0] = sa;
	array[1] = sb;
	array[1] = ss;
	return (array);
}

static void	swap(t_ab **lst)
{
	t_ab	*temp;
	int		save;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)-> next;
	save = (*lst)-> content;
	(*lst)-> content = temp->content;
	temp->content = save;
}

void	swap_a(t_ab **lst_a)
{
	swap(lst_a);
	store_swap(1);
}

void	swap_b(t_ab **lst_b)
{
	swap(lst_b);
	store_swap(2);
}

void	swap_ab(t_ab **lst_a, t_ab **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	store_swap(3);
}
