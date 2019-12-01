/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/29 19:01:19 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int		main(void)
{

	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Hello World");
	mlx_loop(mlx);
	return (0);
}
*/

/*
** Function to connect lines to each other
** Return line
*/


char		*join_lines(char *line, char *prevlines)
{
	char		*temp;

	temp = ft_strdup(prevlines);
	ft_strdel(&prevlines);
	prevlines = ft_strjoin(temp, line);
	ft_strdel(&temp);
	ft_strdel(&line);
	return (prevlines);
}


#include <stdio.h>
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
		printf("%s\n", line);
		//result = join_lines(line, result);
	}
	printf("%s\n", result);
	close(fd);
	return (result);
}

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
	return (0);
}
