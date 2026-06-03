/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:25 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/28 15:41:57 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*store_push(int type, bool isprint)
{
	static int	array[2];
	static int	pa = 0;
	static int	pb = 0;
	static bool	print = true;

	if (print && !isprint)
		print = false ;
	if (print && type == 1)
		write(1, "pa\n", 3);
	else if (print && type == 2)
		write(1, "pb\n", 3);
	if (type == 1)
		pa++;
	else if (type == 2)
		pb++;
	array[0] = pa;
	array[1] = pb;
	return (array);
}

void	fix_id(t_ab *lst)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	lst->id = i;
	while (lst->next)
	{
		lst = lst->next;
		i++;
		lst->id = i;
	}
}

static void	push(t_ab **lst_a,	t_ab **lst_b)
{
	t_ab	*temp;

	if (!lst_a || !*lst_a)
		return ;
	temp = *lst_b;
	*lst_b = *lst_a;
	*lst_a = (*lst_a)->next;
	if (*lst_a)
		(*lst_a)->prev = NULL;
	if (temp)
	{
		(*lst_b)->next = temp;
		temp ->prev = (*lst_b);
	}
	else
		(*lst_b)->next = NULL;
	fix_id(*lst_b);
	fix_id(*lst_a);
	return ;
}

void	push_a(t_ab **lst_a, t_ab **lst_b)
{
	push(lst_b, lst_a);
	store_push(1, true);
}

void	push_b(t_ab **lst_a, t_ab **lst_b)
{
	push(lst_a, lst_b);
	store_push(2, true);
}
