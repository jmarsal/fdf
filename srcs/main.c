/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/28 01:15:49 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_mlx		*mlx;
	t_coords	*coords;
	t_colors	color;

	if (ac == 2)
	{
		(void)av;
		coords = init_coords();
		color = init_colors();
		mlx = init_mlx();
		mlx_key_hook(mlx->mlx_win, key_hook, mlx);
		mlx_mouse_hook(mlx->mlx_win, mouse_hook, mlx);
		draw_windows(coords, mlx, color);
		mlx_hook(mlx->mlx_win, 17, 1L << 17, close_win, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n---> usage : ./fdf exemple.fdf\n");
	return (0);
}
