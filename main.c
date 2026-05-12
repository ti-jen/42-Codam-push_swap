/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/12 18:36:18 by tkroon           ###   ########.fr       */
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
	if (!mistakes)
		return (0);
	return ((mistakes / total_pairs) + 0.00005);
}

int	check_mode(char *argv)
{
	static bool	isrun = false;
	int			algorithm;

	algorithm = 0;
	if (!isrun)
	{
		if (!ft_strncmp(argv, "--simple", 10))
			algorithm = 1;
		else if (!ft_strncmp(argv, "--medium", 10))
			algorithm = 2;
		else if (!ft_strncmp(argv, "--complex", 10))
			algorithm = 3;
		else if (!ft_strncmp(argv, "--adaptive", 10))
			algorithm = 4;
	}
	if (!algorithm)
		ft_printf("Error: Invalid flags\n");
	isrun = true;
	return (algorithm);
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
		ft_selection_sort(lst);
	else if (algorithm == 2)
		ft_bucket_sort(lst);
	else
		ft_radix_sort(lst);
	ft_print_bench(algorithm, disorder, bench);
}

int	main(int argc, char *argv[])
{
	t_ab	*lst_a;
	bool	bench;
	int		i;
	int		algorithm;

	if (!argv[1])
		return (1);
	algorithm = 4;
	i = 1;
	bench = false;
	lst_a = NULL;
	while (i < argc && !ft_strncmp(argv[i], "--", 2) && i < 3)
	{
		if (!ft_strncmp(argv[i], "--bench", 10))
			bench = true;
		else
			algorithm = check_mode(argv[i]);
		if (algorithm == 0)
			return (0);
		i++;
	}
	if (i < argc)
		ft_make_lst(&lst_a, i, argc, argv);
	if (lst_a != NULL)
		sort_lst(lst_a, algorithm, compute_disorder(lst_a), bench);
}
