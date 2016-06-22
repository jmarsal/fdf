/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 12:05:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

void		mlx_start(t_app *app)
{
	if (!(app->win = init_win(app->win->zoom, app->win->width, app->win->height,
		app->win->move_z)) || !(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	// mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
	mlx_hook(app->mlx->mlx_win, 2, 3, key_funct, app);
	mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(app->mlx->mlx_ptr);
}
