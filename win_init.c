/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:32:22 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/11 12:53:23 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function to print tips
*/

void			print_labels(t_map *map)
{
	if (map->show_help)
	{
		mlx_string_put(map->mlx, map->win, 10, 10,
		0xFFFFDF, "arrows      move the map");
		mlx_string_put(map->mlx, map->win, 10, 30,
		0xFFFFDF, "'+' '-'     zoom in/out");
		mlx_string_put(map->mlx, map->win, 10, 50,
		0xFFFFDF, "'A' 'Z'     change z ratio");
		mlx_string_put(map->mlx, map->win, 10, 70,
		0xFFFFDF, "'S' 'X'     rotate");
		mlx_string_put(map->mlx, map->win, 10, 90,
		0xFFFFDF, "'P'         change projection");
		mlx_string_put(map->mlx, map->win, 10, 110,
		0xFFFFDF, "'F'         pay respects");
		mlx_string_put(map->mlx, map->win, 10, 130,
		0xFFFFDF, "'esc'       exit");
	}
	else
		mlx_string_put(map->mlx, map->win, 10, 10,
		0xFFFFDF, "press 'h' for help");
}

/*
** Function to set color
*/

void			set_color(int color_num, char *color, t_map *map)
{
	int			set_color;

	if (ft_strequ(color, "red"))
		set_color = 0xFF0000;
	else if (ft_strequ(color, "orange"))
		set_color = 0xFFa500;
	else if (ft_strequ(color, "yellow"))
		set_color = 0xFFFF00;
	else if (ft_strequ(color, "green"))
		set_color = 0x00FF00;
	else if (ft_strequ(color, "blue"))
		set_color = 0x0000FF;
	else if (ft_strequ(color, "violet"))
		set_color = 0x7F00FF;
	else
		set_color = 0xFFFFFF;
	if (color_num == 2)
		map->color_end = set_color;
	else
		map->color_start = set_color;
}

/*
** Function to init map with params
*/

void			map_init(t_map *map)
{
	map->show_help = 0;
	map->z_coeff = 5;
	map->angle = 0.8;
	map->rotation = 0;
	map->projection = 0;
	map->zoom = 50;
	map->win_w = 1500;
	map->win_h = 1000;
	map->shift_x = map->win_w / 4;
	map->shift_y = map->win_h / 3;
}

/*
** Function to init minilibx window
*/

int				init_mlx_window(t_map *map)
{
	map_init(map);
	map->mlx = mlx_init();
	if (!(map->win = mlx_new_window(map->mlx, map->win_w, map->win_h, "FdF")))
		return (0);
	draw_map(map);
	mlx_key_hook(map->win, ft_keyhook, map);
	mlx_loop(map->mlx);
	return (0);
}
