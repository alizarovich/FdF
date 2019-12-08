/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:08:51 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 13:11:55 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // TODO DELETE THAT LINE!

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
** Function to connect lines to each other
*/

char			*check_map_file(char *filename)
{
	int			fd;
	char		*line;
	char		*result;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (NULL);

	result = ft_strnew(0);
	while (ft_get_next_line(fd, &line) > 0)
	{
		result = join_lines(line, result);
	}
	printf("%s\n", result);  // TODO DELETE THAT LINE!
	close(fd);
	return (result);
}
