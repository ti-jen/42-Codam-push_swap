/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wouter Ebbers <webbers@student.codam.nl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:13 by tkroon            #+#    #+#             */
/*   Updated: 2026/05/06 13:36:31 by Wouter Ebbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_strprint(const char *str, int count);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putadres(unsigned long adr);
int		ft_putdec(int n);
int		ft_putudec(unsigned int n);
int		ft_puthexhigh(unsigned int n);
int		ft_puthexlow(unsigned int n);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif