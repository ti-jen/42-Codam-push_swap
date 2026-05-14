/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:37:42 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/14 11:47:52 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			i;
	int long	end;
	int long	temp;
	int long	min;

	min = 0;
	i = 0;
	end = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
		min++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = nptr[i] - '0';
		end = (end * 10) + temp;
		i++;
		if (end > (2147483647 + min))
			return (0);
	}
	if (min == 1)
		end = -end;
	return (end);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main (void)
// {
// char numb[] = "475";

// printf("ft_atoi:\n%i\n", ft_atoi(numb));
// printf("atoi:\n%i", atoi(numb));
// }
