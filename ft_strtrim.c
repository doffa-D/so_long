/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:09:21 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 13:30:49 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		slen;
	char	*b;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	i = 0;
	if (!s)
		return (0);
	b = malloc(sizeof(char) * (len + 1));
	if (b == 0)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		b[i] = s[start];
		i++;
		start++;
	}
	b[i] = '\0';
	return (b);
}

int	ftstrchr(char c, char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		s1ln;
	char	*b;

	i = 0;
	if (s1 == 0)
		return (0);
	if (set == 0)
		return ((char *)s1);
	s1ln = ft_strlen(s1) - 1;
	while (ftstrchr(s1[i], set))
		i++;
	while (ftstrchr(s1[s1ln], set) && s1ln > 0)
		s1ln--;
	if (i > s1ln)
		return (ft_substr(s1, i, 0));
		b = ft_substr(s1, i, s1ln - i +1);
	free(s1);
	return (b);
}

// int main()
// {
// 	ft_printf("%s",ft_strtrim("##hello##", "#"));
// }