/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:50:11 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 10:54:19 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	i = 0;
	str1 = dest;
	str2 = src;
	if (str1 < str2)
	{
		while (i < n)
		{
			str1[i] = str2[i];
			i++;
		}
		return (dest);
	}
	while (n > 0)
	{
		n--;
		str1[n] = str2[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//    // const char src[50] = "123456789";
//    char Adest[50] = "lorem ipsum dolor sit amet";
//    char Adest2[50] = "ABCDEFGHJ";
//    char Bdest[50] = "lorem ipsum dolor sit amet";
//    char Bdest2[50] = "ABCDEFGHJ";
//    char	*dest;
//    char	*dest2;
//    dest = Adest + 1;
//    dest2 =	Bdest + 1;
//    memmove(Adest, dest, 8);
//    printf("After memmove  =    %s\n", Adest);
//    ft_memmove(Bdest, dest2, 8);
//    printf("After ft_memmove  = %s\n", Bdest);
//    return(0);
// }
