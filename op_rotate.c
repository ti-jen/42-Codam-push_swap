/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:39 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 12:55:07 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

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

int	rotate_a(t_ab **lst_a, bool bench)
{
	static int	count = 0;

	rotate(lst_a);
	count++;
	if (!bench)
		ft_printf("ra\n");
	return (count);
}

int	rotate_b(t_ab **lst_b, bool bench)
{
	static int	count = 0;

	rotate(lst_b);
	count++;
	if (!bench)
		ft_printf("rb\n");
	return (count);
}

int	rotate_ab(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	static int	count = 0;

	rotate(lst_a);
	rotate(lst_b);
	count ++;
	if (!bench)
		ft_printf("rr\n");
	return (count);
}

void	rotate_op(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	t_ab *temp;
	if (!lst_b || !(*lst_b) || !(*lst_b)->next)
	{
		rotate_a(lst_a, bench);
		return ;
	}
	temp  = ft_find_higest(*lst_b);
	if((*lst_b)->content == temp->content)
		rotate_a(lst_a, bench);
	else
		rotate_ab(lst_a, lst_b, bench);
}