/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort_bubble2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:13:44 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/20 14:59:09 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*find_value(int i, t_ab *list)
{
	if (i == 5)
	{
		while (1)
		{
			if (list->content == 1)
				return (list);
			if (list->next == NULL)
				break ;
			list = list->next;
		}
	}
	return (NULL);
}
