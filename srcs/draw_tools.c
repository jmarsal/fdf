/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:50:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/23 15:13:40 by jmarsal          ###   ########.fr       */
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

t_coords	ch_data_paralelle(int is_color, t_win *win, t_coords data)
{
	t_coords	modify;

	modify.z = data.z * win->move_z;
	modify.y = ((CST1 / 2) * -modify.z + data.y) * win->zoom
				+ win->move_vertical;
	modify.y *= win->zoom_change;
	modify.x = (data.x + CST1 * modify.z) * win->zoom + win->move_horizontal;
	modify.x *= win->zoom_change;
	modify.color = (is_color == 0) ? COLOR_DEF : data.color;
	return (modify);
}

t_coords	ch_data_isometric(int is_color, t_win *win, t_coords data)
{
	t_coords	modify;

	modify.z = data.z * win->move_z;
	modify.y = (data.x * (CST1 / 2) + data.y * (CST2 / 2) - modify.z) *
				win->zoom + win->move_vertical;
	modify.y *= win->zoom_change;
	modify.x = (data.x * CST1 - data.y * CST2) *
				win->zoom + win->move_horizontal;
	modify.x *= win->zoom_change;
	modify.color = (is_color == 0) ? COLOR_DEF : data.color;
	return (modify);
}
