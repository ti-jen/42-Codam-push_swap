/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:37:42 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:26:20 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

// #include <stdio.h>
// int main ()
// {
// 	char ch = '-';
// 	printf("%c\n", toupper(ch));
// 	printf("%c", ft_toupper(ch));

// 	return(0);
// }