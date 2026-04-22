/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:48:30 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/24 17:21:10 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		la;
	int		lb;
	char	*res;

	i = 0;
	la = 0;
	lb = 0;
	while (s1[la] != '\0')
		la++;
	while (s2[lb] != '\0')
		lb++;
	res = malloc((la + lb) + 1);
	if (res == NULL)
		return (NULL);
	while (i <= (la + lb))
	{
		if (i < la)
			res[i] = s1[i];
		else
			res[i] = s2[i - la];
		i++;
	}
	return (res);
}

// int main (void)
// {
// 	char string1[] = "12345";
// 	char string2[] = "ABCDEF";

// 	char *string3 = ft_strjoin(string1, string2);

// 	printf("%s", string3);

// 	free(string3);
// }