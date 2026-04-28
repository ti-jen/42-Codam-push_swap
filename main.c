/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/28 18:07:43 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "lib_push_swap.h"

double	compute_disorder(t_ab *lst)
{
	double	mistakes;
	double	total_pairs;
	t_ab	*temp;

	mistakes = 0;
	total_pairs = 0;
	while (lst->next)
	{
		temp = lst->next;
		while (temp)
		{
			if (lst->content > temp->content)
				mistakes++;
			total_pairs++;
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (mistakes / total_pairs);
}

int	main(int argc, char *argv[])
{
	t_ab	*lst_a;
	bool	bench;
	int		i;
	int		algorithm;

	algorithm = 0;
	i = 1;
	bench = false;
	lst_a = NULL;
	if (!ft_strncmp(argv[i], "--bench", 10))
	{
		bench = true;
		i++;
	}
	if (!ft_strncmp(argv[i], "--", 2))
	{
		if (!ft_strncmp(argv[i], "--simple", 10))
			algorithm = 1;
		else if (!ft_strncmp(argv[i], "--medium", 10))
			algorithm = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			algorithm = 3;
		else if (ft_strncmp(argv[i], "--adaptive", 10))
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	lst_a = ft_make_lst(i, argc, argv);
	if (bench)
	{
		printf("[bench] disorder:	%f%%\n", compute_disorder(lst_a));
		printf("[bench] strategy:	%i\n", algorithm);
	}
	ft_lstprint(lst_a, NULL);
}
	// if (bench)
	// {
	// 	printf("[bench] total_ops:	%i\n", (swap_a(&A, bench) + swap_b(&B, bench) + swap_ab(&A, &B, bench) + push_a(&A, &B, bench) + push_b(&A, &B, bench) +
	// 		rotate_a(&A, bench) + rotate_b(&B, bench) + rotate_ab(&A, &B, bench) + reverse_rotate_a(&A, bench) + reverse_rotate_b(&B, bench) + reverse_rotate_ab(&A, &B, bench)) - 11);
	// 	printf("[bench]	sa:	%i	sb:	%i	ss:	%i	", (swap_a(&A, bench) - 2), (swap_b(&A, bench) - 2), (swap_ab(&A, &B,bench) - 2));
	// 	printf("pa:	%i	pb:	%i\n", (push_a(&A, &B,bench) - 2), (push_b(&A, &B,bench) - 2));
	// 	printf("[bench]	ra:	%i	rb:	%i	rr:	%i	", (rotate_a(&A, bench) - 2), (rotate_b(&B, bench) - 2), (rotate_ab(&A, &B, bench) - 2));
	// 	printf("rra:	%i	rrb:	%i	rrr:	%i\n", (reverse_rotate_a(&A, bench) - 2), (reverse_rotate_b(&B, bench) - 2), (reverse_rotate_ab(&A, &B, bench) - 2));
	// }