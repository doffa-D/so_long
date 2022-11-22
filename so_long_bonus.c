/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:55:37 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/21 19:38:14 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *img)
{
	int i = 0;
	int z = 0;
	static int k = 0;
	i = 0;
	z = 0;

	mlx_put_image_to_window(img->mlx, img->win, img->back.img , 0, 0);
	if(keycode == 53)
	{
		mlx_destroy_window(img->mlx,img->win);
		free(img->map.map);
		exit(0);
	}
	if(!(img->coin1.i == 0 && (img->mob.localz / 50) == img->dor.localz && (img->mob.locali / 50) == img->dor.locali) && !(img->map.map[img->mob.localz / 50][img->mob.locali / 50] == 'Z'))
	{	
		img->mob.y = img->mob.localz;
		img->mob.x = img->mob.locali;
		if(keycode == 2 && (img->map.map[img->mob.localz / 50][(img->mob.locali / 50) + 1]) != '1')
		{
			img->mob.locali += 50;
			img->mob.is = 1;
		}
		if(keycode == 0 && (img->map.map[img->mob.localz / 50][(img->mob.locali / 50) - 1]) != '1')
		{
			img->mob.locali -= 50;
			img->mob.is = 2;
		}
		if(keycode == 1 && (img->map.map[(img->mob.localz / 50)+1][(img->mob.locali / 50)]) != '1')
			img->mob.localz += 50;
		if(keycode == 13 && (img->map.map[(img->mob.localz / 50)-1][(img->mob.locali / 50)]) != '1')
			img->mob.localz -= 50;
		if(img->map.map[img->mob.localz / 50][img->mob.locali / 50] == 'C')
		{
			img->map.map[img->mob.localz / 50][(img->mob.locali / 50)] = 0;
			img->coin1.i -= 1;
		}
		k++;
	}
	else if(img->coin1.i == 0 && (img->mob.localz / 50) == img->dor.localz && (img->mob.locali / 50) == img->dor.locali)
		mlx_string_put(img->mlx, img->win, (50*img->map.linesize)/2-30, (50*img->map.xsize)/2,  0x00FF0000, " You win ");
	else
		mlx_put_image_to_window(img->mlx, img->win, img->craves.img , img->mob.x, img->mob.y);
	while(z < img->map.xsize)
	{
		i = 0;
		while(i < img->map.linesize)
		{
			if(img->map.map[z][i] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall.img , i*50, z*50);
			if(img->map.map[z][i] == 'E' && img->coin1.i != 0)
				mlx_put_image_to_window(img->mlx, img->win, img->dorclose.img , i*50, z*50);
			if(img->map.map[z][i] == 'E' && img->coin1.i == 0)
				mlx_put_image_to_window(img->mlx, img->win, img->dor.img , img->dor.locali*50, img->dor.localz*50);
			i++;
		}
		z++;
	}
	if(img->mob.is == 1)
	{
		mlx_put_image_to_window(img->mlx, img->win, img->mob.img , img->mob.locali, img->mob.localz);
	}
	else
		mlx_put_image_to_window(img->mlx, img->win, img->mob2.img , img->mob.locali, img->mob.localz);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img ,(50*img->map.linesize)-150, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img ,(50*img->map.linesize)-250, 0);
	mlx_string_put(img->mlx, img->win, (50*img->map.linesize)-142, 30,  0x007A07D2, ft_strjoin("Coins:" ,ft_itoa(img->coin1.i)));
	mlx_string_put(img->mlx, img->win, (50*img->map.linesize)-233, 30,  0x007A07D2, ft_strjoin("PM:" ,ft_itoa(k)));

	return (0);
}

int	main(void)
{
	t_data	img;
	get_array(&img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 50*img.map.linesize, 50*img.map.xsize, "./so_long");
	img.img = mlx_new_image(img.mlx, img.map.linesize, img.map.xsize);

	img.mob.img = mlx_xpm_file_to_image(img.mlx, "xpm/P1.xpm", &img.mob.img_width, &img.mob.img_height);
	img.mob2.img = mlx_xpm_file_to_image(img.mlx, "xpm/P2.xpm", &img.mob2.img_width, &img.mob2.img_height);

	img.enemy1.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm1.xpm", &img.enemy1.img_width, &img.enemy1.img_height);
	img.enemy2.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm2.xpm", &img.enemy2.img_width, &img.enemy2.img_height);
	img.enemy3.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm3.xpm", &img.enemy3.img_width, &img.enemy3.img_height);
	img.enemy4.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm4.xpm", &img.enemy4.img_width, &img.enemy4.img_height);
	img.enemy5.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm5.xpm", &img.enemy5.img_width, &img.enemy5.img_height);
	img.enemy6.img = mlx_xpm_file_to_image(img.mlx, "xpm/enm6.xpm", &img.enemy6.img_width, &img.enemy6.img_height);

	img.coin1.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin1.xpm", &img.coin1.img_width, &img.coin1.img_height);
	img.coin2.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin2.xpm", &img.coin2.img_width, &img.coin2.img_height);
	img.coin3.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin3.xpm", &img.coin3.img_width, &img.coin3.img_height);
	img.coin4.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin4.xpm", &img.coin4.img_width, &img.coin4.img_height);
	img.coin5.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin5.xpm", &img.coin5.img_width, &img.coin5.img_height);
	img.coin6.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin6.xpm", &img.coin6.img_width, &img.coin6.img_height);



	img.craves.img = mlx_xpm_file_to_image(img.mlx, "xpm/craves.xpm", &img.craves.img_width, &img.craves.img_height);

	img.back.img = mlx_xpm_file_to_image(img.mlx, "xpm/background.xpm", &img.back.img_width, &img.back.img_height);
	img.wall.img = mlx_xpm_file_to_image(img.mlx, "xpm/rock.xpm", &img.wall.img_width, &img.wall.img_height);
	img.dorclose.img = mlx_xpm_file_to_image(img.mlx, "xpm/dor-close.xpm", &img.dor.img_width, &img.dor.img_height);
	img.dor.img = mlx_xpm_file_to_image(img.mlx, "xpm/dors.xpm", &img.dorclose.img_width, &img.dorclose.img_height);
	img.wallcoin.img = mlx_xpm_file_to_image(img.mlx, "xpm/wallllllco.xpm", &img.wallcoin.img_width, &img.wallcoin.img_height);
	showimagebonus(&img);

	mlx_hook(img.win, 2, 1L<<0, key_hook, &img);
	mlx_loop_hook(img.mlx, ft_animation, &img);
	mlx_loop(img.mlx);
}
