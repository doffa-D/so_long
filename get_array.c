/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:03:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/21 16:56:26 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char **get_array(t_data *img)
{
    int i = 0;
    int z = 0;
    int c = 0;
    int p = 0;
    int e = 0;
    int fd = open("map.ber" , O_RDWR);
    char **map = malloc(1000);
    map[z] = get_next_line(fd);

    while(map[z])
    {
        if(z==0)
        {
            i = 0;
            while(map[z][i])
            {
                if(map[z][i] != '1' && map[z][i] != '\n')
                    exit(0);
                i++;
            }
        }
        if(map[z][0] != '1' && map[z][0] != '\n')
                    exit(0);

        if(map[z][strlen(map[z])-2] != '1' && map[z][strlen(map[z])-2] != '\n')
                    exit(0);

        z++;
        map[z] = get_next_line(fd);
    }
    z--;
    i = 0;
    while(map[z][i])
    {
        if(map[z][i] != '1' && map[z][i] != '\n')
                    exit(0);

        i++;
    }
    z++;
    img->map.xsize=z;
    img->map.linesize=ft_strlen(map[0]) - 1;
    img->map.map = map;
    i = 0;
    z = 0;
    while(img->map.map[z])
    {
        // printf("%s",map[z]);
        i = 0;
        while(img->map.map[z][i])
        {
            if(img->map.map[z][i] == 'P')
                p++;
            if(img->map.map[z][i] == 'E')
                e++;
            if(img->map.map[z][i] == 'C')
                c++;
            i++;
        }
        z++;
    }
    if(e >= 2 || e == 0)
    {
        printf("\n -------------- \n | 🤨 %d door | \n -------------- \n",e);
        exit(0);
    }    
    if(p >= 2 || p == 0)
    {
        printf("\n -------------- \n | 🤨 %d Player | \n -------------- \n",p);
        exit(0);
    }
    if(c == 0)
    {
        printf("\n -------------- \n | 😳 0 coins | \n -------------- \n");
        exit(0);
    }
    check();
    return map;
}