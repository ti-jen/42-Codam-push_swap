/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:39 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/28 18:10:47 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

static void	rotate(t_ab **lst)
{
	int		i;
	t_ab	*temp;
	t_ab	*save;

	temp = *lst;
	if (!(*lst) || !(*lst)->next)
		return ;
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
