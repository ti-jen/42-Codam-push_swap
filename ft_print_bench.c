/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:12:43 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/29 16:12:26 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdbool.h>

void	print_algorithm(int algorithm, double dis)
{
	if (algorithm == 1)
		ft_printf("Simple / ");
	if (algorithm == 2)
		ft_printf("Medium / ");
	if (algorithm == 3)
		ft_printf("Complex / ");
	if (algorithm == 4)
	{
		ft_printf("Adapitve / ");
		if (dis < 0.2)
			algorithm = 1;
		else if (dis > 0.2 && dis < 0.5)
			algorithm = 2;
		else
			algorithm = 3;
	}
	if (algorithm == 1)
		ft_printf("O(n2\n)");
	if (algorithm == 2)
		ft_printf("O(n√n)\n");
	if (algorithm == 3)
		ft_printf("O(n log n)\n");
}

void	print_actions(int i, int action, char *name)
{
	static int	j = 0;

	j = j + (action - 1);
	i++;
	if (i == 1)
		print_actions(i, reverse_rotate_b(NULL, true), "rrb");
	if (i == 2)
		print_actions(i, reverse_rotate_a(NULL, true), "rra");
	if (i == 3)
		print_actions(i, rotate_ab(NULL, NULL, true), "rr");
	if (i == 4)
		print_actions(i, rotate_b(NULL, true), "rb");
	if (i == 5)
		print_actions(i, rotate_a(NULL, true), "ra");
	if (i == 6)
	{
		print_actions(i, push_b(NULL, NULL, true), "pb");
		ft_printf("\n[bench] ");
	}
	if (i == 7)
		print_actions(i, push_a(NULL, NULL, true), "pa");
	if (i == 8)
		print_actions(i, swap_ab(NULL, NULL, true), "ss");
	if (i == 9)
		print_actions(i, swap_b(NULL, true), "sb");
	if (i == 10)
		print_actions(i, swap_a(NULL, true), "sa");
	if (i == 11)
		ft_printf("%i\n[bench] ", j);
	ft_printf("%s: %i ", name, (action - 1));
	return ;
}

void	ft_print_bench(int algorithm, double dis)
{
	int	chunk;

	ft_printf("[bench] disorder:	");
	chunk = dis * 10000;
	ft_printf("%i.", chunk / 100);
	ft_printf("%i%%", chunk % 100);
	ft_printf("\n[bench] strategy:	");
	print_algorithm(algorithm, dis);
	ft_printf("[bench] total_ops: ");
	print_actions(0, reverse_rotate_ab(NULL, NULL, true), "rrr");
}
