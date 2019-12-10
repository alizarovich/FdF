/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:55:05 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/09 18:27:21 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Gradient generate
*/

int			gradient(int startcolor, int endcolor, int len, int pix)
{
	double		increment[3];
	int			new[3];
	int			newcolor;

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

void		isometric(float *x, float *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(map->angle);
	*y = (*x + *y) * sin(map->angle) - z * map->z_coeff;
}

void		rotation(float *x, float *y, t_map *map)
{
	*x = *x * cos(map->rotation) + *y * sin(map->rotation);
	*y = -*x * sin(map->rotation) + *y * cos(map->rotation);
}

float		max_num(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
** Bresenham’s Line Generation
*/

void		draw_line(float x1, float y1, float x2, float y2, t_map *map)
{
	float		x_step;
	float		y_step;
	float		max;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = max_num(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;

	while (ft_abs(x2 - x1) > 0 || ft_abs(y2 - y1) > 0)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, 0xFFFF00); //gradient(0x0000FF, 0xFFFF00, max, z1)); // max z, current z
		x1 += x_step;
		y1 += y_step;
	}
}

void		process_points(float x1, float y1, float x2, float y2, t_map *map)
{
	int			z1;
	int			z2;

	z1 = map->z_data[(int)y1][(int)x1];
	z2 = map->z_data[(int)y2][(int)x2];

	// zoom
	x1 *= map->zoom;
	y1 *= map->zoom;
	x2 *= map->zoom;
	y2 *= map->zoom;

	// 3D
	isometric(&x1, &y1, z1, map);
	isometric(&x2, &y2, z2, map);

	//shift
	x1 += map->shift_x;
	y1 += map->shift_y;
	x2 += map->shift_x;
	y2 += map->shift_y;

	//rotation
	//rotation(&x1, &y1, map);
	draw_line(x1, y1, x2, y2, map);

}
/*
** Function to draw map
*/

void		draw_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				process_points(x, y, x + 1, y, map);
			if (y < map->height - 1)
				process_points(x, y, x, y + 1, map);
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
	map->zoom = 50;
	map->z_coeff = 5;
	map->angle = 0.8;
	map->shift_x = 100;
	map->shift_y = 100;
	map->rotation = 0;
	mlx_string_put(map->mlx, map->win, 100, 92, 0xFFFFDF, "Hello");
	draw_map(map);
	mlx_key_hook(map->win, ft_keyhook, map);
	//mlx_mouse_hook(map->win, ft_mouse_hook, map);
	//mlx_hook(map->win, 2, (1L << 0), ft_keyhook_pressed, map);
	//mlx_hook(map->win, 3, (1L << 1), ft_keyhook_release, map);
	mlx_loop(map->mlx);
	return (0);
}
