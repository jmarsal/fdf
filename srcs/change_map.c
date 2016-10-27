/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 23:44:14 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 21:43:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	relaunch_soft(char *map, t_app *app)
{
	while (app->data->helper.nb_elems--)
		ft_strdel(&app->data->helper.elems[app->data->helper.nb_elems]);
	ft_free_null(app->data->helper.elems);
	free_data(app->data->data_elem);
	mlx_destroy_image(MLX_PTR, app->c_map);
	app->params->x_max = 0;
	app->params->y_max = 0;
	app->params->check_elements = 0;
	if (!(app->data = init_data()))
		exit(0);
	if (read_file((const char*)map, app) == -1)
		exit(-1);
	get_original_pos(app);
}

static void	if_back(t_app *app, int keycode)
{
	if (KC == R)
	{
		app->if_menu = 0;
		mlx_destroy_image(MLX_PTR, app->c_map);
		app->c_map = NULL;
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	}
}

void		new_map2(char *map, t_app *app, int keycode)
{
	if_back(app, KC);
	if (KC == K)
		map = "maps/IGN_France_250_ASC_L93_OCEAN0_M.fdf";
	else if (KC == 82)
		map = "maps/42.fdf";
	else if (KC == 83)
		map = "maps/elem-col.fdf";
	else if (KC == 84)
		map = "maps/elem-fract.fdf";
	else if (KC == 85)
		map = "maps/elem.fdf";
	else if (KC == 86)
		map = "maps/elem2.fdf";
	else if (KC == 87)
		map = "maps/julia.fdf";
	else if (KC == 88)
		map = "maps/mars.fdf";
	else if (KC == 89)
		map = "maps/t1.fdf";
	else if (KC == 91)
		map = "maps/t2.fdf";
	else if (KC == 92)
		map = "maps/pyramide.fdf";
	if (KC != R)
		relaunch_soft(map, app);
}

void		new_map(t_app *app, int keycode)
{
	char *map;

	map = NULL;
	if (KC == A)
		map = "maps/pyra.fdf";
	else if (KC == B)
		map = "maps/pylone.fdf";
	else if (KC == C)
		map = "maps/pnp_flat.fdf";
	else if (KC == D)
		map = "maps/pentenegpos.fdf";
	else if (KC == E)
		map = "maps/basictest.fdf";
	else if (KC == F)
		map = "maps/100-6.fdf";
	else if (KC == G)
		map = "maps/50-4.fdf";
	else if (KC == H)
		map = "maps/20-60.fdf";
	else if (KC == I)
		map = "maps/10-70.fdf";
	else if (KC == J)
		map = "maps/10-2.fdf";
	new_map2(map, app, KC);
}

void		change_map(t_app *app, int keycode)
{
	if (KC == ENTER)
	{
		if (!(app->c_map = init_img(app, WIDTH_DRAW, HEIGHT_DRAW)))
			exit(0);
		app->if_menu = 1;
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			app->c_map->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
		print_map_menu(app);
	}
}
