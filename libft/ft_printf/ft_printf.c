/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:09:29 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/13 10:33:36 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_putconversion(int format, va_list arg)
{
	int	c;

	c = 0;
	if (format == 'c')
		c = ft_putchar(va_arg(arg, int));
	else if (format == 's')
		c = ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		c = ft_putadres(va_arg(arg, unsigned long));
	else if (format == 'd' || format == 'i')
		c = ft_putdec(va_arg(arg, int));
	else if (format == 'u' )
		c = ft_putudec(va_arg(arg, unsigned int));
	else if (format == 'x')
		c = ft_puthexlow(va_arg(arg, int));
	else if (format == 'X')
		c = ft_puthexhigh(va_arg(arg, int));
	else if (format == '%')
	{
		write(1, "%", 1);
		c++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		c;
	va_list	arg;

	i = 0;
	j = 0;
	c = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i] != '\0')
	{
		j = ft_strprint(format, i);
		i = i + j;
		c = c + j;
		if (format[i] == '\0')
			break ;
		c = c + ft_putconversion(format[i + 1], arg);
		i = i + 2;
	}
	va_end(arg);
	return (c);
}

// int main ()
// {
// 	char i = 'A';
// 	char b = 'c';
// 	ft_printf("loongtext == %c--%c-", i, b);
// }