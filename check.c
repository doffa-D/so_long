/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:20 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 15:36:11 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	replace(int z, int p, int i, char **map)
{
	if (map[z][i + 1] == '0' || map[z][i + 1] == 'C' || map[z][i + 1] == 'E')
	{
		map[z][i + 1] = 'P';
		p = 1;
	}
	if (map[z][i - 1] == '0' || map[z][i - 1] == 'C' || map[z][i - 1] == 'E')
	{
		map[z][i - 1] = 'P';
		p = 1;
	}
	if (map[z + 1][i] == '0' || map[z + 1][i] == 'C' || map[z + 1][i] == 'E')
	{
		map[z + 1][i] = 'P';
		p = 1;
	}
	if (map[z - 1][i] == '0' || map[z - 1][i] == 'C' || map[z - 1][i] == 'E')
	{
		map[z - 1][i] = 'P';
		p = 1;
	}
	return (p);
}

void	path_finder(char **map)
{
	int	p;
	int	i;
	int	z;

	p = 1;
	z = 0;
	i = 0;
	while (p == 1)
	{
		p = 0;
		z = 0;
		while (map[z])
		{
			i = 0;
			while (map[z][i])
			{
				if (map[z][i] == 'P')
				{
					p = replace(z, p, i, map);
				}
				i++;
			}
			z++;
		}
	}
}

void	find_c_e(char **map)
{
	int	z;
	int	i;

	z = 0;
	i = 0;
	while (map[z])
	{
		i = 0;
		if (ft_strlen(map[z]) != ft_strlen(map[0]))
			exit(0);
		if (map[z])
		{
			ft_strchr(map[z], 'C');
			ft_strchr(map[z], 'E');
		}
		while (map[z][i])
		{
			if (map[z][i] != '0' && map[z][i] != '1' && map[z][i] != 'P'
				&& map[z][i] != 'E' && map[z][i] != 'C' && map[z][i] != '\n')
				exit(0);
			i++;
		}
		z++;
	}
}

char	*ft_strjoin_5(char *s1, char *s2)
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
	free(s1);
	return (b);
}

void	check(char *argv)
{
	int		z;
	int		fd;
	char	**map;

	map = malloc(10000000);
	fd = open(argv, O_RDWR);
	z = 0;
	map[z] = get_next_line(fd);
	while (map[z])
	{
		z++;
		map[z] = get_next_line(fd);
	}
	path_finder(map);
	map[z - 1] = ft_strjoin_5(map[z - 1], "\n\0");
	find_c_e(map);
	z = 0;
	while (map[z])
		free(map[z++]);
	free(map);
}
