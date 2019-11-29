/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:23 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/29 20:08:56 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Hello World");
	mlx_loop(mlx);
	return (0);
}
