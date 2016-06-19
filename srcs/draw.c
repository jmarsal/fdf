/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/19 02:40:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static void echangerEntiers(int* x, int* y)
// {
//   int t = *x;
//   *x = *y;
//   *y = t;
// }
void	mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 && c->y < app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

void	draw_columns(t_app *app, t_coords **n_data, size_t lines, size_t elems)
{
	t_coords	c_line;
	t_coords	n_line;

	c_line = n_data[lines][elems];
	if (n_data[lines + 1])
		n_line = n_data[lines + 1][elems];
	else
		n_line = c_line;
	while (c_line.y < n_line.y)
	{
		if (c_line.x < n_line.x - n_line.z)
			c_line.x++;
		else if (c_line.x > n_line.x + n_line.z)
			c_line.x--;
		if (c_line.x != n_line.x && c_line.z != n_line.z)
			c_line.color = 0xFFFFFF;
		else if (c_line.z != n_line.z && n_line.z > 0)
			c_line.color = 0xff0000;
		mlx_put_pixel_to_image(app, &c_line, c_line.color);
		c_line.y++;
	}
}

void	draw_line(t_app *app, t_coords **n_data, size_t lines, size_t elems)
{
	t_coords	c_elems;
	t_coords	n_elems;

	c_elems = n_data[lines][elems];
	n_elems = n_data[lines][elems + 1];
	while (c_elems.x < n_elems.x)
	{
		if (c_elems.y < n_elems.y)
			c_elems.y++;
		else if (c_elems.y > n_elems.y)
			c_elems.y--;
		if (c_elems.y != n_elems.y && c_elems.z != n_elems.z)
			c_elems.color = 0xFFFFFF;
		else if (c_elems.z != n_elems.z && n_elems.z > 0)
			c_elems.color = 0xff0000;
		mlx_put_pixel_to_image(app, &c_elems, c_elems.color);
		c_elems.x++;
	}
}

static t_coords **new_data(t_data *data, t_params *params, t_win *win,
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
			n_data[lines][elems].x += (((n_data[lines][elems].x * win->zoom) +
										n_data[lines][elems].z) + win->move);
			n_data[lines][elems].y += (((n_data[lines][elems].y * win->zoom) -
										n_data[lines][elems].z) + win->move);
			n_data[lines][elems].color = (n_data[lines][elems].z != 0 &&
				data->is_colors == 0) ? 0xff0000 : n_data[lines][elems].color;
			elems++;
		}
		lines++;
	}
	return (n_data);
}

void		draw_windows(t_app *app)
{
	t_coords	**n_data;
	size_t		lines;
	size_t		elems;

	n_data = new_data(app->data, app->params, app->win, app->data->data_elem);
	lines = 0;
	while (n_data[lines])
	{
		elems = 0;
		while (elems < app->params->x_max)
		{
			// mlx_put_pixel_to_image(app, &n_data[lines][elems],
									// n_data[lines][elems].color);
			draw_line(app, n_data, lines, elems);
			draw_columns(app, n_data, lines, elems);
			elems++;
		}
		lines++;
	}
	elems = 0;
}
