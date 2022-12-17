/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:57:14 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 15:11:12 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enem(t_data *img)
{
	img->coin1.img = mlx_xpm_file_to_image(img->mlx, "xpm/coin1.xpm",
			&img->coin1.img_width, &img->coin1.img_height);
	img->enemy1.img = mlx_xpm_file_to_image(img->mlx, "xpm/enm1.xpm",
			&img->enemy1.img_width, &img->enemy1.img_height);
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
	protect(img);
	enem(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		if (!(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))))
			exit(0);
		get_array_bonus(&img, argv[1]);
		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, 50 * img.map.linesize,
				50 * img.map.xsize, "./so_long");
		img.img = mlx_new_image(img.mlx, img.map.linesize, img.map.xsize);
		put_image(&img);
		showimage(&img);
		redanime(&img);
		img.pm = 0;
		img.wall.y = 2;
		mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
		mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
		mlx_loop_hook(img.mlx, ft_animation, &img);
		mlx_loop(img.mlx);
	}
	else
		exit (0);
}
