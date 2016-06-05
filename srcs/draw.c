/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/05 02:19:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < WIDTH && c->y > 0 && c->y < HEIGHT)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

void	draw_windows(t_app *app)
{
	while (app->data->data_val)
	{
		mlx_put_pixel_to_image(app, app->data->data_val, app->data->data_val->color);
		app->data->data_val = app->data->data_val->next;
	}
}
