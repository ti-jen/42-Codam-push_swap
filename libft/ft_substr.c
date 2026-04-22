/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:04:32 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:25:45 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*res;

	i = 0;
	l = 0;
	if (ft_strlen(s) <= start)
	{
		res = malloc(l + 1);
		res[i] = '\0';
		return (res);
	}
	while (l < len && s[start + l] != '\0')
		l++;
	res = malloc(l + 1);
	if (res == NULL)
		return (NULL);
	while (ft_strlen(s) > start && len > i)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// int main (void)
// {
// 	printf("%s\n",ft_substr("tripouille", 0, 1000));
// 	printf("%s",ft_substr("tripouille", 1, 1));
// }