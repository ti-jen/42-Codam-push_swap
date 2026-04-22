/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:14:52 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:25:19 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == 0)
		return ((char *) &big[i]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0')
			{
				i = i - j;
				return ((char *) &big[i]);
			}
		}
		i = i - j;
		i++;
	}
	return (NULL);
}

// int main()
// {
// const char	*largestring = "FooBarBa";
// const char	*smallstring = "";
// int c = 6;

// printf("%s\n", strnstr(largestring, smallstring, c));
// printf("%s", ft_strnstr(largestring, smallstring, c));
// }