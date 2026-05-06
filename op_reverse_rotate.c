/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:32 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:58:59 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*store_rev_rotate(int type)
{
	static int	array[3];
	static int	rra = 0;
	static int	rrb = 0;
	static int	rrr = 0;

	if (type == 1)
	{
		write(1, "rra\n", 4);
		rra++;
	}
	else if (type == 2)
	{
		write(1, "rrb\n", 4);
		rrb++;
	}
	else if (type == 3)
	{
		write(1, "rrb\n", 4);
		rrr++;
	}
	array[0] = rra;
	array[1] = rrb;
	array[2] = rrr;
	return (array);
}

static void	reverse_rotate(t_ab **lst_a)
{
	t_ab	*temp;
	t_ab	*save;

	if (!lst_a || !(*lst_a) || !(*lst_a)->next)
		return ;
	temp = *lst_a;
	while ((*lst_a)->next)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = temp;
	save = temp;
	temp = (*lst_a)->prev;
	temp->next = NULL;
	save->prev = (*lst_a);
	(*lst_a)->prev = NULL;
	fix_id (*lst_a);
}

void	reverse_rotate_a(t_ab **lst_a)
{
	reverse_rotate(lst_a);
	store_rev_rotate(1);
}

void	reverse_rotate_b(t_ab **lst_a)
{
	reverse_rotate(lst_a);
	store_rev_rotate(2);
}

void	reverse_rotate_ab(t_ab **lst_a, t_ab **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	store_rev_rotate(3);
}
