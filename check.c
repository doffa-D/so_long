/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:20 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/23 14:50:01 by hdagdagu         ###   ########.fr       */
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

char	**check(void)
{
	int		z;
	int		fd;
	char	**map;

	map = malloc(10000000);
	fd = open("map.ber", O_RDWR);
	z = 0;
	map[z] = get_next_line(fd);
	while (map[z])
	{
		z++;
		map[z] = get_next_line(fd);
	}
	path_finder(map);
	map[z - 1] = ft_strjoin(map[z - 1], "\n\0");
	find_c_e(map);
	free(map);
	return (map);
}
