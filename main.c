/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/20 15:25:30 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_ab	*free_lst(t_ab *lst)
{
	t_ab	*temp;

	while (lst && lst->prev)
		lst = lst->prev;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	return (lst);
}

static float	compute_disorder(t_ab *lst)
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

static int	check_mode(char *argv)
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
		ft_printf("Error\n");
	isrun = true;
	return (algorithm);
}

static void	sort_lst(t_ab *lst, int algorithm, float dis, bool bench)
{
	float	disorder;
	int		strat;

	strat = algorithm;
	disorder = (compute_disorder(lst));
	lst = cleanlist(lst);
	if (algorithm == 4)
	{
		if (dis < 0.2 || num_items_lst(lst) < 6)
			algorithm = 1;
		else if (dis > 0.2 && dis < 0.5)
			algorithm = 2;
		else
			algorithm = 3;
	}
	if (algorithm == 1)
		ft_bubble_sort(lst);
	else if (algorithm == 2)
		ft_bucket_sort(lst);
	else
		ft_radix_sort(lst);
	lst = free_lst(lst);
	ft_print_bench(strat, disorder, bench);
}

int	main(int argc, char *argv[])
{
	t_ab	*lst_a;
	bool	bench;
	int		i;
	int		algorithm;

	if (!argv[1])
		return (0);
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
