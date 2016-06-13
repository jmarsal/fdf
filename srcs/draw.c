/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/13 16:31:45 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static void echangerEntiers(int* x, int* y)
// {
//   int t = *x;
//   *x = *y;
//   *y = t;
// }
static void	mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 && c->y < app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

static void	draw_columns(t_app *app, t_coords *current, t_coords *next, size_t i)
{
	t_coords	*tmp;
	int			y;

	tmp = current;
	y = current->y;
	while (i-- > 0 && next)
		next = next->next;
	while (y < next->y && next)
	{
		tmp->y = y;
		mlx_put_pixel_to_image(app, tmp, current->color);
		y++;
	}
}

static void	draw_line(t_app *app, t_coords *current)
{
	t_coords	*tmp;
	int			y;
	int			x;
	int			color;

	tmp = current;
	y = current->y;
	x = current->x;
	color = current->color;
	// if (current)
	// {
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
			mlx_put_pixel_to_image(app, tmp, current->color);
			x++;
		}
	// }
}

static void change_data(t_data *lst, t_params *params, t_win *win, t_data *data)
{
	t_data		*lst_cur;
	t_coords	*coords_cur;

	lst_cur = lst;
	while (lst_cur)
	{
		coords_cur = lst_cur->data_val;
		while (coords_cur)
		{
			coords_cur->x = (params->move +
				((coords_cur->x + coords_cur->z) +
				win->space_pix) * params->zoom);
			coords_cur->y = (params->move +
				((coords_cur->y - coords_cur->z) +
				win->space_pix) * params->zoom);
			if (coords_cur->z > 0 && data->is_colors == 0)
				coords_cur->color = 0xff0000;
			coords_cur = coords_cur->next;
		}
		lst_cur = lst_cur->next;
	}
}

void		draw_windows(t_app *app)
{
	t_data		*lst_cur;
	t_coords	*coords_cur;
	t_coords	*coords_next;
	size_t		i;

	lst_cur = app->data;
	change_data(lst_cur, app->params, app->win, app->data);
	while (lst_cur)
	{
		coords_cur = lst_cur->data_val;
		if (lst_cur->next)
			coords_next = lst_cur->next->data_val;
		i = 0;
		while (coords_cur)
		{
			printf("x = %d\n", coords_cur->x);
			// mlx_put_pixel_to_image(app, coords_cur, coords_cur->color);
			draw_line(app, coords_cur);
			draw_columns(app, coords_cur, coords_next, i);
			coords_cur = coords_cur->next;
			// if (coords_next->next)
				// coords_next = coords_next->next;
			i++;
		}
		lst_cur = lst_cur->next;
	}
}
