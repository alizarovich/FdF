/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:53:48 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 13:09:50 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhook(int keycode, t_map *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 4 && e->show_help == 1)
		e->show_help = 0;
	else if (keycode == 4 && e->show_help == 0)
		e->show_help = 1;
	else if (keycode == 35 && e->projection == 1)
		e->projection = 0;
	else if (keycode == 35 && e->projection == 0)
		e->projection = 1;
	else if (keycode == 125)
		e->shift_y += 10;
	else if (keycode == 126)
		e->shift_y -= 10;
	else if (keycode == 125)
		e->shift_y += 10;
	else if (keycode == 123)
		e->shift_x -= 10;
	else if (keycode == 124)
		e->shift_x += 10;
	else if (keycode == 69 || keycode == 24)
		e->zoom += 10;
	else if (keycode == 78 || keycode == 27)
		e->zoom -= 10;
	else if (keycode == 0)
		e->z_coeff += 1;
	else if (keycode == 6)
		e->z_coeff -= 1;
	else if (keycode == 1)
		e->rotation += 0.1;
	else if (keycode == 7)
		e->rotation -= 0.1;
	printf("%i\n", keycode); // TODO DELETE THIS LINE!
	mlx_clear_window(e->mlx, e->win);
	draw_map(e);
	return (0);
}

/*
** Function to check if ESC is pressed
*/

int		ft_keyhook_pressed(int keycode, t_map *e)
{
	if (e)
		keycode == 53 ? exit(0) : 0;
	return (0);
}

/*
** Function to check if ESC is pressed
*/

int		ft_keyhook_release(int keycode, t_map *e)
{
	if (e)
		printf("%d\n", keycode); // TODO DELETE THAT LINE!
	return (0);
}

int		ft_mouse_hook(int keycode, int x, int y, t_map *map)
{
	// TODO rotate with mouse
	if (map)
		printf("%i\t%i\t%i\n", keycode, x, y);
	/*
	how mouse works
	get current offset
	get related coordinates
	update offset
	clear window
	redraw map
	*/
return (0);
}

void	print_labels(t_map *map)
{
	if (map->show_help)
	{
		mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFDF, "arrows      move the map");
		mlx_string_put(map->mlx, map->win, 10, 30, 0xFFFFDF, "'+' '-'     zoom in/out");
		mlx_string_put(map->mlx, map->win, 10, 50, 0xFFFFDF, "'A' 'Z'     change z ratio");
		mlx_string_put(map->mlx, map->win, 10, 70, 0xFFFFDF, "'S' 'X'     rotate");
		mlx_string_put(map->mlx, map->win, 10, 90, 0xFFFFDF, "'P'         change projection");

	}
	else
		mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFDF, "press 'h' for help");
}
