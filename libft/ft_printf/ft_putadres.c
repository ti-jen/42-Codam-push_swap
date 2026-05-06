/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:22:35 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:54:00 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

static void	ft_decthex(unsigned long adr)
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

int	ft_putadres(unsigned long adr)
{
	int	i;

	if (!adr)
		return (ft_putstr("(nil)"));
	i = 2;
	write(2, "0", 1);
	write(2, "x", 1);
	ft_decthex(adr);
	while (adr >= 16)
	{
		adr = adr / 16;
		i++;
	}
	i++;
	return (i);
}

// int	main(void)
// {
// 	char word[] = "cool long text";
// 	printf("%p\n", word);

// 	ft_putadres((unsigned long)&word);
// 	return (0);
// }