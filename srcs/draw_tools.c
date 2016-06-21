/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:50:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 16:26:28 by jmarsal          ###   ########.fr       */
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
	t_coords	**tmp;
	size_t		lines;
	size_t		elems;

	lines = 0;
	// tmp = n_data;
	ft_memcpy(&tmp, &n_data, sizeof(tmp));
	while (lines < params->y_max)
	{
		printf("move_z = %f\n", win->move_z);
		elems = 0;
		printf("z = %f\n", tmp[lines][elems].z);
		while (elems < params->x_max)
		{
			tmp[lines][elems].z = n_data[lines][elems].z * win->move_z;
			tmp[lines][elems].x = n_data[lines][elems].x + CST1 * tmp[lines][elems].z;
			// tmp[lines][elems].x *= win->zoom;
			tmp[lines][elems].y = n_data[lines][elems].y + (CST1 / 2) * -tmp[lines][elems].z;
			// tmp[lines][elems].y *= win->zoom;
			tmp[lines][elems].color = (n_data[lines][elems].z != 0 &&
				data->is_colors == 0) ? 0xff0000 : n_data[lines][elems].color;
			elems++;
		}
		lines++;
	}
	return (tmp);
}
