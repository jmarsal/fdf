/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:50:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 00:12:34 by jmarsal          ###   ########.fr       */
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

t_coords	**new_data(t_data *data, t_params *params, t_win *win,
							t_coords **n_data)
{
	size_t		lines;
	size_t		elems;

	lines = 0;
	while (lines < params->y_max)
	{
		elems = 0;
		while (elems < params->x_max)
		{
			n_data[lines][elems].z *= win->move_z;
			n_data[lines][elems].x = (n_data[lines][elems].x + CST1 *
										n_data[lines][elems].z) * win->zoom
										+ win->move;
			n_data[lines][elems].x += n_data[lines][elems].x * win->zoom;
			n_data[lines][elems].y = (n_data[lines][elems].y + (CST1 / 2) *
										-n_data[lines][elems].z) * win->zoom
										+ win->move;
			n_data[lines][elems].y += n_data[lines][elems].y * win->zoom;
			n_data[lines][elems].color = (n_data[lines][elems].z != 0 &&
				data->is_colors == 0) ? 0xff0000 : n_data[lines][elems].color;
			elems++;
		}
		lines++;
	}
	return (n_data);
}
