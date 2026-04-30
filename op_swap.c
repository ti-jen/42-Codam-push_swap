/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:45 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/30 15:07:41 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

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
