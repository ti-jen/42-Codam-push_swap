/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:45:11 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 13:15:37 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = (*lst);
	*lst = new;
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
// 	ft_lstadd_front(&l, ft_lstnew("A1"));
// 	ft_lstadd_front(&l, ft_lstnew("B2"));
// 	ft_lstadd_front(&l, ft_lstnew("C3"));
// 	ft_lstadd_front(&l, ft_lstnew("D4"));
// 	ft_lstadd_front(&l, l2);
// 	int i = 0;
// 	while(i < 3)
// 	{
// 		printf("%i = %s\n", i,  (char*)l->content);
// 		l = l->next;
// 		i++;
// 	}
// }