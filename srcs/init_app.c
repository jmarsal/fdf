/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/09 15:58:20 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*init_mlx(t_app *app)
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx*)malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx_ptr = mlx_init()) == NULL || (mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, app->win->width, app->win->height,
			"fdf by jmarsal")) == NULL)
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

t_img		*init_img(t_app *app)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
	{
		print_error(app, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(app->mlx, app->win->width, app->win->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

t_win		*init_win(size_t width, size_t heigth, size_t div_const, size_t space_pix)
{
	t_win	*tmp;

	if ((tmp = (t_win*)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	tmp->width = width;
	tmp->height = heigth;
	tmp->div_const = div_const;
	tmp->space_pix = space_pix;
	return (tmp);
}

t_app		*init_app()
{
	t_app		*app;
	t_coords	*start;

	if ((app = (t_app*)malloc(sizeof(t_app))) == NULL)
		return (NULL);
	start = NULL;
	if (
		(app->data = init_data(NULL)) == NULL ||
		(app->err.p_err = (char**)malloc(sizeof(char*) * (NB_ERR + 1))) == NULL
		|| (app->win = (t_win*)malloc(sizeof(t_win))) == NULL)
	{
		free(app);
		return (NULL);
	}
	app->check_elements = 0;
	app->x_max = 0;
	app->y_max = 0;
	app->len = 0;
	app->showing = 0;
	app->const_power = 1;
	return (app);
}
