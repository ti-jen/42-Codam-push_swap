/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:01:37 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 14:41:49 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
//     char c = 'a';

//     printf("%i\n", isalpha(c));
//     printf("%i", ft_isalpha(c));

// }