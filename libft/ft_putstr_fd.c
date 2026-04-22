/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:01:12 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/17 15:07:21 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDWR);
// 	ft_putstr_fd("go to test fileeeeeee", fd);
// }