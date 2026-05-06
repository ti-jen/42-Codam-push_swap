/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:39 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:21:39 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*store_rotate(int type)
{
	static int	array[3];
	static int	ra = 0;
	static int	rb = 0;
	static int	rr = 0;

	if (type == 1)
	{
		ft_printf("ra\n");
		ra++;
	}
	else if (type == 2)
	{
		ft_printf("rb\n");
		rb++;
	}
	else if (type == 3)
	{
		ft_printf("rr\n");
		rr++;
	}
	array[0] = ra;
	array[1] = rb;
	array[2] = rr;
	return (array);
}

static void	rotate(t_ab **lst)
{
	int		i;
	t_ab	*temp;
	t_ab	*save;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	temp = *lst;
	i = 1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	temp->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	save = temp;
	temp = temp->next;
	temp->next = NULL;
	temp->prev = save;
	fix_id(*lst);
}

void	rotate_a(t_ab **lst_a)
{
	rotate(lst_a);
	store_rotate(1);
}

void	rotate_b(t_ab **lst_b)
{
	rotate(lst_b);
	store_rotate(2);
}

void	rotate_ab(t_ab **lst_a, t_ab **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	store_rotate(3);
}
