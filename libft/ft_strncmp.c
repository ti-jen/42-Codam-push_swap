/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:36:17 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/20 12:01:05 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int				comp;
	unsigned int	i;

	i = 0;
	comp = 0;
	while (!(i == n) && (comp == 0) && !(s1[i] == '\0' && s2[i] == '\0'))
	{
		comp = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (comp);
}

// #include <stdio.h> 
// int main (void)
// {
// 	char str1[] = {-0, -1, -2, -3, -4, -5};
// 	char str2[] = {-0, -1, -2, -3, -4, -5};
// 	size_t		len = strlen((const char *)str1);

// 	printf("%d\n", strncmp((const char *)str1, (const char *)str2, len));
// 	printf("%d", ft_strncmp((const char *)str1, (const char *)str2, len));
// }