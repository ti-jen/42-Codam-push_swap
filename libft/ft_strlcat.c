/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:49:02 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 11:39:15 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	int		p;

	i = 0;
	l = 0;
	p = 0;
	while (dst[l] != '\0' && l < size)
	{
		l++;
	}
	while (src[p] != '\0')
	{
		p++;
	}
	if (l == size)
		return (p + l);
	while (src[i] != '\0' && l + i < size - 1)
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (l + p);
}

// # include <stdio.h>

// int main(void)
// {
// char test[100];
// char test2[100];

// strcpy(test, "12");
// strcpy(test2, "12");

// size_t le = strlcat(test, "1235", 5);
// size_t len = strlcat(test, "111", 7);
// printf("%s\n", test);
// printf("lenght = %zu\n\n", len);
// size_t le1 = ft_strlcat(test2, "5678", 5);
// size_t len1 = ft_strlcat(test2, "915555", 10);
// printf("%s\n", test2);
// printf("lenght = %zu\n\n", len1);
// }