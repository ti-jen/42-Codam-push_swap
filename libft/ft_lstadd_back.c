/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:49:18 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:03:55 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = (*lst);
	while (temp-> next)
	{
		temp = temp-> next;
	}
	temp->next = new;
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*l;

// 	l = (t_list *)malloc(sizeof(t_list));
// 	l->content = content;
// 	l -> next = NULL;
// 	return (l);
// }

// #include <stdio.h>
// int main (void)
// {
// 	t_list * l =  NULL;
// 	t_list * l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew("A1"));
// 	ft_lstadd_back(&l, ft_lstnew("B2"));
// 	ft_lstadd_back(&l, ft_lstnew("C3"));
// 	ft_lstadd_back(&l, ft_lstnew("D4"));
// 	ft_lstadd_back(&l, l2);
// 	int i = 0;
// 	while(i < 4)
// 	{
// 		printf("%i = %s\n", i,  (char*)l->content);
// 		l = l->next;
// 		i++;
// 	}
// }