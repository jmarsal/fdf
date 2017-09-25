/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 21:45:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_win(t_mlx *mlx)
{
	ft_free_null(mlx);
	exit(0);
}

static void	fill_img(t_app *app, int *h, int *w)
{
	app->menu->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
												"images/galaxy.xpm", w, h);
	app->img_ecole->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
												"images/42.xpm", w, h);
	app->phenix->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
												"images/phenix.xpm", w, h);
	app->rtfm->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
												"images/rtfm.xpm", w, h);
	app->cadre->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
												"images/cadre.xpm", w, h);
}

static void	free_and_init_img(t_app *app)
{
	mlx_destroy_image(MLX_PTR, app->img);
	mlx_destroy_image(MLX_PTR, app->menu);
	mlx_destroy_image(MLX_PTR, app->img_ecole);
	mlx_destroy_image(MLX_PTR, app->phenix);
	mlx_destroy_image(MLX_PTR, app->cadre);
	mlx_destroy_image(MLX_PTR, app->rtfm);
	if (!(app->img = init_img(app, WIDTH_DRAW, HEIGHT_DRAW)) ||
		!(app->menu = init_img(app, WIDTH, HEIGHT)) ||
		!(app->img_ecole = init_img(app, 200, 216)) ||
		!(app->phenix = init_img(app, 60, 53)) ||
		!(app->cadre = init_img(app, WIDTH_DRAW, HEIGHT_DRAW)) ||
		!(app->rtfm = init_img(app, 200, 216)))
	{
		print_error(app->err, 5);
		ft_free_null(app);
		exit(-1);
	}
}

void		refresh_win(t_app *app)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	app->if_menu = 0;
	free_and_init_img(app);
	draw_windows(app);
	fill_img(app, &h, &w);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu->img_ptr, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img_ecole->img_ptr, 67, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->rtfm->img_ptr, WIDTH - 217, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->cadre->img_ptr, 320, 69);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->phenix->img_ptr, 20, 850);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	print_info(app);
}

void		mlx_start(t_app *app)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app, WIDTH_DRAW, HEIGHT_DRAW)) ||
		!(app->menu = init_img(app, WIDTH, HEIGHT)) ||
		!(app->img_ecole = init_img(app, 200, 216)) ||
		!(app->phenix = init_img(app, 60, 53)) ||
		!(app->cadre = init_img(app, WIDTH_DRAW, HEIGHT_DRAW)) ||
		!(app->rtfm = init_img(app, 200, 216)))
	{
		print_error(app->err, 5);
		ft_free_null(app);
		exit(-1);
	}
	mlx_mouse_hook(MLX_WIN, mouse_funct, &app->mlx);
	fill_img(app, &h, &w);
	refresh_win(app);
	mlx_hook(MLX_WIN, 2, 3, key_funct, &app->mlx);
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, &app->mlx);
	mlx_loop(MLX_PTR);
}
