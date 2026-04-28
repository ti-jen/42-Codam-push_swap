/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:30:26 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/28 18:07:54 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lib_push_swap.h"

void	ft_lstprint(t_ab *A, t_ab *B)
{
	printf("----------------------\n");
	while (A || B)
	{
		if (A)
		{
			printf("\033[33m%i\033[0m|%d", A->id, A->content);
			A = A->next;
		}
		printf("	");
		if (B)
		{
			printf("\033[33m%i\033[0m|%d", B->id, B->content);
			B = B->next;
		}
		printf("\n");
	}
	printf("\n A	 B\n");
	printf("----------------------\n");
	return ;
}
