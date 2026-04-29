/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:32:03 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/29 18:23:07 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "lib_push_swap.h"
#include "libft/ft_printf/ft_printf.h"

void	ft_intadd_back(t_ab **lst, int content)
{
	t_ab		*temp;
	t_ab		*new;
	static int	i = 0;

	temp = *lst;
	new = (t_ab *)malloc(sizeof(t_ab));
	if (!new)
		return ;
	new->content = content;
	new->id = i;
	new->prev = NULL;
	new->next = NULL;
	i++;
	if (!temp)
		*lst = new;
	else
	{
		while (temp-> next)
		{
			temp = temp-> next;
		}
		new->prev = temp;
		temp->next = new;
	}
}

int	ft_lst_check_doubles(t_ab *lst, int content)
{
	while (lst)
	{
		if ((lst->content - content) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	free_all(t_ab *lst, char **split, int j)
{
	t_ab	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

void	ft_make_lst(t_ab **lst, int i, int argc, char **argv)
{
	char				**split;
	int					content;
	long unsigned int	j;

	while ((argc) > i)
	{
		split = ft_split(argv[i++], ' ');
		j = 0;
		while (split[j])
		{
			content = ft_atoi(split[j]);
			if ((content == 0 && split[j][0] != '0')
			|| (ft_lst_check_doubles(*lst, content)))
			{
				ft_printf("Error: Invalid or Double Numbers\n");
				free_all(*lst, split, j);
				*lst = NULL;
				return ;
			}
			free(split[j++]);
			ft_intadd_back(lst, content);
		}
		free(split);
	}
}
