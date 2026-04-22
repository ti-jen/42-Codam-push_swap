/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:45 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:47 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "lib_push_swap.h"
# include "libft/ft_printf/ft_printf.h"

static void swap (lst_ab **A)
{
	lst_ab *temp;
	int save;

	if (!*A || !(*A) -> next)
		return ;
	temp = (*A)-> next;
	save = (*A)-> content;
	(*A)-> content = temp->content;
	temp->content = save;
}

void swap_a (lst_ab **A)
{
	swap(A);
	ft_printf("sa\n");
	return ;
}

void swap_b (lst_ab **B)
{
	swap(B);
	ft_printf("sb\n");
	return ;
}

void swap_ab (lst_ab **A, lst_ab **B)
{
	swap(A);
	swap(B);
	ft_printf("ss\n");
	return ;
}