/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 13:10:18 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // TODO DELETE THAT LINE!

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file]");
		return (1);
	}
	// read file & check if correct
	if (check_map_file(argv[1]) == NULL)
	{
		ft_putendl("error");
		exit(1);
		return (1);
	}
	//system("leaks fdf");
	return (0);
}
