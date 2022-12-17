/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:11:45 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 13:36:12 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_counte(long int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*dst;
	long int	nb;
	int			len;

	nb = n;
	len = ft_counte(nb);
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	if (nb < 0)
	{
		dst[0] = '-';
		nb *= -1;
	}
	dst[len] = 0;
	if (nb == 0)
		dst[0] = '0';
	while (nb != 0)
	{
		dst[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && (unsigned char)c != s[i])
		i++;
	if (s[i] == (unsigned char)c)
	{
		ft_printf("   -------------------------");
		ft_printf("\n | 😭 I can't find the path |\n");
		ft_printf("  -------------------------\n");
		exit(0);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*b;
	int		j;

	if (!s1 || !s2)
		return (0);
	b = malloc((ft_strlen(s1) + 1) + ft_strlen(s2));
	if (!b)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		b[i] = s2[j];
		i++;
		j++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (0);
}
