/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showimage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:29:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:06 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ep(t_data *img, int z, int i)
{
	if (img->map.map[z][i] == 'P')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->mob.img, i * 50, z * 50);
		img->mob.locali = i * 50;
		img->mob.localz = z * 50;
	}
	if (img->map.map[z][i] == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->dorclose.img, i * 50, z * 50);
		img->dor.locali = i;
		img->dor.localz = z;
	}
}

int	showpng(t_data *img, int i, int z, int x)
{
	if (img->map.map[z][i] == '1')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->wall.img, i * 50, z * 50);
	}
	if (img->map.map[z][i] == 'C')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin1.img, i * 50, z * 50);
		img->coin1.locali = i;
		img->coin1.localz = z;
		x++;
		img->coin1.i = x;
	}
	ep(img, z, i);
	return (x);
}

void	put(t_data *img, int x)
{
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 150, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 250, 0);
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 120,
		30, 0x007A07D2, "PM:0");
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 240,
		30, 0x007A07D2, ft_strjoin("Coins:", ft_itoa(x)));
}

int	showimage(t_data *img)
{
	int			i;
	static int	x;
	int			z;

	i = 0;
	x = 0;
	z = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->back.img, 0, 0);
	while (z < img->map.xsize)
	{
		i = 0;
		while (i < img->map.linesize)
		{
			x = showpng(img, i, z, x);
			i++;
		}
		z++;
	}
	put(img, x);
	return (0);
}
