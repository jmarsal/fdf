/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/02 12:02:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < WIDTH && c->y > 0 && c->y < HEIGHT)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

void	draw_windows(t_app *app)
{
	while (app->coords->x <= WIDTH && app->coords->y <= HEIGHT)
	{
		if (app->coords->x == WIDTH)
		{
			app->coords->y++;
			app->coords->x = 0;
		}
		if (app->coords->x <= TIER * 1)
			mlx_put_pixel_to_image(app, app->coords, app->color.color1);
		if (app->coords->x >= TIER * 1 && app->coords->x <= TIER * 2)
			mlx_put_pixel_to_image(app, app->coords, app->color.color2);
		if (app->coords->x >= TIER * 2 && app->coords->x <= TIER * 3)
			mlx_put_pixel_to_image(app, app->coords, app->color.color3);
		app->coords->x++;
	}
}
