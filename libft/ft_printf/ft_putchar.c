/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:04:49 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:53:42 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// function that writes the given character
int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

// int	main(void)
// {
// 	ft_putchar('a');
// 	return (0);
// }
