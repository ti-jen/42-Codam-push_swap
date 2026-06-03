/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:19:46 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/28 18:21:01 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

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

static int	sort_medium(t_ab **lst_a, t_ab **lst_b, int max, int bucket)
{
	int		scan;
	int		min;
	int		lowest;

	min = max;
	lowest = ft_find_higlow(*lst_a, false)->content;
	scan = 0;
	max = max + bucket;
	if (max >= ft_find_higlow(*lst_a, true)->content)
	{
		while (*lst_a)
			push_b(lst_a, lst_b);
		return (max);
	}
	while (shortest_path(lst_a, max, min, -1))
		push_b(lst_a, lst_b);
	return (max);
}

int	bucket_size(int bucket)
{
	int	end;
	int	mid;
	int	start;

	start = 0;
	end = bucket;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == bucket)
			break ;
		if (mid * mid < bucket)
			start = mid + 1;
		else
			end = mid - 1;
	}
	while (mid * mid < bucket)
		mid ++;
	return (mid);
}

void	ft_bucket_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	int		max;
	int		bucket;

	lst_b = NULL;
	max = 0;
	if (num_items_lst(lst_a) < 6)
	{
		ft_bubble_sort(lst_a);
		return ;
	}
	bucket = bucket_size(ft_find_higlow(lst_a, 1)->content) * 1.5;
	while (!(checkorder(lst_a)))
	{
		while (lst_a)
			max = sort_medium(&lst_a, &lst_b, max, bucket);
		sort_simple(&lst_a, &lst_b);
	}
}
