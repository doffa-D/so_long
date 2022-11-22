/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:11:59 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/21 17:23:42 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_ptr(const char src, va_list ptr)
{
	if (src == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (src == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (src == 'i' || src == 'd')
		return (ft_putnbr(va_arg(ptr, int)));
	else
		return (ft_putchar(src));
	return (0);
}

int	ft_printf(const char *src, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start (ptr, src);
	if (src[i] == 0)
		return (0);
	while (src[i])
	{
		if (src[i] == '%')
		{
			len += ft_ptr(src[++i], ptr);
			i++;
		}
		else
		{
			len++;
			ft_putchar(src[i]);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}
