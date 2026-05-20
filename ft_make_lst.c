/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:32:03 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/20 11:03:10 by tkroon           ###   ########.fr       */
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

int	check_dub(t_ab *lst, int content)
{
	while (lst)
	{
		if (lst->content == content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static t_ab	*free_all(t_ab *lst, char **split, int j)
{
	t_ab	*temp;

	ft_printf("Error\n");
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
	return (lst);
}

static int	checkifnumber(char *split, int content)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (content == 0 && split[i] != '0')
		return (0);
	if (split[i] == '-')
	{
		j++;
		if (!split[j])
			return (0);
	}
	while (split[i + j])
	{
		if (!(split[i + j] >= '0' && split[i + j] <= '9'))
			return (0);
		i++;
	}
	return (1);
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
		while (1)
		{
			if (split[j])
				content = ft_atoi(split[j]);
			if (!split[j] || !checkifnumber(split[j], content)
				|| (check_dub(*lst, content)))
			{
				*lst = free_all(*lst, split, j);
				return ;
			}
			free(split[j++]);
			ft_intadd_back(lst, content);
			if (!split[j])
				break ;
		}
		free(split);
	}
	*lst = cleanlist(*lst);
}
