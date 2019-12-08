/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:22:19 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 13:46:24 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h> // TODO DELETE THIS LINE!

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			**z_values;
}				t_map;

int				ft_keyhook_pressed(int keycode, t_map *e);
int				ft_keyhook_release(int keycode, t_map *e);
int				read_map_file(char *filename, t_map *current_map);

#endif
