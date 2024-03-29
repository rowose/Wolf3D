/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:06:24 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/19 22:06:25 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			mlx_pixel_put_to_image(t_img img, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIDTH * LENGTH * img.bits_per_pixel / 8;
	if (x < 0 || y < 0 || y * img.size_line + x * img.bits_per_pixel / 8 > \
		img_size
		|| x >= img.size_line / (img.bits_per_pixel / 8) || y >= img_size / \
		img.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = img.bits_per_pixel / 8;
	img.data[y * img.size_line + x * bit_pix] = color1;
	img.data[y * img.size_line + x * bit_pix + 1] = color2;
	img.data[y * img.size_line + x * bit_pix + 2] = color3;
}

void			aff(t_stuff *e)
{
	int i;
	int j;

	i = -1;
	j = e->draw.start - 1;
	while (++i < e->draw.start)
		mlx_pixel_put_to_image(e->img, e->map.x, i, 0x547681);
	while (++j < e->draw.end)
	{
		if (e->wolf.side == 0 && e->wolf.stepx == 1)
			mlx_pixel_put_to_image(e->img, e->map.x, j, 0x5b2C6f);
		else if (e->wolf.side == 0 && e->wolf.stepx == -1)
			mlx_pixel_put_to_image(e->img, e->map.x, j, 0x6c3483);
		else if (e->wolf.side == 1 && e->wolf.stepy == 1)
			mlx_pixel_put_to_image(e->img, e->map.x, j, 0x512e5f);
		else if (e->wolf.side == 1 && e->wolf.stepy == -1)
			mlx_pixel_put_to_image(e->img, e->map.x, j, 0x8e44ad);
	}
	j = e->draw.end - 1;
	while (++j < LENGTH)
		mlx_pixel_put_to_image(e->img, e->map.x, j, 0x34495e);
}
