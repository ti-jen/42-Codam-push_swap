/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 10:34:47 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 11:43:45 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				p;
	unsigned char	l;

	l = c;
	p = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == l)
		{
			p = i;
		}
		i++;
	}
	if (l == '\0')
		return ((char *) &s[i]);
	if (p >= 0)
		return ((char *) &s[p]);
	return (NULL);
}

// #include <stdio.h>

// int main (void)
// {
// 	char str[] = "tripouille";
// 	int c = ' ';

// 	// printf("%s\n", strrchr(str, c));
// 	printf("%s\n", ft_strrchr(str, c));

// }