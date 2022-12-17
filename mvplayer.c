/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvplayer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:38:04 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 17:36:52 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dplayer(t_data *img)
{
	img->mob.locali += 50;
	img->mob.is = 1;
	img->pm++;
	ft_printf("\033[0;32mPM :[%d]\n", img->pm);
}

void	aplayer(t_data *img)
{
	img->mob.locali -= 50;
	img->mob.is = 2;
	img->pm++;
	ft_printf("\033[0;32mPM :[%d]\n", img->pm);
}

void	wplayer(t_data *img)
{
	img->mob.localz -= 50;
	img->pm++;
	ft_printf("\033[0;32mPM :[%d]\n", img->pm);
}

void	splayer(t_data *img)
{
	img->mob.localz += 50;
	img->pm++;
	ft_printf("\033[0;32mPM :[%d]\n", img->pm);
}

void	mvplayer(t_data *img, int keycode)
{
	img->mob.y = img->mob.localz;
	img->mob.x = img->mob.locali;
	if (keycode == 2 && (img->map.map[img->mob.localz / 50]
			[(img->mob.locali / 50) + 1]) != '1')
		dplayer(img);
	if (keycode == 0
		&& (img->map.map[img->mob.localz / 50][(img->mob.locali / 50) - 1])
			!= '1')
		aplayer(img);
	if (keycode == 1
		&& (img->map.map[(img->mob.localz / 50) + 1][(img->mob.locali / 50)])
			!= '1')
		splayer(img);
	if (keycode == 13
		&& (img->map.map[(img->mob.localz / 50) - 1][(img->mob.locali / 50)])
			!= '1')
		wplayer(img);
	if (img->map.map[img->mob.localz / 50][img->mob.locali / 50] == 'C')
	{
		img->map.map[img->mob.localz / 50][(img->mob.locali / 50)] = 0;
		img->coin1.i -= 1;
	}
}
