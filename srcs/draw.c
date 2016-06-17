/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/17 16:17:58 by jmarsal          ###   ########.fr       */
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
void	draw_line(t_app *app, t_coords *c_data, t_coords *n_data)
{
	t_coords	*tmp;
	int			y;
	int			x;
	int			color;
	tmp = c_data;
	y = c_data->y;
	x = c_data->x;
	color = c_data->color;
	while (x < n_data->x)
	{
		tmp->x = x;
		if (y < n_data->y)
			y++;
		else if (y > n_data->y)
			y--;
		tmp->y = y;
		if ((y != n_data->y && c_data->z == 0) ||
		(y != n_data->y && n_data->z == 0))
			tmp->color = 0xFFFFFF;
		else if (n_data->z > 0)
		{
			n_data->color = 0xff0000;
			tmp->color = n_data->color;
		}
		else if (c_data->z == 0)
			tmp->color = 0xFFFFFF;
		mlx_put_pixel_to_image(app, tmp, tmp->color);
		x++;
	}
}

static t_coords *new_data(t_win *win, t_coords *c_data, t_data *data)
{
	c_data->x += (((c_data->x * win->zoom) + c_data->z) + win->move);
	c_data->y += (((c_data->y * win->zoom) - c_data->z) + win->move);
	c_data->color = (c_data->z > 0 && data->is_colors == 0) ?
					0xff0000 : c_data->color;
	return (c_data);
}

void		draw_windows(t_app *app)
{
	size_t		lines;
	size_t		elems;
	t_coords	*c_data;
	t_coords	*n_data;

	lines = 0;
	while (lines < app->params->y_max)
	{
		elems = 0;
		while (elems < app->params->x_max)
		{
			c_data = new_data(app->win, &app->data->data_elem[lines][elems],
								app->data);
			if (elems + 1 < app->params->x_max)
				n_data = new_data(app->win,
						&app->data->data_elem[lines][elems + 1], app->data);
			// mlx_put_pixel_to_image(app, c_data, c_data->color);
			draw_line(app, c_data, n_data);
			// draw_columns(app, coords_cur, coords_next, i);
			++elems;
		}
		++lines;
	}
}
