/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:06:26 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 14:49:48 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_checksim(int const n, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (n == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_trimrev(char const	*set, char const *s1, int l, int i)
{
	char	*res;

	res = malloc(l + 1);
	if (res == NULL)
		return (NULL);
	res[l] = '\0';
	i--;
	l--;
	while (ft_checksim(s1[i], set))
		i--;
	while (l >= 0)
	{
		res[l] = s1[i];
		i--;
		l--;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (ft_checksim(s1[i], set))
		i++;
	while (s1[i] != '\0')
	{
		l++;
		i++;
	}
	while (ft_checksim(s1[i - 1], set) && l > 0)
	{
		i--;
		l--;
	}
	return (ft_trimrev(set, s1, l, i));
}

// #include <stdio.h>
// int main (void)
// {
// 	printf("%s",ft_strtrim("lorem ipsum", "m"));

// }