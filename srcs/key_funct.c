/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 22:25:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*void		move_z(t_app *app, int keycode, t_win hook)
{
	if (keycode == 69)
		hook.move_z *= 1.1;
	if (keycode == 78)
		hook.move_z /= 1.1;
	app->win->move_z = hook.move_z;
	// mlx_destroy_window(app->mlx->mlx_ptr, app->mlx->mlx_win);
	// mlx_clear_window(app->mlx->mlx_ptr, app->mlx->mlx_win);
	printf("move_z = %f\n",hook.move_z);
	// app->win = new_win(app->params, hook);
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	if (!(app->img = init_img(app->mlx, app->win, app->err)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	// draw_windows(app);

	ft_memdel((void **)&app->img);
	print_mlx(app);
}*/

int		key_funct(int keycode, t_app *app)
{
	t_win	hook;

	if (app->mlx == NULL)
		return (0);
	hook.height = app->win->height;
	hook.width = app->win->width;
	hook.zoom = app->win->zoom;
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 24)
		hook.move_z *= 1.1;
	else if (keycode == 78 || keycode == 27)
		hook.move_z /= 1.1;
	ft_memdel((void **)&app->img);
	app->win = new_win(app->params, hook);
	// mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	// ft_memdel((void **)&app->img);
	print_mlx(app);
	// if (keycode == 69 || keycode == 78)
	// 	move_z(app, keycode, win);
	return (0);
}
