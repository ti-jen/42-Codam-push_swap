/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:10:18 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:54:20 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strprint(const char *str, int count)
{
	int	i;

	i = 0;
	while (str[count + i] != '\0' && str[count + i] != '%')
	{
		write(2, &str[count + i], 1);
		i++;
	}
	return (i);
}
