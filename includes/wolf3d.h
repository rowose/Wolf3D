/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:10:07 by jgaillar          #+#    #+#             */
/*   Updated: 2017/08/07 11:13:07 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H
# define WIDTH 320
# define LENGTH 200
# define BUFF_SIZE 0xfffff
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <../libft/libft.h>

# define MT 1
# define ALIAS(var, name) typeof(var) name = var

typedef struct		s_wolf
{
	float			wallh;
	float			playerh;
	float			fov;
	float			angle;
	float			posx;
	float			posy;
	float			dispw;
	float			angleray;
}					t_wolf;

typedef struct		s_draw
{
	float			Xa;
	float			Ya;
	float			Xi;
	float			Yi;
	int			x;
	int			y;
	float			angle;
	float			dist;
	float			disthor;
	float			distver;
}					t_draw;

typedef struct		s_map
{
	size_t			x;
	size_t			y;
	size_t			maxx;
	size_t			maxy;
	int				**array;
}					t_map;

typedef struct		s_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				size;
	int				color[51];
	char			*data;
}					t_img;

typedef	struct		s_stuff
{
	t_img			img;
	t_map			map;
	t_wolf			wolf;
	pthread_t		*th;
	int				fd;
	char			buf[BUFF_SIZE + 1];
}					t_stuff;

typedef	struct		s_tmp
{
	t_stuff			*stuff;
	int			start;
	int			end;
}					t_tmp;

void				ft_exit(int code);
int					**malloc2d(t_map *map);
void				free_2d(char **array);
size_t				lentab(char *buf);
size_t				linelength(char *buf);
void				putintab(t_stuff *stuff);
void				init_struct(t_stuff *stuff);
void				init_wolf(t_stuff *stuff);
void				setborders(t_stuff *stuff);
void				wolf3d(t_stuff *stuff);
void				draw_wolf(t_tmp tmp, t_img *img);
int				check_hor(t_wolf wolf, t_draw *draw, t_map map);
int				check_ver(t_wolf wolf, t_draw *draw, t_map map);
void				correc_dist(t_draw *draw, t_stuff *stuff);
void				create_image(t_stuff *stuff);
void				mlx_pixel_put_to_image(t_img img, int x, int y, int color);
void				aff(t_draw *draw, t_stuff *stuff, t_img *img, int x);

#endif
