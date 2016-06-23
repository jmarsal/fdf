/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/23 16:28:30 by jmarsal          ###   ########.fr       */
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
	t_img	*menu;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (!(app->win = init_win(app->win->zoom, app->win->width, app->win->height,
		app->win->move_z)) || !(app->mlx = init_mlx(app->win)) ||
		!(app->img = init_img(app->mlx, app->win, app->err)) ||
		!(menu = ft_memalloc(sizeof(t_img))))
	{
		print_error(app->err, 5);
		free (app);
		exit (-1);
	}
	mlx_mouse_hook(MLX_WIN, mouse_funct, &app->mlx);
	menu->img_ptr = mlx_xpm_file_to_image(MLX_PTR, "images/galaxy.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, menu->img_ptr, 0, 0);
	draw_windows(app);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, 0, 0);
	print_info(app);
	mlx_hook(MLX_WIN, 2, 3, key_funct, &app->mlx);
	mlx_hook(MLX_WIN, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(MLX_PTR);
}
