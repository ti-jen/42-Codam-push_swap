/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:38:05 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/06 10:47:57 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlength(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

int	ft_putdec(int n)
{
	char	*numb;

	numb = ft_itoa(n);
	ft_putstr(numb);
	free(numb);
	return (ft_intlength(n));
}
