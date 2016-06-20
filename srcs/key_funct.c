/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 00:24:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		high(t_app *app, int keycode, t_win hook)
{
	if (keycode == 69)
		hook.move_z *= 1.1;
	if (keycode == 78)
		hook.move_z /= 1.1;
	app->win = new_win(app->params, hook);
	ft_memdel((void **)&app->img);
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
	t_win	win;

	printf("keycode = %d\n", keycode);
	win.move_z = app->win->move_z;
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		high(app, keycode, win);
	return (0);
}
