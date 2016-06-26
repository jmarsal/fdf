/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 01:19:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 01:30:09 by jmarsal          ###   ########.fr       */
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
	mlx_string_put(MLX_PTR, MLX_WIN, 1700, 540, 0xAEECFE, "NEW MAP  :    ");
	mlx_string_put(MLX_PTR, MLX_WIN, 1810, 540, 0xFFFFFF, "Enter");
}

void 		print_info(t_app *app)
{
	print_info1(app);
	print_info2(app);
}

static void print_map_menu2(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 330, 0xAEECFE, "press 0");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 360, 0xAEECFE, "press 1");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 390, 0xAEECFE, "press 2");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 420, 0xAEECFE, "press 3");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 450, 0xAEECFE, "press 4");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 480, 0xAEECFE, "press 5");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 510, 0xAEECFE, "press 6");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 540, 0xAEECFE, "press 7");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 570, 0xAEECFE, "press 8");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 600, 0xAEECFE, "press 9");
	mlx_string_put(MLX_PTR, MLX_WIN, 750, 630, 0xAEECFE, "press A");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 330, 0xAEECFE, "press B");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 360, 0xAEECFE, "press C");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 390, 0xAEECFE, "press D");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 420, 0xAEECFE, "press E");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 450, 0xAEECFE, "press F");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 480, 0xAEECFE, "press G");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 510, 0xAEECFE, "press H");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 540, 0xAEECFE, "press I");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 570, 0xAEECFE, "press J");
	mlx_string_put(MLX_PTR, MLX_WIN, 1250, 600, 0xAEECFE, "press K");
	mlx_string_put(MLX_PTR, MLX_WIN, 950, 800, 0xFF0000, "press R");

}

void 		print_map_menu(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 880, 200, 0xAEECFE, "--- MAPS ----");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 330, 0xFFFFFF, "42");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 360, 0xFFFFFF, "elem-col");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 390, 0xFFFFFF, "elem-fract");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 420, 0xFFFFFF, "elem");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 450, 0xFFFFFF, "elem2");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 480, 0xFFFFFF, "julia");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 510, 0xFFFFFF, "mars");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 540, 0xFFFFFF, "t1");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 570, 0xFFFFFF, "t2");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 600, 0xFFFFFF, "pyramide");
	mlx_string_put(MLX_PTR, MLX_WIN, 600, 630, 0xFFFFFF, "pyra");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 330, 0xFFFFFF, "pylone");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 360, 0xFFFFFF, "pnp_flat");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 390, 0xFFFFFF, "pentenegpos");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 420, 0xFFFFFF, "basictest");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 450, 0xFFFFFF, "100-6");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 480, 0xFFFFFF, "50-4");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 510, 0xFFFFFF, "20-60");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 540, 0xFFFFFF, "10-70");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 570, 0xFFFFFF, "10-2");
	mlx_string_put(MLX_PTR, MLX_WIN, 1100, 600, 0xFFFFFF, "France");
	mlx_string_put(MLX_PTR, MLX_WIN, 880, 800, 0xFF0000, "RETOUR");
	print_map_menu2(app);
}
