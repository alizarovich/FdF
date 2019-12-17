/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:08:51 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/17 15:51:40 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function to find min and max z
*/

void			find_extremum_z(t_map *map)
{
	int			i;
	int			j;
	int			z_min;
	int			z_max;

	j = 0;
	z_min = 2147483647;
	z_max = -2147483648;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->z_data[j][i] > z_max)
			{
				z_max = map->z_data[j][i];
			}
			if (map->z_data[j][i] < z_min)
				z_min = map->z_data[j][i];
			i++;
		}
		j++;
	}
	map->z_min = z_min;
	map->z_max = z_max;
}

/*
** Function to read and check map file
*/

int				get_map_size(char *filename, t_map *map)
{
	int			fd;
	char		*line;
	int			height;
	int			width;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (0);
	height = 0;
	width = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (!width)
			width = ft_count_words(line, ' ');
		if (width != ft_count_words(line, ' '))
			return (0);
		height++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	map->height = height;
	map->width = width;
	close(fd);
	return (1);
}

/*
** Function to add map data
*/

void			save_map_data(int *z_row, char *line)
{
	int			i;
	int			test;
	char		**nums;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		test = ft_atoi(nums[i]);
		z_row[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

/*
** Function to get map data
*/

int				get_map_data(char *filename, t_map *map)
{
	int			fd;
	int			i;
	char		*line;

	if (!(map->z_data = (int **)malloc(sizeof(int*)
	* (map->height + 1))))
		return (0);
	i = 0;
	while (i <= map->height)
		if (!(map->z_data[i++] = (int*)malloc(sizeof(int)
		* (map->width + 1))))
			return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (0);
	i = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		save_map_data(map->z_data[i++], line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}

/*
** Function to read and check map file
*/

int				read_map_file(char *filename, t_map *map)
{
	if (get_map_size(filename, map) == 0)
	{
		ft_putendl("map file is damaged");
		return (0);
	}
	get_map_data(filename, map);
	find_extremum_z(map);
	return (1);
}
