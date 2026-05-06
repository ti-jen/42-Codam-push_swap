/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:52:54 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 16:54:15 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != 0)
	{
		write(2, &str[i], 1);
		++i;
	}
	return (i);
}

// int	main(void)
// {
// 	char word[] = "cool long text";

// 	ft_putstr(word);
// 	return (0);
// }