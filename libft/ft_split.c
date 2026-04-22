/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:42:59 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/26 16:03:47 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_count(char const *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] != n && str[i] != '\0')
		count++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i - 1] == n && str[i] != n && str[i] != '\0')
			count++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**id;
	int		i;
	int		p;
	int		j;

	p = 0;
	j = 0;
	id = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (id == NULL)
		return (NULL);
	while (ft_count(s, c) > j)
	{
		while (s[p] == c && s[p] != '\0')
			p++;
		i = p;
		while (s[i] != c && s[i] != '\0')
			i++;
		id[j] = malloc(((i - p) + 1));
		ft_strncpy(id[j], &s[p], i - p);
		p = i;
		j++;
	}
	id[j] = NULL;
	return (id);
}

// #include <stdio.h>

// int main (void)
// {
// 	char **arr;

// 	arr = ft_split(" Tripouille", ' ');

// 	int i = 0;

// 	printf("%i == %s\n",i, strcmp(arr[0], "Tripouille"));

// }