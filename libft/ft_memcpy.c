/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:35:24 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 15:19:00 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*str1;
	const char		*str2;

	str1 = dest;
	str2 = src;
	while (n > 0)
	{
		*str1 = *str2;
		str2++;
		str1++;
		n--;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//    // const char src[50] = "123456789";
//    char dest[50] = "Learning";
//    char dest2[50] = "Learning";
//    char dest3[50] = "Learning";
//    printf("Before memcpy dest =  %s\n", dest);
//    memcpy(dest + 8, dest, 10);
//    printf("After memcpy dest =     %s\n", dest);
//    memmove(dest2 + 8, dest2, 10);
//    printf("After memmove dest2 =   %s\n", dest2);
//    ft_memcpy(dest3 + 8, dest3, 10);
//    printf("After ft_memcpy dest3 = %s\n", dest3);
//    return(0);
// }