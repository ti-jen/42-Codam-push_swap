/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:19:46 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/07 12:30:23 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_scan(t_ab *lst_a, int max, int min)
{
	int	count;

	count = 0;
	while (lst_a)
	{
		if (lst_a->content <= max && lst_a->content > min)
			count++;
		lst_a = lst_a->next;
	}
	return (count);
}

void	sort_simple(t_ab **lst_a, t_ab **lst_b)
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
		maxid = ft_find_higest(*lst_b)->id;
		if (maxid < (length / 2))
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

int	bucket_size(t_ab *lst_a)
{
	int size;
	while (lst_a->next)
		lst_a = lst_a->next;
	size = lst_a->id / 10;
	if (size > 10)
		return(size);
	else
		return(10);
}

int	sort_medium(t_ab **lst_a, t_ab **lst_b, int max)
{
	int		scan;
	int		path;
	int		min;
	int		lowest;

	min = max;
	lowest = ft_find_lowest(*lst_a)->content;
	scan = 0;
	while (scan < bucket_size(*lst_a) && min >= lowest)
	{
		min = min - 10;
		scan = ft_scan(*lst_a, max, min);
	}
	while (scan)
	{
		path = shortest_path(*lst_a, max, min);
		if (path < 0)
			while (path++ < 0)
				reverse_rotate_a(lst_a);
		else
			while (path-- > 0)
				rotate_a(lst_a);
		push_b(lst_a, lst_b);
		scan--;
	}
	return (min);
}

void	ft_bucket_sort(t_ab *lst_a)
{
	t_ab	*lst_b;
	int		max;
	int		path;
	bool	start;

	start = true;
	lst_b = NULL;
	max = ft_find_higest(lst_a)->content;
	path = 0;
	while (max > ft_find_lowest(lst_a)->content)
	{
		max = sort_medium(&lst_a, &lst_b, max);
		if (!start)
			path = shortest_path(lst_a, path, path - 1);
		if (path < 0)
			while (path++ < 0)
				reverse_rotate_a(&lst_a);
		else
			while (path-- > 0)
				rotate_a(&lst_a);
		if (lst_b)
			sort_simple(&lst_a, &lst_b);
		path = (lst_a)->content;
		start = false;
	}
}
