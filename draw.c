/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:55:05 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/09 07:37:00 by kgavrilo         ###   ########.fr       */
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

void		isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

/*
** Bresenham’s Line Generation
*/

void		draw_line(int x1, int y1, int x2, int y2, t_map *map)
{
	int		m;
	int		slope_error;
	int		x;
	int		y;
	int		z1;
	int		z2;

	z1 = map->z_data[y1][x1];
	z2 = map->z_data[y2][x2];

	// zoom
	x1 *= map->zoom;
	y1 *= map->zoom;
	x2 *= map->zoom;
	y2 *= map->zoom;

	// 3D
	isometric (&x1, &y1, z1);
	isometric (&x2, &y2, z2);

	//shift
	x1 += map->shift_x;
	y1 += map->shift_y;
	x2 += map->shift_x;
	y2 += map->shift_y;

	m = 2 * (y2 - y1);
	slope_error = m - (x2 - x1);
	x = x1;
	y = y1;
	while (x <= x2)
	{
		slope_error += m;
		mlx_pixel_put (map->mlx, map->win, x, y, gradient(0x0000FF, 0xFFFF00, 90, z2 - z1));
		if (slope_error >= 0)
		{
			y++;
			slope_error -= 2 * (x2 - x1);
		}
		x++;
	}
}

/*
** Function to draw map
*/

void		draw_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while(y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}

/*
** Function to init minilibx window
*/

int			init_mlx_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!(map->win = mlx_new_window(map->mlx, 1000, 1000, "Title")))
		return (0);
	map->zoom = 20;
	mlx_string_put(map->mlx, map->win, 100, 92, 0xFFFFDF, "Hello");
	draw_map(map);
	mlx_key_hook(map->win, ft_keyhook, map);
	mlx_mouse_hook(map->win, ft_mouse_hook, map);
	mlx_hook(map->win, 2, (1L << 0), ft_keyhook_pressed, map);
	mlx_hook(map->win, 3, (1L << 1), ft_keyhook_release, map);
	mlx_loop(map->mlx);
	return(0);
}
