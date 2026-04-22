/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:03:40 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/23 14:18:26 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	int cd;

// 	fd = open("test.txt", O_RDWR);
// 	ft_putchar_fd('p', fd);
// }