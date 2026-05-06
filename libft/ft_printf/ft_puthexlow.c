/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:35:26 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:54:10 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

static void	ft_decthex(unsigned int adr)
{
	char	hex[16];
	long	temp;

	ft_strlcpy(hex, "0123456789abcdef", 20);
	if (adr >= 16)
	{
		ft_decthex(adr / 16);
	}
	temp = adr % 16;
	temp = hex[temp];
	write(2, &temp, 1);
}

int	ft_puthexlow(unsigned int n)
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
