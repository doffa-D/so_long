/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showimage_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:29:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/21 17:18:34 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	showimagebonus(t_data *img)
{
	int i = 0;
	static int x = 1;
	int z = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->back.img , 0, 0);
	while(z < img->map.xsize)
	{
		i = 0;
		while(i < img->map.linesize)
		{
			if(img->map.map[z][i] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->wall.img , i*50, z*50);
			}
			if(img->map.map[z][i] == 'C')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->coin1.img , i*50, z*50);
				img->coin1.locali = i;
				img->coin1.localz = z;
				img->coin1.i = x;
				x++;
			}
            if(img->map.map[z][i] == 'P')
            {
                mlx_put_image_to_window(img->mlx, img->win, img->mob.img , i*50, z*50);
                img->mob.locali = i*50;
                img->mob.localz = z*50;
            }
			if(img->map.map[z][i] == 'E')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->dorclose.img , i*50, z*50);
				img->dor.locali = i;
				img->dor.localz = z;
			}
			i++;
		}
		z++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img ,(50*img->map.linesize)-150, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img ,(50*img->map.linesize)-250, 0);
	mlx_string_put(img->mlx, img->win, (50*img->map.linesize)-142, 30,  0x007A07D2, ft_strjoin("Coins:" ,ft_itoa(img->coin1.i)));
	mlx_string_put(img->mlx, img->win, (50*img->map.linesize)-233, 30,  0x007A07D2, "PM:0");


	return (0);
}