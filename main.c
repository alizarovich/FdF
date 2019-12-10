/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/09 16:12:37 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Main Function
*/

int		main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file]");
		return (1);
	}
	// read file & check if correct
	map = (t_map *)malloc(sizeof(t_map));
	if (!(read_map_file(argv[1], map)))
	{
		ft_putendl("error");
		exit(1);
		return (1);
	}
	init_mlx_window(map);
	free(map);
	//system("leaks fdf");
	return (0);
}
