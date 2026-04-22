/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:10:31 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/23 14:25:56 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	l;

	l = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == l)
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main (void)
// {
// 	char str[] = {0, 1, 2, 3, 4, 5};
// 	int c = 'G';
// 	int l = 20;
// 	char *res = memchr(str, 2 + 256, 3);
// 	char *res2 = ft_memchr(str, 2 + 256, 3);

// 	printf("%s\n", res);
// 	printf("%s\n", res2);

// }