/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:18:45 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

float	compute_disorder(t_ab *lst)
{
	float	mistakes;
	float	total_pairs;
	t_ab	*temp;

	mistakes = 0;
	total_pairs = 0;
	while (lst->next)
	{
		temp = lst->next;
		while (temp)
		{
			if (lst->content > temp->content)
				mistakes++;
			total_pairs++;
			temp = temp->next;
		}
		lst = lst->next;
	}
	return ((mistakes / total_pairs) + 0.00005);
}

int	check_mode(char *argv)
{
	if (!ft_strncmp(argv, "--simple", 10))
		return (1);
	else if (!ft_strncmp(argv, "--medium", 10))
		return (2);
	else if (!ft_strncmp(argv, "--complex", 10))
		return (3);
	else if (!ft_strncmp(argv, "--adaptive", 10))
		return (4);
	printf("Error: Invalid flags\n");
	return (0);
}

void	sort_lst(t_ab *lst, int algorithm, float dis, bool bench)
{
	float	disorder;

	disorder = (compute_disorder(lst));
	if (algorithm == 4)
	{
		if (dis < 0.2)
			algorithm = 1;
		else if (dis > 0.2 && dis < 0.5)
			algorithm = 2;
		else
			algorithm = 3;
	}
	if (algorithm == 1)
		ft_printf("\n");
	else if (algorithm == 2)
		ft_bucket_sort(lst);
	else
		ft_printf("\n");
	ft_print_bench(algorithm, disorder, bench);
}

int	main(int argc, char *argv[])
{
	t_ab	*lst_a;
	bool	bench;
	int		i;
	int		algorithm;

	algorithm = 4;
	i = 1;
	bench = false;
	lst_a = NULL;
	while (!ft_strncmp(argv[i], "--", 1))
	{
		if (!ft_strncmp(argv[i], "--bench", 10))
			bench = true;
		else
		{
			algorithm = check_mode(argv[i]);
			if (algorithm == 0)
				return (0);
		}
		i++;
	}
	ft_make_lst(&lst_a, i, argc, argv);
	if (lst_a == NULL)
		return (0);
	sort_lst(lst_a, algorithm, compute_disorder(lst_a), bench);
}
