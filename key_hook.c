/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:55:37 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:35 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putcheck(int z, int i, t_data *img)
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
	if (img->map.map[z][i] == 'C')
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin1.img, i * 50, z * 50);
}

void	makephototowin(t_data *img, int z, int i, int k)
{
	while (z < img->map.xsize)
	{
		i = 0;
		while (i < img->map.linesize)
		{
			putcheck(z, i, img);
			i++;
		}
		z++;
	}
	if (img->mob.is == 1)
		mlx_put_image_to_window(img->mlx, img->win, img->mob.img,
			img->mob.locali, img->mob.localz);
	else
		mlx_put_image_to_window(img->mlx, img->win, img->mob2.img,
			img->mob.locali, img->mob.localz);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 150, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 250, 0);
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 120,
		30, 0x007A07D2, ft_strjoin("PM:", ft_itoa(k)));
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 240,
		30, 0x007A07D2, ft_strjoin("Coins:", ft_itoa(img->coin1.i)));
}

int	win(t_data *img, int keycode)
{
	static int	k;

	if (!(img->coin1.i == 0 && (img->mob.localz / 50) == img->dor.localz
			&& (img->mob.locali / 50) == img->dor.locali))
	{
		if (img->wall.y == 1)
			mvplayer(img, keycode);
		else if (img->wall.y == 2
			&& !(img->map.map[img->mob.localz / 50][img->mob.locali / 50]
			== 'Z'))
			mvplayer(img, keycode);
		k++;
	}
	else if (img->coin1.i == 0 && (img->mob.localz / 50) == img->dor.localz
		&& (img->mob.locali / 50) == img->dor.locali)
	{
		mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) / 2 - 30,
			(50 * img->map.xsize) / 2, 0x00B64F, " You win ");
	}
	else
		mlx_put_image_to_window(img->mlx, img->win, img->craves.img,
			img->mob.x, img->mob.y);
	return (k);
}

int	key_hook(int keycode, t_data *img)
{
	int			i;
	int			z;
	static int	k;

	k = 0;
	i = 0;
	z = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->back.img, 0, 0);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		free(img->map.map);
		exit(0);
	}
	k = win(img, keycode);
	makephototowin(img, z, i, k);
	return (0);
}
