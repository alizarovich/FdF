/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:22:19 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 13:10:26 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# include <stdio.h> // TODO DELETE THIS LINE!

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			x_cur;
	int			y_cur;
}				t_point;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			zoom;
	int			width;
	int			height;
	int			shift_x;
	int			shift_y;
	float		angle;
	float		z_coeff;
	float		rotation;
	int			**z_data;
	int			z_min;
	int			z_max;
	int			show_help;
	int			projection;
	t_point		p1;
	t_point		p2;
}				t_map;

void			draw_map(t_map *map);
int				ft_keyhook(int keycode, t_map *e);
int				ft_mouse_hook(int keycode, int x, int y, t_map *map);
int				ft_keyhook_pressed(int keycode, t_map *e);
int				ft_keyhook_release(int keycode, t_map *e);
int				init_mlx_window(t_map *map);
void			projection(float *x, float *y, int z, t_map *map);
void			print_labels(t_map *map);
int				read_map_file(char *filename, t_map *map);

#endif
