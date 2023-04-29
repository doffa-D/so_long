/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:31:21 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/29 20:05:59 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# define COIN_ANIMATION 1
# define ENEMY_ANIMATION 1

typedef struct gs_data
{
	void	*img;
	int		img_width;
	int		img_height;
	int		locali;
	int		localz;
	int		i;
	int		z;
	int		y;
	int		x;
	int		is;
}	t_photo;

typedef struct m_data
{
	char	**map;
	int		xsize;
	int		linesize;
	int		locali;
	int		localz;
	int		i1;
	int		z1;
}	t_map;

typedef struct s_data
{
	void	*img;
	void	*imghero;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		pm;
	t_map	map;
	t_photo	mob;
	t_photo	mob2;
	t_photo	enemy1;
	t_photo	coin1;
	t_photo	coin2;
	t_photo	craves;
	t_photo	back;
	t_photo	coinback;
	t_photo	wall;
	t_photo	wallcoin;
	t_photo	dor;
	t_photo	dorclose;
	t_photo	test;
	t_map	redenm;
	t_map	redcoin;
}	t_data;

int		ft_strlen(char *str);
int		showimage(t_data *img);

char	*ft_strdup(char *str);
char	**get_array(t_data *img, char *argv);
char	*ft_itoa(int n);
void	check(char *argv);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_animation(t_data *img);
int		key_hook(int keycode, t_data *img);
void	mvplayer(t_data *img, int keycode);
void	check_bonus(char *argv);
void	get_array_bonus(t_data *img, char *argv);
int		ft_close(void);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
void	protect(t_data *img);
void	animove(t_data *img);
void	redanime(t_data *img);
char	*ft_strtrim(char *s1, char *set);
void	animove(t_data *img);
void	whill(t_data *img);
void	freedata(t_data *img);
// get_next_line
char	*get_next_line(int fd);

// ft_printf
int		ft_printf(const char *src, ...);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif
