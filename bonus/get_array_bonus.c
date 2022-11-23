/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:03:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/23 15:15:23 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_dor_and_player(int e, int p, int c)
{
	if (e >= 2 || e == 0)
	{
		ft_printf("\n -------------- \n | 🤨 %d door | \n -------------- \n", e);
		exit(0);
	}
	if (p >= 2 || p == 0)
	{
		ft_printf("\n -------------- \n | 🤨 %d Player | \n -------------- \n", p);
		exit(0);
	}
	if (c == 0)
	{
		ft_printf("\n -------------- \n | 😳 0 coins | \n -------------- \n");
		exit(0);
	}
}

void	find_p_e_c(t_data *img, int e)
{
	int	i;
	int	z;
	int	p;
	int	c;

	p = 0;
	c = 0;
	i = 0;
	z = 0;
	while (img->map.map[z])
	{
		i = 0;
		while (img->map.map[z][i])
		{
			if (img->map.map[z][i] == 'P')
				p++;
			if (img->map.map[z][i] == 'E')
				e++;
			if (img->map.map[z][i] == 'C')
				c++;
			i++;
		}
		z++;
	}
	check_dor_and_player(e, p, c);
}

void	find_error(t_data *img)
{
	int	z;
	int	i;

	z = 0;
	i = 0;
	while (img->map.map[z])
	{
		if (z == 0)
		{
			i = 0;
			while (img->map.map[z][i])
			{
				if (img->map.map[z][i] != '1' && img->map.map[z][i] != '\n')
					exit(0);
				i++;
			}
		}
		if (img->map.map[z][0] != '1' && img->map.map[z][0] != '\n')
			exit(0);
		if (img->map.map[z][strlen(img->map.map[z]) - 2] != '1'
			&& img->map.map[z][strlen(img->map.map[z]) - 2] != '\n')
			exit(0);
		z++;
	}
}

char	**get_array_bonus(t_data *img)
{
	int		e;
	int		i;
	int		z;
	int		fd;
	char	**map;

	e = 0;
	i = 0;
	z = 0;
	fd = open("map.ber", O_RDWR);
	map = malloc(1000);
	map[z] = get_next_line(fd);
	while (map[z])
		map[++z] = get_next_line(fd);
	img->map.xsize = z;
	img->map.linesize = ft_strlen(map[0]) - 1;
	img->map.map = map;
	find_error(img);
	z--;
	while (img->map.map[z][++i])
		if (map[z][i] != '1' && map[z][i] != '\n')
			exit(0);
	find_p_e_c(img, e);
	check_bonus();
	return (map);
}
