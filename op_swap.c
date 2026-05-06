/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:45 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 12:55:17 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

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

int	swap_a(t_ab **lst_a, bool bench)
{
	static int	count = 0;

	swap(lst_a);
	count++;
	if (!bench)
		ft_printf("sa\n");
	return (count);
}

int	swap_b(t_ab **lst_b, bool bench)
{
	static int	count = 0;

	swap(lst_b);
	count++;
	if (!bench)
		ft_printf("sb\n");
	return (count);
}

int	swap_ab(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	static int	count = 0;

	swap(lst_a);
	swap(lst_b);
	count++;
	if (!bench)
		ft_printf("ss\n");
	return (count);
}
