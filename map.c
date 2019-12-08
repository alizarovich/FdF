/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:08:51 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 15:24:06 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO Do I need join_lines func? If not - delete it!
/*
** Function to connect lines to each other
** Return line
*/

char		*join_lines(char *line, char *prevlines)
{
	char		*temp;

	temp = prevlines;
	prevlines = ft_strjoin(temp, line);
	ft_strdel(&temp);
	return (prevlines);
}

/*
** Function to read and check map file
*/

int				get_map_size(char *filename, t_map *current_map)
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
	current_map->height = height;
	current_map->width = width;
	close(fd);
	return (1);
}

/*
** Function to add map data
*/

void				save_map_data(int *z_row, char *line)
{
	int			i;
	char		**nums;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_row[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

/*
** Function to get map data
*/

int				get_map_data(char *filename, t_map *current_map)
{
	int			fd;
	int			i;
	char		*line;

	if (!(current_map->z_data = (int **)malloc(sizeof(int*)
	* (current_map->height + 1))))
		return (0);
	i = 0;
	while (i <= current_map->height)
		if (!(current_map->z_data[i++] = (int*)malloc(sizeof(int)
		* (current_map->width + 1))))
			return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (0);
	i = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		save_map_data(current_map->z_data[i++], line);
		ft_strdel(&line);
	}
	close(fd);
	return (1);
}

/*
** Function to read and check map file
*/

int				read_map_file(char *filename, t_map *current_map)
{
	get_map_size(filename, current_map);
	get_map_data(filename, current_map);
	return (1);
}
