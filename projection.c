/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:00:03 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 13:08:01 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		isometric(float *x, float *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(map->angle);
	*y = (*x + *y) * sin(map->angle) - z * map->z_coeff;
}

static void		parallel(float *x, float *y, int z, t_map *map)
{
	*x = *x - z * map->z_coeff;
	*y = *y -1 * 0.5 * z * map->z_coeff;
}

void		projection(float *x, float *y, int z, t_map *map)
{
	if (map->projection == 1)
		isometric(x, y, z, map);
	else
		parallel(x, y, z, map);
}
