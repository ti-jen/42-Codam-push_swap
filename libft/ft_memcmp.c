/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:15:26 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/16 14:10:19 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				comp;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	comp = 0;
	while (i < n && comp == 0)
	{
		comp = str1[i] - str2[i];
		i++;
	}
	return (comp);
}

// int main (void)
// {
// 	char s1[20] = "ABCEFGH\0\0\0abcda1";
// 	char s2[20] = "ABCEFGH\0\0\0abcd";
// 	int c = 15;

// 	printf("%d\n", memcmp(s1, s2, c));
// 	printf("%d", ft_memcmp(s1, s2, c));

// }