/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:39 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:42 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "lib_push_swap.h"
# include "libft/ft_printf/ft_printf.h"

static void	rotate (lst_ab **A)
{
	int i;
	lst_ab *temp;
	temp = *A;

	i = 1;
	while(temp->next)
	{
		i++;
		temp = temp->next;
	}
	temp->id = i;
	temp->next = *A;
	*A = (*A)->next;
	(*A)->prev = NULL;
	temp = temp->next;
	temp->next = NULL;
	fixId(*A);
}

void rotate_a (lst_ab **A)
{
	rotate(A);
	ft_printf("ra\n");
}

void rotate_b (lst_ab **A)
{
	rotate(A);
	ft_printf("rb\n");
}

void rotate_ab (lst_ab **A, lst_ab **B)
{
	rotate(A);
	rotate(B);
	ft_printf("rr\n");
}