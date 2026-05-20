/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:19:46 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/20 13:47:40 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

// static int	ft_scan(t_ab *lst_a, int max, int amount)
// {
// 	int		high;
// 	t_ab	*temp;
// 	t_ab	*bucket;

// 	bucket = NULL;
// 	while (amount-- && !(high == -2147483648))
// 	{
// 		temp = lst_a;
// 		high = -2147483648;
// 		while (temp)
// 		{
// 			if (!check_dub(bucket, temp->content)
// 				&& temp->content > high && temp->content < max)
// 				high = temp->content;
// 			temp = temp->next;
// 		}
// 		ft_intadd_back(&bucket, high);
// 	}
// 	high = ft_find_higlow(bucket, false)->content;
// 	bucket = free_lst(bucket);
// 	return (high);
// }

static void	sort_simple(t_ab **lst_a, t_ab **lst_b)
{
	int		maxid;
	int		length;
	t_ab	*temp;

	temp = *lst_b;
	while (temp->next)
		temp = temp->next;
	length = temp->id;
	while (*lst_b)
	{
		maxid = ft_find_higlow(*lst_b, true)->id;
		if (maxid <= (length / 2))
		{
			while (maxid--)
				rotate_b(lst_b);
		}
		else
		{
			while (maxid++ <= length)
				reverse_rotate_b(lst_b);
		}
		push_a(lst_a, lst_b);
		length--;
	}
}

static int	bucket_size(t_ab *lst_a)
{
	int	size;

	while (lst_a->next)
		lst_a = lst_a->next;
	size = lst_a->id / 10;
	if (size > 10)
		return (size);
	else
		return (10);
}

static int	sort_medium(t_ab **lst_a, t_ab **lst_b, int max)
{
	int		scan;
	int		min;
	int		lowest;

	min = max;
	lowest = ft_find_higlow(*lst_a, false)->content;
	scan = 0;
	min = max - bucket_size(*lst_a);
	while (shortest_path(lst_a, max, min, -1))
		push_b(lst_a, lst_b);
	return (min);
}

void	ft_bucket_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	int		max;

	lst_b = NULL;
	max = ft_find_higlow(lst_a, true)->content;
	while (!(checkorder(lst_a)))
	{
		while (lst_a->next)
			max = sort_medium(&lst_a, &lst_b, max - 1);
		sort_simple(&lst_a, &lst_b);
	}
}
