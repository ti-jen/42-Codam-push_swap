/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:25 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:27 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "lib_push_swap.h"
# include "libft/ft_printf/ft_printf.h"

void	fixId(lst_ab *A)
{
	int i;

	if(!A)
		return;
	i = 0;
	A->id = i;
	while(A->next)
	{
		A = A->next;
		i++;
		A->id = i;
	}
}

static void push (lst_ab **A,	lst_ab **B)
{
	lst_ab *temp;

	if (!*A)
		return ;
	temp = *B;
	*B = *A;
	*A = (*A) ->next;
	if (temp)
		(*B) ->next = temp;
	else
		(*B) ->next = NULL;
	fixId(*B);
	fixId(*A);
	return ;
}

void push_a (lst_ab **A,	lst_ab **B)
{
	push(A,B);
	ft_printf("pa\n");
}

void push_b (lst_ab **A,	lst_ab **B)
{
	push(B,A);
	ft_printf("pb\n");
}
