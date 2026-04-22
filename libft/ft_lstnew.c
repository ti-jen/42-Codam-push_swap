/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:41:12 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:23:05 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	l->content = content;
	l -> next = NULL;
	return (l);
}

// #include <stdio.h>
// int main (void)
// {
// 	t_list *first = ft_lstnew("ABCDEFT");

// 	printf("%s\n", first->content);
// }