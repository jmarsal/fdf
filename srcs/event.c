/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:59:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 13:10:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_z(t_app *app, int keycode)
{
	if (keycode == Z_PLUS)
		app->win->move_z += Z_CHANGE;
	if (keycode == Z_MINUS)
		app->win->move_z -= Z_CHANGE;
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	if (!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
}

void	move_tray(t_app *app, int keycode)
{
	if (keycode == T_LEFT)
		app->win->move_horizontal -= T_MOVE;
	if (keycode == T_RIGHT)
		app->win->move_horizontal += T_MOVE;
	if (keycode == T_UP)
		app->win->move_vertical -= T_MOVE;
	if (keycode == T_DOWN)
		app->win->move_vertical += T_MOVE;
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	if (!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
}

void	get_original_pos(t_app *app)
{
	app->win->zoom_change = 0;
	app->win->move_z = 1;
	app->win->move_horizontal = app->win->width / 4;
	app->win->move_vertical = app->win->height / 4;
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	if (!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
}
