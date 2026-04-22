/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/22 14:06:28 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# include "libft/libft.h"
# include "lib_push_swap.h"

void	ft_intadd_back(lst_ab **lst, int content)
{
	lst_ab *temp;
	lst_ab *new;
	static int i = 0;
	temp = *lst;

	new = (lst_ab *)malloc(sizeof(lst_ab));
	new->content = content;
	new->id = i;
	new->prev = NULL;
	new->next = NULL;
	i++;
	if (!temp)
		*lst = new;
	else
	{
		while (temp-> next)
		{
			temp = temp-> next;
		}
		new->prev = temp;
		temp->next = new;
	}
}

int main(int argc, char* argv[])
{
	lst_ab *A = NULL;
	lst_ab *B = NULL;
	int i = 1;
	while((argc) > i)
	{
		ft_intadd_back(&A, ft_atoi(argv[i]));
		i++;
	}
	// push_a(&A, &B);
	push_a(&A, &B);
	push_a(&A, &B);
	push_b(&A, &B);
	ft_lstprint(A, B);
	// // ft_sort(&A, &B);
	// ft_lstprint(A, B);
}