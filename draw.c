/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:55:05 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 13:08:40 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Gradient generate
*/

int gradient(int startcolor, int endcolor, int len, int pix)
{
	double increment[3];
	int new[3];
	int newcolor;

	// for red, green, and blue accordingly
	increment[0] = (double)((endcolor >> 16) - (startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - ((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) / (double)len;

	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);

	newcolor = ((new[0]) << 16) + ((new[1]) << 8) + (new[2]);
	return (newcolor);
}

/*
** Bresenham’s Line Generation
*/

void		draw_line(int x1, int y1, int x2, int y2, t_map *e)
{
	int		m;
	int		slope_error;
	int		x;
	int		y;

	m = 2 * (y2 - y1);
	slope_error = m - (x2 - x1);
	x = x1;
	y = y1;
	while (x <= x2)
	{
		slope_error += m;
		mlx_pixel_put (e->mlx, e->win, x, y, gradient(0x0000FF, 0xFFFF00, 90, y2 - y));
		if (slope_error >= 0)
		{
			y++;
			slope_error -= 2 * (x2 - x1);
		}
		x++;
	}
}

/*
** Init
*/

int init(t_map *e)
{
	e->mlx = mlx_init();
	if (!(e->win = mlx_new_window(e->mlx, 1000, 1000, "Title")))
		return (0);
	mlx_string_put(e->mlx, e->win, 100, 92, 0xFFFFDF, "Hello");
	draw_line(10, 10, 10, 100, e);
	mlx_hook(e->win, 2, (1L << 0), ft_keyhook_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), ft_keyhook_release, e);
	mlx_loop(e->mlx);
	return(0);
}
