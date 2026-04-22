/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:32 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:34 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "lib_push_swap.h"
# include "libft/ft_printf/ft_printf.h"

static void	reverse_rotate (lst_ab **A)
{
	lst_ab *temp;
	temp = *A;

	while((*A)->next)
		*A = (*A)->next;
	(*A)->next = temp;
	temp = (*A)->prev;
	(*A)->prev = NULL;
	temp->next = NULL;
	fixId(*A);
}

void reverse_rotate_a (lst_ab **A)
{
	reverse_rotate(A);
	ft_printf("rra\n");
}

void reverse_rotate_b (lst_ab **A)
{
	reverse_rotate(A);
	ft_printf("rrb\n");
}

void reverse_rotate_ab (lst_ab **A, lst_ab **B)
{
	reverse_rotate(A);
	reverse_rotate(B);
	ft_printf("rrr\n");
}