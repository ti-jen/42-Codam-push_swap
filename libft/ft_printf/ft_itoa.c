/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:03:00 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/06 10:14:22 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlength(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

static char	*itstr(char	*res, long in, int l)
{
	res[l] = '\0';
	if (in < 0)
	{
		in = -in;
		res[0] = '-';
	}
	l--;
	if (in == 0)
		res[l] = '0';
	while (in > 0)
	{
		res[l] = in % 10 + '0';
		in = in / 10;
		l--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	in;
	int		l;
	char	*res;

	in = n;
	l = ft_intlength(in);
	if (in < 0)
		l++;
	res = malloc(l + 1);
	if (res == NULL)
		return (NULL);
	itstr(res, in, l);
	return (res);
}

// #include <limits.h>
// #include <stdio.h>
// int main (void)
// {
// 	char *test = ft_itoa(INT_MIN);
// 	printf("%s", test);
// }