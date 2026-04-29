/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:32 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/29 14:26:07 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

static void	reverse_rotate(t_ab **lst_a)
{
	t_ab	*temp;

	if (!lst_a || !(*lst_a) || !(*lst_a)->next)
		return ;
	temp = *lst_a;
	while ((*lst_a)->next)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = temp;
	temp = (*lst_a)->prev;
	temp->next = NULL;
	(*lst_a)->prev = NULL;
	fix_id (*lst_a);
}

int	reverse_rotate_a(t_ab **lst_a, bool bench)
{
	static int	count = 0;

	reverse_rotate(lst_a);
	count++;
	if (!bench)
		ft_printf("rra\n");
	return (count);
}

int	reverse_rotate_b(t_ab **lst_a, bool bench)
{
	static int	count = 0;

	reverse_rotate(lst_a);
	count++;
	if (!bench)
		ft_printf("rrb\n");
	return (count);
}

int	reverse_rotate_ab(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	static int	count = 0;

	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	count++;
	if (!bench)
		ft_printf("rrr\n");
	return (count);
}
