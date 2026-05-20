/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:34:38 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/20 14:51:51 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

// # include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
// # include <stdlib.h>
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
int		*store_swap(int type);
void	swap_a(t_ab **A);
void	swap_b(t_ab **A);
void	swap_ab(t_ab **A, t_ab **B);
int		*store_push(int type);
void	push_a(t_ab **A,	t_ab **B);
void	push_b(t_ab **A,	t_ab **B);
int		*store_rotate(int type);
void	rotate_a(t_ab **A);
void	rotate_b(t_ab **A);
void	rotate_ab(t_ab **A, t_ab **B);
int		*store_rev_rotate(int type);
void	reverse_rotate_a(t_ab **A);
void	reverse_rotate_b(t_ab **A);
void	reverse_rotate_ab(t_ab **A, t_ab **B);
void	ft_print_bench(int algorithm, double dis, bool bench);
void	ft_selection_sort(t_ab *lst_a);
void	ft_bucket_sort(t_ab *lst);
void	ft_radix_sort(t_ab *lst_a);
t_ab	*ft_find_higlow(t_ab *lst_a, bool ishigh);
int		check_dub(t_ab *lst, int content);
void	ft_intadd_back(t_ab **lst, int content);
t_ab	*free_lst(t_ab *lst);
int		shortest_path(t_ab **lst_a, int max, int min, int dir);
void	ft_lstprint(t_ab *A, t_ab *B);
int		checkorder(t_ab *lst_a);
int		checkorder_f(t_ab *lst_a, int (*f)(int, int, bool), int mult);
void	finish_list(t_ab **lst_a, t_ab **lst_b);
t_ab	*find_max(t_ab *lst);
t_ab	*find_min(t_ab *lst);
void	push_select(t_ab **lst_a, t_ab **lst_b, t_ab *push_value);
int		num_items_lst(t_ab *lst);
t_ab	*cleanlist(t_ab *lst);
void	return_to_low(t_ab **lst);
void	bubble_pairs(t_ab **lst, int num_items, int *change);
t_ab	*checkorder_sp(t_ab *lst);
void	go_to_loc(t_ab **lst, t_ab *lst_loc);
t_ab	*closest_error(t_ab *lst);
t_ab	*nasty_cases(t_ab *lst);
t_ab	*nasty_cases2(t_ab *lst);
void	ft_bubble_sort(t_ab *lst);
t_ab	*find_value(int i, t_ab *list);

#endif