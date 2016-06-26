/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 23:44:14 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 16:18:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void relaunch_soft(char *map, t_app *app)
{
	while (app->data->helper.nb_elems--)
		ft_strdel(&app->data->helper.elems[app->data->helper.nb_elems]);
	free (app->data->helper.elems);
	free_data(app->data->data_elem);
	mlx_destroy_image(app->mlx->mlx_ptr, app->c_map);
	app->params->x_max = 0;
	app->params->y_max = 0;
	app->params->check_elements = 0;
	if (!(app->data = init_data()))
		exit(0);
	if (read_file((const char*)map, app) == -1)
		exit (-1);
	get_original_pos(app);
}

void 	new_map2(char *map, t_app *app, int keycode)
{
	if (keycode == K)
		map = "maps/IGN_France_250_ASC_L93_OCEAN0_M.fdf";
	else if (keycode == R)
	{
		mlx_destroy_image(app->mlx->mlx_ptr, app->c_map);
		app->c_map = NULL;
		mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
			app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	}
	else if (keycode == 82)
		map = "maps/42.fdf";
	else if (keycode == 83)
		map = "maps/elem-col.fdf";
	else if (keycode == 84)
		map = "maps/elem-fract.fdf";
	else if (keycode == 85)
		map = "maps/elem.fdf";
	else if (keycode == 86)
		map = "maps/elem2.fdf";
	else if (keycode == 87)
		map = "maps/julia.fdf";
	else if (keycode == 88)
		map = "maps/mars.fdf";
	else if (keycode == 89)
		map = "maps/t1.fdf";
	else if (keycode == 91)
		map = "maps/t2.fdf";
	else if (keycode == 92)
		map = "maps/pyramide.fdf";
	if (keycode != R)
		relaunch_soft(map, app);
}

void	new_map(t_app *app, int keycode)
{
	char *map;

	map = NULL;
	if (keycode == A)
		map = "maps/pyra.fdf";
	else if (keycode == B)
		map = "maps/pylone.fdf";
	else if (keycode == C)
		map = "maps/pnp_flat.fdf";
	else if (keycode == D)
		map = "maps/pentenegpos.fdf";
	else if (keycode == E)
		map = "maps/basictest.fdf";
	else if (keycode == F)
		map = "maps/100-6.fdf";
	else if (keycode == G)
		map = "maps/50-4.fdf";
	else if (keycode == H)
		map = "maps/20-60.fdf";
	else if (keycode == I)
		map = "maps/10-70.fdf";
	else if (keycode == J)
		map = "maps/10-2.fdf";
	new_map2(map, app, keycode);
}

void 	change_map(t_app *app, int keycode)
{
	// char	*av;
//  si touche entree
//  -> cree une nouvelle img et la put sur la fenetre de dessin
//  -> dedans, touche les touches a appuyer pour chaques map;
//  -> quant touches appuyer, free img;
//  -> relance le soft avec la nouvelle map;
	if (keycode == 36) // A
	{
		if (!(app->c_map = init_img(app, app->win->width, app->win->height)))
			exit(0);
		// mlx_destroy_image(app->mlx->mlx_ptr, app->img);
		mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
			app->c_map->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
		print_map_menu(app);
	}
}
