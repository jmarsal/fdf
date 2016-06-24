/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 01:19:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/25 01:28:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void print_info2(t_app *app)
{
	char *print;

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
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 930, 0xFFFFFF,
													"jmarsal@student.42.fr");
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 960, 0xFFFFFF,
												"https://github.com/jmarsal");
	mlx_string_put(MLX_PTR, MLX_WIN, 20, 990, 0xFFFFFF, "June 2016");
	free(print);
	print = !(app->win->witch_proj) ? PAR : ISOMETRIC;
	mlx_string_put(MLX_PTR, MLX_WIN, 60, 316, 0xAEECFE, print);
}

static void print_info1(t_app *app)
{
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
}

void 		print_info(t_app *app)
{
	print_info1(app);
	print_info2(app);
}
