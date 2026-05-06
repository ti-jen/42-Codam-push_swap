/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:34:38 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 13:35:00 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "lib_push_swap.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct int_list
{
	int				id;
	struct int_list	*prev;
	int				content;
	struct int_list	*next;
}	t_ab;

void	fix_id(t_ab *A);
void	ft_make_lst(t_ab **lst, int i, int argc, char **argv);
int		swap_a(t_ab **A, bool bench);
int		swap_b(t_ab **A, bool bench);
int		swap_ab(t_ab **A, t_ab **B, bool bench);
int		push_a(t_ab **A,	t_ab **B, bool bench);
int		push_b(t_ab **A,	t_ab **B, bool bench);
int		rotate_a(t_ab **A, bool bench);
int		rotate_b(t_ab **A, bool bench);
int		rotate_ab(t_ab **A, t_ab **B, bool bench);
void	rotate_op(t_ab **lst_a, t_ab **lst_b, bool bench);
int		reverse_rotate_a(t_ab **A, bool bench);
int		reverse_rotate_b(t_ab **A, bool bench);
int		reverse_rotate_ab(t_ab **A, t_ab **B, bool bench);
void	reverse_rotate_op(t_ab **A, t_ab **B, bool bench);
void	ft_print_bench(int algorithm, double dis, bool bench);
void	ft_bucket_sort(t_ab *lst, bool bench);

t_ab	*ft_find_higest(t_ab *lst_a);
int		shortest_path(t_ab *lst_a, int max, int min);
void	ft_lstprint(t_ab *A, t_ab *B);

#endif