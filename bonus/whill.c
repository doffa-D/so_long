/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:19:56 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 13:30:08 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ifc_or_z(t_data *img, int i, int z)
{
	if (img->map.map[z][i] == 'C')
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin2.img, i * 50, z * 50);
	if (img->map.map[z][i] == 'Z')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy1.img, i * 50, z * 50);
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy1.img, img->enemy1.locali * 50,
			img->enemy1.localz * 50);
	}
}

void	if1_e(t_data *img, int i, int z)
{
	if (img->map.map[z][i] == '1')
		mlx_put_image_to_window(img->mlx, img->win,
			img->wall.img, i * 50, z * 50);
	if (img->map.map[z][i] == 'E' && img->coin1.i != 0)
		mlx_put_image_to_window(img->mlx, img->win,
			img->dorclose.img, i * 50, z * 50);
	if (img->map.map[z][i] == 'E' && img->coin1.i == 0)
		mlx_put_image_to_window(img->mlx, img->win, img->dor.img,
			img->dor.locali * 50, img->dor.localz * 50);
}

void	whill(t_data *img)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (z < img->map.xsize)
	{
		i = 0;
		while (i < img->map.linesize)
		{
			ifc_or_z(img, i, z);
			if1_e(img, i, z);
			i++;
		}
		z++;
	}
}
