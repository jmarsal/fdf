/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/27 23:26:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*init_mlx()
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx*)malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	if ((mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT,
										"fdf by jmarsal")) == NULL)
		return (NULL);
	return (mlx);
}

t_colors	init_colors()
{
	t_colors	color;

	//if ((color = (t_colors*)malloc(sizeof(t_colors))) == NULL)
	//	return (NULL);
	color.color1 = 0x00239d;
	color.color2 = 0xffffff;
	color.color3 = 0xa10404;
	return (color);
}

t_coords	*init_coords()
{
	t_coords	*coords;

	if ((coords = (t_coords*)malloc(sizeof(t_coords))) == NULL)
		return (NULL);
	coords->x = 0;
	coords->y = 0;
	coords->next = NULL;
	return (coords);
}

int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}