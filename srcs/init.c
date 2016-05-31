/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:29:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/31 15:24:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_app		*init_app()
{
	t_app	*app;

	if ((app = (t_app*)malloc(sizeof(t_app))) == NULL)
		return (NULL);
	if ((app->mlx = init_mlx()) == NULL)
		return (NULL);
	if ((app->img = init_img(app)) == NULL)
		return (NULL);
	app->color = init_colors();
	if ((app->coords = init_coords()) == NULL)
		return (NULL);
	app->len = 0;
	if ((app->buf = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (NULL);
	return (app);
}

t_mlx		*init_mlx()
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

t_img		*init_img(t_app *app)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
	{
		ft_putstr("\033[31mERROR\033[0m\n--> Can't create image.\n");
		return (NULL);
	}
	img->img_ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

t_colors	init_colors()
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
	coords->next = NULL;
	return (coords);
}
