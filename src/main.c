/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/20 00:15:03 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_exit(int code)
{
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

static void		ft_usage(void)
{
	ft_putendl("Usage: ./wolf3d <map>");
	ft_exit(0);
}

int				main(int ac, char **av)
{
	t_stuff stuff;
	int i = -1;
	int j = -1;

	if (ac != 2 || !av[1])
		ft_usage();
	if ((stuff.fd = open(av[1], O_RDONLY)) < 0)
		ft_exit(-1);
	stuff.buf[read(stuff.fd, stuff.buf, BUFF_SIZE)] = '\0';
	close(stuff.fd);
	init_struct(&stuff);
	while (++i < stuff.map.maxy)
	{
		j = -1;
		while (++j < stuff.map.maxx)
		{
			ft_putnbr(stuff.map.array[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	// stuff.img.mlx_ptr = mlx_init();
	// stuff.img.win_ptr = mlx_new_window(stuff.img.mlx_ptr, WIDTH, LENGTH,\
	// 		"WOLF3D");
	// controlhelp();
	// mlx_hook(stuff.img.win_ptr, 2, (1L << 0), hooks, &stuff);
	// mlx_hook(stuff.img.win_ptr, 6, (1L << 6), mouse_hook, &stuff);
	// mlx_hook(stuff.img.win_ptr, 4, (1L << 2), zoom, &stuff);
	// mlx_loop(stuff.img.mlx_ptr);
	return (0);
}