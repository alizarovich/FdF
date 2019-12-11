/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:53:48 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 20:01:31 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keyhook_1(int keycode, t_map *e)
{
	if (keycode == 4 && e->show_help == 1)
		e->show_help = 0;
	else if (keycode == 4 && e->show_help == 0)
		e->show_help = 1;
	else if (keycode == 0)
		e->z_coeff += 1;
	else if (keycode == 6)
		e->z_coeff -= 1;
	else if (keycode == 1)
		e->rotation += 0.1;
	else if (keycode == 7)
		e->rotation -= 0.1;
}

void	ft_keyhook_2(int keycode, t_map *e)
{
	if (keycode == 35 && e->projection == 1)
		e->projection = 0;
	else if (keycode == 35 && e->projection == 0)
		e->projection = 1;
	else if (keycode == 125)
		e->shift_y += 10;
	else if (keycode == 126)
		e->shift_y -= 10;
	else if (keycode == 123)
		e->shift_x -= 10;
	else if (keycode == 124)
		e->shift_x += 10;
	else if (keycode == 69 || keycode == 24)
		e->zoom *= 1.5;
	else if (keycode == 78 || keycode == 27)
		e->zoom /= 1.5;
}

int		ft_keyhook(int keycode, t_map *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode <= 23)
		ft_keyhook_1(keycode, e);
	else
		ft_keyhook_2(keycode, e);
	mlx_clear_window(e->mlx, e->win);
	draw_map(e);
	return (0);
}
