/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/14 10:08:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*init_mlx(t_win *win)
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx*)malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()) || !(mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, win->width, win->height,
			"fdf by jmarsal")))
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

t_img		*init_img(t_mlx *mlx, t_win *win, t_error err)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
	{
		print_error(err, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(mlx, win->width, win->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

t_win		*init_win(int width, int heigth, size_t space_pix)
{
	t_win	*tmp;

	if ((tmp = (t_win*)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	tmp->width = width;
	tmp->height = heigth;
	tmp->space_pix = space_pix;
	return (tmp);
}

t_app		*init_app()
{
	t_app		*app;

	if ((app = (t_app*)malloc(sizeof(t_app))) == NULL)
		return (NULL);
	if (!(app->data = init_data(NULL)) ||
		!(app->err.p_err = (char**)malloc(sizeof(char*) * (NB_ERR + 1))) ||
		!(app->win = (t_win*)malloc(sizeof(t_win))) ||
		!(app->params = (t_params*)malloc(sizeof(t_params))) ||
		!(app->win->size = (t_size_win*)malloc(sizeof(t_size_win))) ||
		!(app->win->size->tab_of_size_width = init_size_win_width()) ||
		!(app->win->size->tab_of_size_height = init_size_win_height()) ||
		!(app->win->size->tab_of_size_space_pix = init_size_win_space_pix()))
	{
		free(app);
		return (NULL);
	}
	app->params->check_elements = 0;
	app->params->x_max = 0;
	app->params->y_max = 0;
	app->params->move = 50;
	app->params->zoom = 1;
	app->params->const_power = 2;
	return (app);
}
