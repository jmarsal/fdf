/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/24 15:13:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*init_mlx()
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()) || !(mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, 1920, 1080, TITLE)))
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

t_img		*init_img(t_app *app, int width, int height)
{
	t_img	*img;

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

static int	*init_tab_of_size()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	return (tab_of_size);
}

t_win		*init_win(int zoom, int width, int heigth, float move_z)
{
	t_win	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_win))))
		return (NULL);
	if (!(tmp->size = ft_memalloc(sizeof(t_win))) ||
		!(TAB_S_O_Z = init_tab_of_size()))
		return (NULL);
	TAB_S_O_Z = init_size_win_zoom(TAB_S_O_Z);
	tmp->width = width;
	tmp->height = heigth;
	tmp->move_horizontal = 1920 / 3;
	tmp->move_vertical = 1080 / 4;
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

t_app		*init_app()
{
	t_app		*app;

	if (!(app = ft_memalloc(sizeof(t_app))))
		return (NULL);
	if (!(app->data = init_data()) ||
		!(app->err.p_err = ft_memalloc(sizeof(char*) * (NB_ERR + 1))) ||
		!(app->win = init_win(0, 0, 0, 0)) ||
		!(app->params = ft_memalloc(sizeof(t_params))))
	{
		free(app);
		return (NULL);
	}
	app->params->check_elements = 0;
	app->params->x_max = 0;
	app->params->y_max = 0;
	return (app);
}
