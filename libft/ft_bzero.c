/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:49:22 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 14:31:01 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[50] = "super long tekst to test if the text is dif";
// 	char str2[50] = "super long tekst to test if the text is dif";
// 	printf("Before memset: 		%s\n", str);
// 	printf("Before ft_memset: 	%s\n\n", str2);

// 	bzero(str + 5, 4);
// 	ft_bzero(str2 + 5 , 4);

// 	printf("After memset():		%s\n", str + 10);
// 	printf("After ft_memset():	%s\n", str2 + 10);
// 	return 0;
// }