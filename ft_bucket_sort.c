/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:19:46 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/04 12:44:40 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

int	lstsize(t_ab *lst)
{
	int		i;
	t_ab	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_iterative_power(int nb, int power)
{
	int	ans;
	int	i;

	ans = nb;
	i = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (i < power)
	{
		ans = ans * nb;
		i++;
	}
	return (ans);
}

int ft_scan(t_ab *lst_a, int max, int min)
{
	int count = 0;
	while(lst_a)
	{
		if(lst_a->content <= max && lst_a->content > min)
			count++;
		lst_a = lst_a->next;
	}
	return (count);
}

t_ab *ft_find_higest(t_ab *lst_a)
{
	t_ab *temp;
	
	temp = lst_a;
	while(lst_a)
	{
		if(lst_a->content > temp->content)
				temp = lst_a;
		lst_a = lst_a->next;
	}		
	return (temp);
}

void sort(t_ab **lst_a, t_ab **lst_b, bool bench)
{
	int maxid;
	t_ab *temp;
	while(*lst_b)
	{
		temp = ft_find_higest(*lst_b);
		maxid = temp->id;
		while(maxid)
		{
			rotate_b(lst_b, bench);
			maxid--;
		}
		push_a(lst_a, lst_b, bench);
	}
}

void bucket(t_ab *lst_a, bool bench)
{
	t_ab	*lst_b;
	t_ab	*temp;
	int	scan;
	int	max;
	int	min;
	int save;
	lst_b = NULL;
	max = 1;
	min = 0;
	
	scan = 0;
	temp = ft_find_higest(lst_a);
	max = temp->content;
	while(max > 0)
	{
		min =  max;
		while (scan < 10 && min >= 0)
		{
			min = min - 10;
			scan = ft_scan(lst_a, max, min);
		}
		save = lst_a->content;
		while(scan)
		{
			if(lst_a->content <= max && lst_a->content > min)
			{
				push_b(&lst_a, &lst_b, bench);
				scan--;
			}
			else
				reverse_rotate_a(&lst_a, bench);
		}
		while (lst_a->content != save)
			rotate_a(&lst_a, bench);
		max = min;
		if (lst_b)
			sort(&lst_a, &lst_b, bench);
	}
	// ft_lstprint(lst_a,lst_b);
}

void	ft_bucket_sort(t_ab *lst_a, bool bench)
{
	bucket(lst_a, bench);
}