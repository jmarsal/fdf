/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/24 23:35:26 by jmarsal          ###   ########.fr       */
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
	char	*print;

	mlx_string_put(MLX_PTR, MLX_WIN, 880, 30, 0xAEECFE, "File Name : ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1000, 30, 0xFFFFFF, app->win->filename);
	mlx_string_put(MLX_PTR, MLX_WIN, 1750, 245, 0xAEECFE, "Commands :");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 300, 0xAEECFE, "ISO      :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 300, 0xFFFFFF, "Page Up");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 330, 0xAEECFE, "PAR      :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 330, 0xFFFFFF, "Page DOWN");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 360, 0xAEECFE, "ALTITUDE+:    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 360, 0xFFFFFF, "+");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 390, 0xAEECFE, "ALTITUDE-:    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 390, 0xFFFFFF, "-");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 420, 0xAEECFE, "MOVE     :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 420, 0xFFFFFF, "Arrows");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 450, 0xAEECFE, "ZOOM     :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 450, 0xFFFFFF, "Scroll");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 480, 0xAEECFE, "ORIGIN   :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 480, 0xFFFFFF, "O");
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 510, 0xAEECFE, "EXIT     :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 510, 0xFFFFFF, "Esc");
	print = ft_itoa(app->win->zoom_change);
	mlx_string_put(MLX_PTR, MLX_WIN, 60, 226, 0xAEECFE, "Current zoom x :");
	mlx_string_put(MLX_PTR, MLX_WIN, 235, 226, 0xFFFFFF, print);
	free(print);
	print = ft_itoa(app->win->move_horizontal);
	mlx_string_put(MLX_PTR, MLX_WIN, 60, 256, 0xAEECFE, "position.x     :");
	mlx_string_put(MLX_PTR, MLX_WIN, 235, 256, 0xFFFFFF, print);
	free(print);
	print = ft_itoa(app->win->move_vertical);
	mlx_string_put(MLX_PTR, MLX_WIN, 60, 286, 0xAEECFE, "position.y     :");
	mlx_string_put(MLX_PTR, MLX_WIN, 235, 286, 0xFFFFFF, print);
	mlx_string_put(MLX_PTR, MLX_WIN, 95, 850, 0xAEECFE, "fdf made by");
	mlx_string_put(MLX_PTR, MLX_WIN, 95, 880, 0xAEECFE, "Jean-Baptiste Marsal");
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 930, 0xFFFFFF, "jmarsal@student.42.fr");
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 960, 0xFFFFFF, "https://github.com/jmarsal");
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 990, 0xFFFFFF, "June 2016");
	free(print);
	print = !(app->win->witch_proj) ? PAR : ISOMETRIC;
	mlx_string_put(MLX_PTR, MLX_WIN, 60, 316, 0xAEECFE, print);
}

void 		refresh_win(t_app *app)
{
	mlx_destroy_image(app->mlx->mlx_ptr, app->img);
	if (!(app->img = init_img(app, app->win->width, app->win->height)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	draw_windows(app);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu->img_ptr, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img_ecole->img_ptr, 67, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->rtfm->img_ptr, 1920 - 217, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->cadre->img_ptr, 320, 69);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->phenix->img_ptr, 20, 850);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	print_info(app);
}

void		mlx_start(t_app *app)
{
	int		h;
	int		w;

	h = app->win->height;
	w = app->win->width;
	if (!(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app, app->win->width, app->win->height)) ||
		!(app->menu = init_img(app, 1920, 1080)) ||
		!(app->img_ecole = init_img(app, 200, 216)) ||
		!(app->phenix = init_img(app, 60, 53)) ||
		!(app->cadre = init_img(app, 1300, 800)) ||
		!(app->rtfm = init_img(app, 200, 216)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	mlx_mouse_hook(MLX_WIN, mouse_funct, &app->mlx);
	app->menu->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/galaxy.xpm", &w, &h);
	app->img_ecole->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/42.xpm", &w, &h);
	app->phenix->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/phenix.xpm", &w, &h);
	app->rtfm->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/rtfm.xpm", &w, &h);
	app->cadre->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/cadre.xpm", &w, &h);
	refresh_win(app);
	mlx_hook(MLX_WIN, 2, 3, key_funct, &app->mlx);
	mlx_hook(MLX_WIN, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(MLX_PTR);
}
