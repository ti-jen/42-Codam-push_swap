/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:00:59 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/23 14:21:03 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd('0' + nb % 10, fd);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	int cd;

// 	fd = open("test.txt", O_RDWR);
// 	ft_putnbr_fd(6453123, fd);
// }