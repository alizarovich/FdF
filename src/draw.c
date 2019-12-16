/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:55:05 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 17:55:32 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Gradient generate
** pix - interpolation of z
*/

int			gradient(t_map *map, float x, float y)
{
	double		increment[3];
	int			new[3];
	int			newcolor;
	int			range;
	float		pix;

	range = ft_abs((map->z_max - map->z_min));
	pix = ft_abs(map->z_min) + map->p1.z + (map->p2.z - map->p1.z)
	* (sqrt(powf(x - map->p1.x_cur, 2) + powf(y - map->p1.y_cur, 2)))
	/ (sqrt(powf(map->p2.x_cur - map->p1.x_cur, 2)
	+ powf(map->p2.y_cur - map->p1.y_cur, 2)));
	increment[0] = (double)((map->color_end >> 16) -
	(map->color_start >> 16)) / (double)range;
	increment[1] = (double)(((map->color_end >> 8) & 0xFF) -
	((map->color_start >> 8) & 0xFF)) / (double)range;
	increment[2] = (double)((map->color_end & 0xFF) -
	(map->color_start & 0xFF)) / (double)range;
	new[0] = (map->color_start >> 16) + ft_round(pix * increment[0]);
	new[1] = ((map->color_start >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (map->color_start & 0xFF) + ft_round(pix * increment[2]);
	newcolor = ((new[0]) << 16) + ((new[1]) << 8) + (new[2]);
	return (newcolor);
}

/*
** Bresenham’s Line Generation
*/

void		draw_line(t_map *map)
{
	float		x_step;
	float		y_step;
	float		x;
	float		y;
	float		max;

	x = map->p1.x_cur;
	y = map->p1.y_cur;
	x_step = map->p2.x_cur - x;
	y_step = map->p2.y_cur - y;
	max = ft_maxnum(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while (ft_abs(map->p2.x_cur - x) > 0 || ft_abs(map->p2.y_cur - y) > 0)
	{
		mlx_pixel_put(map->mlx, map->win, x, y, gradient(map, x, y));
		x += x_step;
		y += y_step;
	}
}

/*
** Function to change params for each point - zoom, projection, rotation
*/

void		process_points(t_map *map)
{
	map->p1.z = map->z_data[(int)(map->p1.y)][(int)(map->p1.x)];
	map->p2.z = map->z_data[(int)(map->p2.y)][(int)(map->p2.x)];
	map->p1.x_cur = map->p1.x * map->zoom;
	map->p1.y_cur = map->p1.y * map->zoom;
	map->p2.x_cur = map->p2.x * map->zoom;
	map->p2.y_cur = map->p2.y * map->zoom;
	projection(&(map->p1.x_cur), &(map->p1.y_cur), map->p1.z, map);
	projection(&(map->p2.x_cur), &(map->p2.y_cur), map->p2.z, map);
	map->p1.x_cur += map->shift_x;
	map->p1.y_cur += map->shift_y;
	map->p2.x_cur += map->shift_x;
	map->p2.y_cur += map->shift_y;
	rotation(&(map->p1.x_cur), &(map->p1.y_cur), map);
	rotation(&(map->p2.x_cur), &(map->p2.y_cur), map);
	draw_line(map);
}

/*
** Function to draw map
*/

void		draw_map(t_map *map)
{
	map->p1.y = 0;
	while (map->p1.y < map->height)
	{
		map->p1.x = 0;
		while (map->p1.x < map->width)
		{
			if (map->p1.x < map->width - 1)
			{
				map->p2.x = map->p1.x + 1;
				map->p2.y = map->p1.y;
				process_points(map);
			}
			if (map->p1.y < map->height - 1)
			{
				map->p2.x = map->p1.x;
				map->p2.y = map->p1.y + 1;
				process_points(map);
			}
			map->p1.x += 1;
		}
		map->p1.y += 1;
	}
	print_labels(map);
}
