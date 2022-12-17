/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:51:34 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/12/16 17:44:27 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	x(void)
{
	ft_printf("\033[0;32m Some xpm file are empty\n\n\n");
	exit(0);
}

void	protect(t_data *img)
{
	if (img->mob.img == 0 || img->mob2.img == 0 || img->enemy1.img == 0)
		x();
	if (img->coin1.img == 0 || img->craves.img == 0)
		x();
	if (img->back.img == 0 || img->coinback.img == 0 || img->wall.img == 0)
		x();
	if (img->wallcoin.img == 0 || img->dor.img == 0
		|| img->dorclose.img == 0 || img->test.img == 0)
		x();
}
