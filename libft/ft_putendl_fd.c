/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:04:27 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/17 15:05:01 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	l;

	i = 0;
	l = '\n';
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &l, 1);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	int cd;

// 	fd = open("test.txt", O_RDWR);
// 	ft_putendl_fd("go to next line", fd);
// }