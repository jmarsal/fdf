/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:50:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 12:38:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		mlx_put_pixel_to_image(t_app *app, t_affine *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 &&
		c->y < app->win->height)
	ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
										octet * c->y)], &color, octet);
}

t_coords		ch_data_paralelle(int is_color, t_win *win, t_coords data)
{
	t_coords	modify;

	modify.z = data.z * win->move_z;
	modify.y = ((CST1 / 2) * -modify.z + data.y) * win->zoom + win->move_vertical;
	modify.x = (data.x + CST1 * modify.z) * win->zoom + win->move_horizontal;
	modify.color = (data.z != 0 && is_color == 0) ? 0xff0000 : data.color;
	return (modify);
}
