/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:05:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 13:21:34 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*tempi;

	if (lst == NULL || del == NULL)
		return ;
	temp = *lst;
	while (temp)
	{
		tempi = temp;
		del(temp->content);
		temp = temp-> next;
		free(tempi);
	}
	*lst = temp;
}

// int main (void)
// {
// 	t_list *first = (t_list *)malloc(sizeof(t_list));
// 	t_list *second = (t_list *)malloc(sizeof(t_list));
// 	t_list *third = (t_list *)malloc(sizeof(t_list));

// 	third->next = NULL;
// 	second->next = third;
// 	first->next = second;
// 	third->content = "333";
// 	second->content = "222";
// 	first->content = "111";

// 	ft_lstclear(&first, free);

// }