/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 15:19:56 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Main Function
*/

int		main(int argc, char **argv)
{
	t_map		*current_map;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file]");
		return (1);
	}
	// read file & check if correct

	current_map = (t_map *)malloc(sizeof(t_map));
	if (!(read_map_file(argv[1], current_map)))
	{
		ft_putendl("error");
		exit(1);
		return (1);
	}
	printf("height:\t\t%i\n", current_map->height); // TODO Delete this line!
	printf("width:\t\t%i\n", current_map->width); // TODO Delete this line!
	free(current_map);
	system("leaks fdf");
	return (0);
}
