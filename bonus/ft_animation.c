/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:01:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/23 15:15:19 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy(t_data *img, int i, int z)
{
	static int	r;

	r++;
	if (r <= ENEMY_ANIMATION)
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy1.img, i * 50, z * 50);
	else if ((r > ENEMY_ANIMATION) && (r <= ENEMY_ANIMATION + 60))
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy2.img, i * 50, z * 50);
	else if ((r > ENEMY_ANIMATION + 60) && (r <= ENEMY_ANIMATION + 120))
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy3.img, i * 50, z * 50);
	else if ((r > ENEMY_ANIMATION + 120) && (r <= ENEMY_ANIMATION + 180))
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy4.img, i * 50, z * 50);
	else if ((r > ENEMY_ANIMATION + 180) && (r <= ENEMY_ANIMATION + 240))
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy5.img, i * 50, z * 50);
	else if ((r > ENEMY_ANIMATION + 240) && (r <= ENEMY_ANIMATION + 300))
		mlx_put_image_to_window(img->mlx, img->win,
			img->enemy6.img, i * 50, z * 50);
	else if (r > ENEMY_ANIMATION + 300)
		r = 0;
	return (0);
}

int	coins(t_data *img, int i, int z)
{
	static int	r;

	r++;
	if (r <= COIN_ANIMATION)
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin1.img, i * 50, z * 50);
	else if ((r > COIN_ANIMATION) && (r <= COIN_ANIMATION + 60))
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin2.img, i * 50, z * 50);
	else if ((r > COIN_ANIMATION + 60) && (r <= COIN_ANIMATION + 120))
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin3.img, i * 50, z * 50);
	else if ((r > COIN_ANIMATION + 120) && (r <= COIN_ANIMATION + 180))
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin4.img, i * 50, z * 50);
	else if ((r > COIN_ANIMATION + 180) && (r <= COIN_ANIMATION + 240))
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin5.img, i * 50, z * 50);
	else if ((r > COIN_ANIMATION + 240) && (r <= COIN_ANIMATION + 300))
		mlx_put_image_to_window(img->mlx, img->win,
			img->coin6.img, i * 50, z * 50);
	else if (r > COIN_ANIMATION + 300)
		r = 0;
	return (0);
}

void	you(t_data *img)
{
	if (img->map.map[img->mob.localz / 50][img->mob.locali / 50] == 'Z')
	{
		mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) / 2 - 30,
			(50 * img->map.xsize) / 2, 0x00FF0000, " you dead ");
		mlx_put_image_to_window(img->mlx, img->win,
			img->craves.img, img->mob.x, img->mob.y);
	}
	if (img->coin1.i == 0 && (img->mob.localz / 50) == img->dor.localz
		&& (img->mob.locali / 50) == img->dor.locali)
		mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) / 2 - 30,
			(50 * img->map.xsize) / 2, 0x00B64F, " You win ");
}

int	ft_animation(t_data *img)
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
			if (img->map.map[z][i] == 'C')
				coins(img, i, z);
			if (img->map.map[z][i] == 'Z')
				enemy(img, i, z);
			i++;
		}
		z++;
	}
	you(img);
	return (0);
}
