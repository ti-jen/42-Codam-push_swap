/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:49:40 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/23 13:46:20 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		l;
	char	*res;

	i = 0;
	l = 0;
	while (s[l] != '\0')
		l++;
	res = malloc(l + 1);
	while (i < l && res != NULL)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main (void)
// {
// 	char *arr;

// 	arr = ft_strmapi("abcdefg", ft_toupper);

// 	printf("%s", arr);
// }
