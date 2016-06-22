/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 12:40:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_z(t_app *app, int keycode)
{
	if (keycode == Z_PLUS)
		app->win->move_z += 0.1;
	if (keycode == Z_MINUS)
		app->win->move_z -= 0.1;
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

void 	move_tray(t_app *app, int keycode)
{
	if (keycode == T_LEFT)
		app->win->move_horizontal -= 2;
	if (keycode == T_RIGHT)
		app->win->move_horizontal += 2;
	if (keycode == T_UP)
		app->win->move_vertical -= 2;
	if (keycode == T_DOWN)
		app->win->move_vertical += 2;
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

int		key_funct(int keycode, t_app *app)
{
	printf("keycode = %d\n", keycode);
	if (keycode == QUIT)
		exit(0);
	if (keycode == Z_PLUS || keycode == Z_MINUS)
		move_z(app, keycode);
	if (keycode == T_LEFT || keycode == T_RIGHT ||
		keycode == T_UP || keycode == T_DOWN)
		move_tray(app, keycode);
	return (0);
}
