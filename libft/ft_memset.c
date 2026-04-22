/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:54:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:23:25 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

// #include <string.h>
// int main()
// {
// 	char str[50] = "super long tekst to test if the text is dif";
// 	char str2[50] = "super long tekst to test if the text is dif";
// 	printf("\nBefore memset(): %s\n", str);
// 	printf("\nBefore ft_memset(): %s\n", str2);

// 	memset(str + 13, '+', 8);
// 	ft_memset(str2 + 13, '+', 8);

// 	printf("\nAfter memset():  %s", str);
// 	printf("\nAfter ft_memset():  %s", str2);
// 	return 0;
// }