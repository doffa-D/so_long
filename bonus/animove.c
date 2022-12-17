/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:01:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 13:25:59 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moveright(t_data *img);
void	moveup(t_data *img);
void	moveleft(t_data *img);

void	movedown(t_data *img)
{
	if (img->map.map[img->enemy1.localz + 1][img->enemy1.locali] != '1'
		&& img->map.map[img->enemy1.localz + 1][img->enemy1.locali] != 'Z')
		img->enemy1.localz++;
	else
		moveleft(img);
}

void	moveup(t_data *img)
{
	if (img->map.map[img->enemy1.localz - 1][img->enemy1.locali] != '1'
		&& img->map.map[img->enemy1.localz - 1][img->enemy1.locali] != 'Z')
		img->enemy1.localz--;
	else
		moveright(img);
}

void	moveright(t_data *img)
{
	if (img->map.map[img->enemy1.localz][img->enemy1.locali + 1] != '1'
		&& img->map.map[img->enemy1.localz][img->enemy1.locali + 1] != 'Z')
		img->enemy1.locali++;
	else
		movedown(img);
}

void	moveleft(t_data *img)
{
	if (img->map.map[img->enemy1.localz][img->enemy1.locali - 1] != '1'
		&& img->map.map[img->enemy1.localz][img->enemy1.locali - 1] != 'Z')
		img->enemy1.locali--;
	else
		moveup(img);
}

void	animove(t_data *img)
{
	static int	p;
	static int	q;

	if (p % 50 == 5)
	{
		q++;
		if (q > 10)
			q = 0;
		if (q % 4 == 0)
			moveup(img);
		else if (q % 4 == 1)
			movedown(img);
		else if (q % 4 == 2)
			moveright(img);
		else if (q % 4 == 3)
			moveleft(img);
	}
	p++;
	if (p > 50)
		p = 0;
}
