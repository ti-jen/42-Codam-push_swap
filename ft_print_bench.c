/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:12:43 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:39:55 by tkroon           ###   ########.fr       */
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

void	print_actions(void)
{
	int	l[11];
	int	i;
	int	total;

	total = 0;
	i = 11;
	l[0] = store_swap(0)[0];
	l[1] = store_swap(0)[1];
	l[2] = store_swap(0)[2];
	l[3] = store_push(0)[0];
	l[4] = store_push(0)[1];
	l[5] = store_rotate(0)[0];
	l[6] = store_rotate(0)[1];
	l[7] = store_rotate(0)[2];
	l[8] = store_rev_rotate(0)[0];
	l[9] = store_rev_rotate(0)[1];
	l[10] = store_rev_rotate(0)[2];
	while (i--)
		total = total + l[i];
	ft_printf("%i\n", total);
	ft_printf("[bench] sa: %i sb: %i ss: %i ", l[0], l[1], l[2]);
	ft_printf("pa: %i pb: %i\n", l[3], l[4]);
	ft_printf("[bench] ra: %i rb: %i rr: %i ", l[5], l[6], l[7]);
	ft_printf("rra: %i rrb: %i rrr: %i\n", l[8], l[9], l[10]);
}

void	ft_print_bench(int algorithm, double dis, bool bench)
{
	int	chunk;

	if (!bench)
		return ;
	ft_printf("[bench] disorder:	");
	chunk = dis * 10000;
	ft_printf("%i.", chunk / 100);
	ft_printf("%i%%", chunk % 100);
	ft_printf("\n[bench] strategy:	");
	print_algorithm(algorithm, dis);
	ft_printf("[bench] total_ops: ");
	print_actions();
	ft_printf("\n");
}
