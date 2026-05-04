/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:56:01 by Wouter Ebbe       #+#    #+#             */
/*   Updated: 2026/05/04 16:55:21 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void ft_sort_bubble(t_ab **lst);
t_ab *nw_node(int content);

int main()
{
	t_ab *lst;
	t_ab *tmp;
	t_ab *new;
	
	int i = 0;
	int values[] = {1,10,23,21,-5,83,100};

	tmp = nw_node(values[i]);
	tmp->id = i;
	
	lst = tmp;
	i++;
	while (i < 7)
	{
		new = nw_node(values[i]);
		tmp->next = new;
		new->prev = tmp;
		new -> prev = tmp;
		new -> id = i;
		tmp = new;
		i++;
	}
	ft_sort_bubble(&lst);
}

t_ab *nw_node(int content)
{
	t_ab *node;

	node = (t_ab *)malloc(sizeof(t_ab));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	node -> prev = NULL;
	return(node);
}


void ft_sort_bubble(t_ab **lst)
{
	t_ab *val1;
	t_ab *val2;
	t_ab *tmp;
	int save_val;
	int val_change;
	int runs;

	runs = 0;
	val_change = 1;
	val1 = *lst;
	val2 = val1->next;
	
	tmp = *lst;
	while(tmp->next != NULL)
	{
		printf("id:%d content:%d\n", tmp->id, tmp->content);
		tmp = tmp -> next;
	}
	
	while (val_change != 0)
	{
		val_change = 0;
		val1 = *lst;
		val2 = val1->next;

		while(val2->next != NULL)
		{
			if (val1->content > val2->content)
			{
				save_val = val1->content;
				val1->content = val2->content;
				val2->content = save_val;
				val_change = 1;
			}
			val1 = val1->next;
			val2 = val1->next;
		}
		runs++;

	}
	tmp = *lst;
	while(tmp->next != NULL)
	{
		printf("id:%d content:%d\n", tmp->id, tmp->content);
		tmp = tmp -> next;
	}
	printf("runs:%d\n", runs);
	
}
