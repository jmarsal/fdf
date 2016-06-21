/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 16:16:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

int		print_mlx(t_app *app)
{
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	// ft_memdel((void **)&app->img);
	if (!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
	return (0);
}

t_win			*new_win(t_params *param, t_win hook)
{
	t_win		*new;

	new = init_win(hook.zoom, hook.width, hook.height, hook.move_z);
	// new->x_max = param->x_max;
	// new->y_max = param->y_max;
	(void)param;
	return (new);
}

void			mlx_start(t_app *app)
{
	if (!(app->win = init_win(app->win->zoom, app->win->width, app->win->height,
		app->win->move_z)) || !(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	// mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
	// mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
	print_mlx(app);
	// draw_windows(app);
	// mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		// app->img->img_ptr, 0, 0);
	// mlx_expose_hook(app->mlx->mlx_ptr, expose_hook, &app);
}
