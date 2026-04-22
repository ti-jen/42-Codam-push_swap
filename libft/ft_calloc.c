/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:59:09 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 14:41:06 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	size_t			i;

	i = 0;
	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
// 	void *p = ft_calloc(3, -6);
// 	printf("P = ");
// 	if (p == NULL)
// 	{
// 		printf("NULL");
// 	}
// }