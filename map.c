/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:08:51 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 14:08:31 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function to connect lines to each other
** Return line
*/

static char		*join_lines(char *line, char *prevlines)
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
	}
	current_map->height = height;
	current_map->width = width;
	close(fd);
	ft_strdel(&line);
	return(1);
}

/*
** Function to read and check map file
*/

int				read_map_file(char *filename, t_map *current_map)
{

	get_map_size(filename, current_map);

	return (1);
}
