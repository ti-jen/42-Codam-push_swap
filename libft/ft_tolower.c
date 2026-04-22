/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:37:42 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 16:09:56 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

// #include <stdio.h>
// int main ()
// {
// 	char ch = 'A';
// 	printf("%c\n", tolower(ch));
// 	printf("%c", ft_tolower(ch));

// 	return(0);
// }