/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 10:34:47 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/20 11:05:34 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	l;

	l = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == l)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == c)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

// int main (void)
// {
// 	const char* str = "ABCDEFGHIJKL";
// 	int c = 0;

// 	printf("%s\n", strchr(str, c));
// 	printf("%s\n", ft_strchr(str, c));

// }