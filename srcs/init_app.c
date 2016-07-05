/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/07/03 00:40:39 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()))
	{
		free(mlx);
		return (NULL);
	}
	if (!(mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, TITLE)))
	{
		free(mlx->mlx_ptr);
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

t_img		*init_img(t_app *app, int width, int height)
{
	t_img	*img;

	img = NULL;
	if (!(img = ft_memalloc(sizeof(t_img))))
	{
		print_error(app->err, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(app->mlx, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

static int	*init_tab_of_size(void)
{
	int	*tab_of_size;

	tab_of_size = NULL;
	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES + 1)))
		return (NULL);
	return (tab_of_size);
}

t_win		*init_win(int zoom, float move_z)
{
	t_win	*tmp;

	tmp = NULL;
	if (!(tmp = ft_memalloc(sizeof(t_win))))
		return (NULL);
	if (!(tmp->size = ft_memalloc(sizeof(t_size_win))) ||
		!(TAB_S_O_Z = init_tab_of_size()))
		return (NULL);
	TAB_S_O_Z = init_size_win_zoom(TAB_S_O_Z);
	tmp->move_horizontal = WIDTH / 3;
	tmp->move_vertical = HEIGHT / 4;
	if (move_z != 0)
		tmp->move_z = move_z;
	else
		tmp->move_z = 1;
	tmp->zoom = zoom;
	tmp->zoom_change = 1;
	tmp->witch_proj = 1;
	tmp->filename = NULL;
	return (tmp);
}

t_app		*init_app(void)
{
	t_app		*app;

	app = NULL;
	if (!(app = ft_memalloc(sizeof(t_app))))
		return (NULL);
	if (!(app->data = init_data()) ||
		!(app->err.p_err = ft_memalloc(sizeof(char*) * (NB_ERR + 1))) ||
		!(app->win = init_win(0, 0)) ||
		!(app->params = ft_memalloc(sizeof(t_params))))
	{
		free(app);
		return (NULL);
	}
	app->if_menu = 0;
	app->mlx = NULL;
	app->img = NULL;
	app->img_ecole = NULL;
	app->cadre = NULL;
	app->phenix = NULL;
	app->rtfm = NULL;
	app->menu = NULL;
	app->c_map = NULL;
	app->params->check_elements = 0;
	app->params->x_max = 0;
	app->params->y_max = 0;
	return (app);
}
