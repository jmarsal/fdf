/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/17 15:44:23 by jmarsal          ###   ########.fr       */
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
}
void	draw_line(t_app *app, t_coords *current)
{
	t_coords	*tmp;
	int			y;
	int			x;
	int			color;
	tmp = current;
	y = current->y;
	x = current->x;
	color = current->color;
	while (current->next && x < current->next->x)
	{
		tmp->x = x;
		if (y < current->next->y)
			y++;
		else if (y > current->next->y)
			y--;
		tmp->y = y;
		if ((y != current->next->y && current->z == 0) ||
		(y != current->next->y && current->next->z == 0))
			tmp->color = 0xFFFFFF;
		else if (current->next->z > 0)
		{
			current->next->color = 0xff0000;
			tmp->color = current->next->color;
		}
		else if (current->z == 0)
			tmp->color = 0xFFFFFF;
		mlx_put_pixel_to_image(app, tmp, tmp->color);
		x++;
	}
}*/

static t_coords *new_data(t_win *win, t_coords *n_data, t_data *data)
{
	n_data->x += ((n_data->x * win->zoom) + n_data->z + win->move);
	n_data->y += ((n_data->y * win->zoom) - n_data->z + win->move);
	n_data->color = (n_data->z > 0 && data->is_colors == 0) ?
					0xff0000 : n_data->color;
	return (n_data);
}

void		draw_windows(t_app *app)
{
	t_coords	**data;
	size_t		lines;
	size_t		elems;
	t_coords	*n_data;

	data = app->data->data_elem;
	lines = 0;
	while (lines < app->params->y_max)
	{
		elems = 0;
		while (elems < app->params->x_max)
		{
			n_data = new_data(app->win, &data[lines][elems], app->data);
			mlx_put_pixel_to_image(app, n_data, n_data->color);
			++elems;
			// draw_line(app, coords_cur);
			// draw_columns(app, coords_cur, coords_next, i);
		}
		++lines;
	}
}
