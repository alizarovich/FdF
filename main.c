/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 20:03:41 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Main Function
*/

int		main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 4)
	{
		ft_putendl("usage: ./fdf [file] [color1] [color2]");
		return (1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	set_color(1, argv[2], map);
	set_color(2, argv[3], map);
	if (!(read_map_file(argv[1], map)))
	{
		ft_putendl("error");
		exit(1);
		return (1);
	}
	init_mlx_window(map);
	free(map);
	return (0);
}
