/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:25 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/30 17:51:07 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdbool.h>

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

int	push_a(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	static int	count = 0;

	push(lst_b, lst_a);
	count++;
	if (!bench)
		ft_printf("pa\n");
	return (count);
}

int	push_b(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	static int	count = 0;

	push(lst_a, lst_b);
	count++;
	if (!bench)
		ft_printf("pb\n");
	return (count);
}
