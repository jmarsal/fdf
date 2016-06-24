/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/24 01:31:03 by jmarsal          ###   ########.fr       */
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

	print = ft_itoa(app->win->zoom_change);
	mlx_string_put(MLX_PTR, MLX_WIN, 15, 10, 0xAEECFE, "Current zoom x :");
	mlx_string_put(MLX_PTR, MLX_WIN, 190, 10, 0xFFFFFF, print);
	free(print);
	print = ft_itoa(app->win->move_horizontal);
	mlx_string_put(MLX_PTR, MLX_WIN, 15, 40, 0xAEECFE, "position.x     :");
	mlx_string_put(MLX_PTR, MLX_WIN, 190, 40, 0xFFFFFF, print);
	free(print);
	print = ft_itoa(app->win->move_vertical);
	mlx_string_put(MLX_PTR, MLX_WIN, 15, 70, 0xAEECFE, "position.y     :");
	mlx_string_put(MLX_PTR, MLX_WIN, 190, 70, 0xFFFFFF, print);
	free(print);
	print = !(app->win->witch_proj) ? PAR : ISOMETRIC;
	mlx_string_put(MLX_PTR, MLX_WIN, 15, 100, 0xAEECFE, print);
}

void		mlx_start(t_app *app)
{
	int		h;
	int		w;

	h = app->win->height;
	w = app->win->width - SIZE_MENU_W;
	if (!(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app, app->win->width, app->win->height)) ||
		!(app->menu = init_img(app, 1920, 1080)))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	mlx_mouse_hook(MLX_WIN, mouse_funct, &app->mlx);
	app->menu->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/galaxy.xpm", &w, &h);
	draw_windows(app);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu->img_ptr, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	print_info(app);
	mlx_hook(MLX_WIN, 2, 3, key_funct, &app->mlx);
	mlx_hook(MLX_WIN, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(MLX_PTR);
}
