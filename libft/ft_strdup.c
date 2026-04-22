/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:12:21 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:24:46 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int				i;
	int				l;
	char			*res;

	i = 0;
	l = 0;
	while (s[l] != '\0')
	{
		l++;
	}
	res = malloc((l + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <string.h>

// int main (void)
// {
// 	char source[] = "coucou";

// 	char* target = strdup(source);
// 	char* target2 = ft_strdup(source);

// 	printf("%s\n", target);
// 	printf("%s", target2);
// 	return 0;
// }