/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:22:19 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/12/08 12:51:09 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			width;
	int			hight;
	int			**z_values;
}				t_map;

#endif
