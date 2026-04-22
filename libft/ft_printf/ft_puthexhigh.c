/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexhigh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:39:02 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/06 10:30:03 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

static void	ft_decthex(unsigned int adr)
{
	char	hex[16];
	long	temp;

	ft_strlcpy(hex, "0123456789ABCDEF", 20);
	if (adr >= 16)
	{
		ft_decthex(adr / 16);
	}
	temp = adr % 16;
	temp = hex[temp];
	write(1, &temp, 1);
}

int	ft_puthexhigh(unsigned int n)
{
	int	i;

	ft_decthex(n);
	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	i++;
	return (i);
}
