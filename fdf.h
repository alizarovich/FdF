/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:22:19 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/10 20:01:43 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	float		x_cur;
	float		y_cur;
}				t_point;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	float		zoom;
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
	int			color_start;
	int			color_end;
	t_point		p1;
	t_point		p2;
}				t_map;

void			draw_line(t_map *map);
void			draw_map(t_map *map);
void			find_extremum_z(t_map *map);
int				get_map_size(char *filename, t_map *map);
int				get_map_data(char *filename, t_map *map);
int				gradient(t_map *map, float x, float y);
int				ft_keyhook(int keycode, t_map *e);
void			ft_keyhook_1(int keycode, t_map *e);
void			ft_keyhook_2(int keycode, t_map *e);
int				ft_mouse_hook(int keycode, int x, int y, t_map *map);
int				ft_keyhook_pressed(int keycode, t_map *e);
int				ft_keyhook_release(int keycode, t_map *e);
int				init_mlx_window(t_map *map);
void			map_init(t_map *map);
void			process_points(t_map *map);
void			projection(float *x, float *y, int z, t_map *map);
void			print_labels(t_map *map);
int				read_map_file(char *filename, t_map *map);
void			rotation(float *x, float *y, t_map *map);
void			save_map_data(int *z_row, char *line);
void			set_color(int color_num, char *color, t_map *map);

#endif
