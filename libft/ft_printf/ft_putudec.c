/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:13:48 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/06 10:34:49 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_intlength(unsigned int n)
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

static char	*itstr(char	*res, unsigned int in, int l)
{
	res[l] = '\0';
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

static char	*ft_itoaun(unsigned int n)
{
	int		l;
	char	*res;

	l = ft_intlength(n);
	res = malloc(l + 1);
	if (res == NULL)
		return (NULL);
	itstr(res, n, l);
	return (res);
}

int	ft_putudec(unsigned int n)
{
	char	*numb;

	numb = ft_itoaun(n);
	ft_putstr(numb);
	free(numb);
	return (ft_intlength(n));
}

// int main ()
// {
// 		ft_putudec(12435234234);
// }