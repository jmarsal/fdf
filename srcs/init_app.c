/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/17 15:43:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*init_mlx(t_win *win)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
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

	if (!(img = ft_memalloc(sizeof(t_img))))
	{
		print_error(err, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(mlx, win->width, win->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

t_win		*init_win(int width, int heigth, int zoom)
{
	t_win	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_win))))
		return (NULL);
	tmp->width = width;
	tmp->height = heigth;
	tmp->move = 50;
	tmp->const_power = 2;
	tmp->zoom = zoom;
	return (tmp);
}

t_app		*init_app()
{
	t_app		*app;

	if (!(app = ft_memalloc(sizeof(t_app))))
		return (NULL);
	if (!(app->data = init_data()) ||
		!(app->err.p_err = ft_memalloc(sizeof(char*) * (NB_ERR + 1))) ||
		!(app->win = ft_memalloc(sizeof(t_win))) ||
		!(app->params = ft_memalloc(sizeof(t_params))) ||
		!(app->win->size = ft_memalloc(sizeof(t_win))) ||
		!(app->win->size->tab_of_size_width = init_size_win_width()) ||
		!(app->win->size->tab_of_size_height = init_size_win_height()) ||
		!(app->win->size->tab_of_size_zoom = init_size_win_zoom()))
	{
		free(app);
		return (NULL);
	}
	app->params->check_elements = 0;
	app->params->x_max = 0;
	app->params->y_max = 0;
	return (app);
}
