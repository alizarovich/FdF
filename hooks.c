/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:53:48 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 13:10:02 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function to check if ESC is pressed
*/

int		ft_keyhook_pressed(int keycode, t_map *e)
{
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
