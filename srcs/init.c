/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/02 16:28:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_mlx		*init_mlx()
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx*)malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx_ptr = mlx_init()) == NULL || (mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fdf by jmarsal")) == NULL)
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

static t_img		*init_img(t_app *app)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
	{
		print_error(app, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

static t_data		*init_data()
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->data_val = NULL;
	data->x_max = 0;
	data->y_max = 0;
	return (data);
}

static t_colors	init_colors()
{
	t_colors	color;

	color.color1 = 0x00239d;
	color.color2 = 0xffffff;
	color.color3 = 0xa10404;
	return (color);
}

t_coords	*init_coords()
{
	t_coords	*coords;

	if ((coords = (t_coords*)malloc(sizeof(t_coords))) == NULL)
		return (NULL);
	coords->x = 0;
	coords->y = 0;
	coords->z = 0;
	coords->color = 0xffffff;
	coords->next = NULL;
	return (coords);
}

t_app		*init_app()
{
	t_app	*app;

	if ((app = (t_app*)malloc(sizeof(t_app))) == NULL)
		return (NULL);
	if ((app->mlx = init_mlx()) == NULL || (app->img = init_img(app)) == NULL ||
		(app->data = init_data()) == NULL ||
		(app->err.p_err = (char**)malloc(sizeof(char*) * (NB_ERR + 1))) == NULL)
	{
		free(app);
		return (NULL);
	}
	app->coords = NULL;
	app->color = init_colors();
	app->len = 0;
	return (app);
}
