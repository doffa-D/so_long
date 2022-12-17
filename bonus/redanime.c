/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redanime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:12:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:14 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remov(t_data *img)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		img->redcoin.map[i] = ft_strtrim(img->redcoin.map[i], "\n");
		img->redenm.map[i] = ft_strtrim(img->redenm.map[i], "\n");
		i++;
	}
}

void	redanime(t_data *img)
{
	int	i;
	int	fd;
	int	fd_2;

	img->redcoin.map = (char **)malloc(sizeof(char *) * 6);
	img->redenm.map = (char **)malloc(sizeof(char *) * 6);
	fd = open("bonus/coin.txt", O_RDWR);
	fd_2 = open("bonus/enm.txt", O_RDWR);
	i = 0;
	while (i < 6)
	{
		img->redcoin.map[i] = get_next_line(fd);
		img->redenm.map[i] = get_next_line(fd_2);
		i++;
	}
	remov(img);
}
