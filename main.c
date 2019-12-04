/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/04 12:33:44 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function to connect lines to each other
** Return line
*/

/*
char		*join_lines(char *line, char *prevlines)
{
	char		*temp;

	temp = prevlines;
	prevlines = ft_strjoin(temp, line);
	ft_strdel(&temp);
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
		result = join_lines(line, result);
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
	//system("leaks fdf");
	return (0);
}
*/
#include "minilibx/mlx.h"

int ft_round(double number)
{
	return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

int gradient(int startcolor, int endcolor, int len, int pix)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = (double)((endcolor >> 16) - (startcolor >> 16)) / (double)len; // for red
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - ((startcolor >> 8) & 0xFF)) / (double)len; // for green
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) / (double)len; // for blue

	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);

	newcolor = ((new[0]) << 16) + ((new[1]) << 8) + (new[2]);
	return (newcolor);
}

void		draw_line(void *mlx, void *window, int x1, int y1, int x2, int y2)
{
	while ( x2 >= x1 || y2 >= y1)
	{
		mlx_pixel_put (mlx, window, x1, y1, gradient(0x0000FF, 0xFFFF00, 90, y2-y1));
		if (x1 <= x2)
			x1++;
		if (y1 <= y2)
			y1++;
	}
}

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	mlx_string_put(mlx, window, 100, 92, 0xFFFFDF, "Hello");
	draw_line(mlx, window, 10, 10, 10, 100);
	mlx_loop(mlx);
	return (0);
}

