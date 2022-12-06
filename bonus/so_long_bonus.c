/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:57:14 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/05 19:40:49 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coin(t_data *img)
{
	img->coin1.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin1.xpm",
			&img->coin1.img_width, &img->coin1.img_height);
	img->coin2.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin2.xpm",
			&img->coin2.img_width, &img->coin2.img_height);
	img->coin3.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin3.xpm",
			&img->coin3.img_width, &img->coin3.img_height);
	img->coin4.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin4.xpm",
			&img->coin4.img_width, &img->coin4.img_height);
	img->coin5.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin5.xpm",
			&img->coin5.img_width, &img->coin5.img_height);
	img->coin6.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin6.xpm",
			&img->coin6.img_width, &img->coin6.img_height);
}

void	enem(t_data *img)
{
	img->enemy1.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm1.xpm",
			&img->enemy1.img_width, &img->enemy1.img_height);
	img->enemy2.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm2.xpm",
			&img->enemy2.img_width, &img->enemy2.img_height);
	img->enemy3.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm3.xpm",
			&img->enemy3.img_width, &img->enemy3.img_height);
	img->enemy4.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm4.xpm",
			&img->enemy4.img_width, &img->enemy4.img_height);
	img->enemy5.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm5.xpm",
			&img->enemy5.img_width, &img->enemy5.img_height);
	img->enemy6.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm6.xpm",
			&img->enemy6.img_width, &img->enemy6.img_height);
}

void	put_image(t_data *img)
{
	img->mob.img = mlx_xpm_file_to_image(img->mlx, "xpm/P1.xpm",
			&img->mob.img_width, &img->mob.img_height);
	img->mob2.img = mlx_xpm_file_to_image(img->mlx, "xpm/P2.xpm",
			&img->mob2.img_width, &img->mob2.img_height);
	img->craves.img = mlx_xpm_file_to_image(img->mlx, "xpm/craves.xpm",
			&img->craves.img_width, &img->craves.img_height);
	img->back.img = mlx_xpm_file_to_image(img->mlx, "xpm/background.xpm",
			&img->back.img_width, &img->back.img_height);
	img->wall.img = mlx_xpm_file_to_image(img->mlx, "xpm/rock.xpm",
			&img->wall.img_width, &img->wall.img_height);
	img->dorclose.img = mlx_xpm_file_to_image(img->mlx, "xpm/dor-close.xpm",
			&img->dor.img_width, &img->dor.img_height);
	img->dor.img = mlx_xpm_file_to_image(img->mlx, "xpm/dors.xpm",
			&img->dorclose.img_width, &img->dorclose.img_height);
	img->wallcoin.img = mlx_xpm_file_to_image(img->mlx, "xpm/wallllllco.xpm",
			&img->wallcoin.img_width, &img->wallcoin.img_height);
	enem(img);
	coin(img);
}

int	main(int argc,char **argv)
{
	t_data	img;

	if(argc == 2)
	{
		if(!(ft_strnstr(argv[1],".ber",ft_strlen(argv[1]))))
			exit(0);
		get_array_bonus(&img,argv[1]);
		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, 50 * img.map.linesize,
				50 * img.map.xsize, "./so_long");
		img.img = mlx_new_image(img.mlx, img.map.linesize, img.map.xsize);
		put_image(&img);
		showimage(&img);
		img.wall.y = 2;
		mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
		mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
		mlx_loop_hook(img.mlx, ft_animation, &img);
		mlx_loop(img.mlx);
	}
}
