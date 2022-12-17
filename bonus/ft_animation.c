/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:01:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 22:19:10 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (img->mob.locali == img->enemy1.locali * 50
		&& img->enemy1.localz * 50 == img->mob.localz)
	{
		ft_printf("\033[0;31m --------\n The enemy killed you\n--------");
		exit(0);
	}
}

char	*pr(char *str, int num)
{
	char	*str2;
	char	*jo;

	str2 = ft_itoa(num);
	jo = ft_strjoin(str, str2);
	free(str2);
	return (jo);
}

void	putse(t_data *img, int k)
{
	char	*str;

	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 150, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->wallcoin.img,
		(50 * img->map.linesize) - 250, 0);
	str = pr("PM:", k);
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 120,
		30, 0x007A07D2, str);
	free(str);
	str = pr("Coins:", img->coin1.i);
	mlx_string_put(img->mlx, img->win, (50 * img->map.linesize) - 240,
		30, 0x007A07D2, str);
	free(str);
}

int	ft_animation(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->back.img, 0, 0);
	img->enemy1.img = mlx_xpm_file_to_image(img->mlx, img->redenm.map[(img->test.x / 5) % 6], &img->enemy1.img_width, &img->enemy1.img_height);
	img->coin2.img = mlx_xpm_file_to_image(img->mlx,
			img->redcoin.map[(img->test.x / 5) % 6],
			&img->coin2.img_width, &img->coin2.img_height);
	animove(img);
	protect(img);
	whill(img);
	putse(img, img->pm);
	if (img->mob.is == 1 && !(img->map.map[img->mob.localz / 50]
			[img->mob.locali / 50] == 'Z'))
		mlx_put_image_to_window(img->mlx, img->win, img->mob.img,
			img->mob.locali, img->mob.localz);
	else if (!(img->map.map[img->mob.localz / 50][img->mob.locali / 50] == 'Z'))
		mlx_put_image_to_window(img->mlx, img->win, img->mob2.img,
			img->mob.locali, img->mob.localz);
	you(img);
	img->test.x++;
	return (0);
}
