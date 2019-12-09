/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:53:48 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/09 07:21:55 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhook(int keycode, t_map *e)
{
	if (keycode == 126)
		e->shift_y -= 10;
	else if (keycode == 125)
		e->shift_y += 10;
	else if (keycode == 123)
		e->shift_x -= 10;
	else if (keycode == 122)
		e->shift_x += 10;
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
