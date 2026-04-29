/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:34:38 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/29 16:42:18 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

typedef struct int_list
{
	int				id;
	struct int_list	*prev;
	int				content;
	struct int_list	*next;
}	t_ab;

void	fix_id(t_ab *A);
t_ab	*ft_make_lst(int i, int argc, char **argv);
int		swap_a(t_ab **A, bool bench);
int		swap_b(t_ab **A, bool bench);
int		swap_ab(t_ab **A, t_ab **B, bool bench);
int		push_a(t_ab **A,	t_ab **B, bool bench);
int		push_b(t_ab **A,	t_ab **B, bool bench);
int		rotate_a(t_ab **A, bool bench);
int		rotate_b(t_ab **A, bool bench);
int		rotate_ab(t_ab **A, t_ab **B, bool bench);
int		reverse_rotate_a(t_ab **A, bool bench);
int		reverse_rotate_b(t_ab **A, bool bench);
int		reverse_rotate_ab(t_ab **A, t_ab **B, bool bench);
void	ft_print_bench	(int algorithm, double dis, bool bench);

void	ft_lstprint(t_ab *A, t_ab *B);
