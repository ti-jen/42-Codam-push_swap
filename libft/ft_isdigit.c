/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:30:00 by tkroon            #+#    #+#             */
/*   Updated: 2026/03/25 14:42:08 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
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

//     printf("%i\n", isdigit(c));
//     printf("%i", ft_isdigit(c));

// }