/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/23 00:16:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

void 		print_info(t_app *app)
{
	char	*str;

	str = ft_itoa(app->win->zoom_change);
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 15, 10, 0xAEECFE,
		"Current zoom x :");
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 190, 10, 0xFFFFFF,
		str);
	free(str);
	str = ft_itoa(app->win->move_horizontal);
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 15, 40, 0xAEECFE,
		"position.x     :");
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 190, 40, 0xFFFFFF,
		str);
	free(str);
	str = ft_itoa(app->win->move_vertical);
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 15, 70, 0xAEECFE,
		"position.y     :");
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 190, 70, 0xFFFFFF,
		str);
	free(str);
	str = !(app->win->witch_proj) ?
	"Current proj : paralelle" : "Current proj : isometrique";
	mlx_string_put(app->mlx->mlx_ptr, app->mlx->mlx_win, 15, 100, 0xAEECFE,
		str);
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
	mlx_mouse_hook(app->mlx->mlx_win, mouse_funct, &app->mlx);
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
	print_info(app);
	mlx_hook(app->mlx->mlx_win, 2, 3, key_funct, &app->mlx);
	mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(app->mlx->mlx_ptr);
}
