/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 11:59:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

void	mlx_start(t_app *app)
{
	size_t	width;
	size_t	height;

	width = app->win->width <= WIDTH ? app->win->width : WIDTH;
	height = app->win->height <= HEIGHT ? app->win->height : HEIGHT;
	app->win = init_win(width, height, 3, 0);
	if ((app->mlx = init_mlx(app)) == NULL ||
		(app->img = init_img(app)) == NULL)
	{
		print_error(app, 5);
		exit (-1);
	}
	mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
	mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
	mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(app->mlx->mlx_ptr);
}
