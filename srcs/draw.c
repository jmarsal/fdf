/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/18 01:15:59 by jmarsal          ###   ########.fr       */
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

/*void	draw_columns(t_app *app, t_coords *current, t_coords *next, size_t i)
{
	t_coords	*tmp;
	int			y;
	tmp = current;
	y = current->y;
	while (i-- > 0 && next)
		next = next->next;
	while (next && y < next->y)
	{
		tmp->y = y;
		mlx_put_pixel_to_image(app, tmp, current->color);
		y++;
	}
}*/
void	draw_line(t_app *app, t_coords **n_data, size_t lines, size_t elems)
{
	t_coords	c_elems;
	t_coords	n_elems;
	t_coords	n_line;

	c_elems = n_data[lines][elems];
	n_elems = n_data[lines][elems + 1];
	n_line = n_data[lines + 1][elems];
	while (c_elems.x < n_elems.x)
	{
		if (c_elems.y < n_elems.y)
			c_elems.y++;
		else if (c_elems.y > n_elems.y)
			c_elems.y--;
		if (c_elems.y != n_elems.y && c_elems.z == 0)
			c_elems.color = 0xFFFFFF;
		else if (n_elems.z > 0 || (n_elems.z != n_elems.z && n_elems.z > 0))
		{
			// n_elems.color = 0xff0000;
			c_elems.color = n_elems.color;
		}
		else if (n_elems.z == 0)
			c_elems.color = 0xFFFFFF;
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
			printf("%d\n", data->is_colors);
			n_data[lines][elems].x += (((n_data[lines][elems].x * win->zoom) +
										n_data[lines][elems].z) + win->move);
			n_data[lines][elems].y += (((n_data[lines][elems].y * win->zoom) -
										n_data[lines][elems].z) + win->move);
			n_data[lines][elems].color = (n_data[lines][elems].z != 0 &&
				data->is_colors == 0) ? 0xff0000 : n_data[lines][elems].color;
			++elems;
		}
		++lines;
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
	while (lines < app->params->y_max)
	{
		elems = 0;
		while (elems < app->params->x_max - 1)
		{
			// mlx_put_pixel_to_image(app, &n_data[lines][elems],
									// n_data[lines][elems].color);
			draw_line(app, n_data, lines, elems);
			// draw_columns(app, coords_cur, coords_next, i);
			++elems;
		}
		++lines;
	}
}
