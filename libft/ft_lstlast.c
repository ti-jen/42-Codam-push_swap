/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:34:00 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:22:37 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp-> next == NULL)
		{
			return (temp);
		}
		temp = temp-> next;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main (void)
// {
// 	t_list *first = (t_list *)malloc(sizeof(t_list));
// 	t_list *second = (t_list *)malloc(sizeof(t_list));
// 	t_list *third = (t_list *)malloc(sizeof(t_list));

// 	third->next = NULL;
// 	third->content = "333";
// 	second->content = "222";
// 	first->content = "111";

// 	ft_lstadd_front(&third, second);
// 	ft_lstadd_front(&second, first);

// 	t_list *last = ft_lstlast(first);
// 	printf("%s\n", (char*)last->content);

// }
