/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/16 16:24:29 by jmarsal          ###   ########.fr       */
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
}

void change_data(t_data *lst, t_params *params, t_win *win, t_data *data)
{
	t_data		*lst_cur;
	t_coords	*coords_cur;

	lst_cur = lst;
	while (lst_cur)
	{
		coords_cur = lst_cur->data_val;
		printf(" dans change_data coords_cur = %p\n", coords_cur);
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
}*/

void		draw_windows(t_app *app)
{
	t_coords	**data;
	size_t		lines;
	size_t		elems;
	int			color;

	data = app->data->data_elem;
	lines = 0;
	// change_data(lst_cur, app->params, app->win, app->data);
	while (lines < app->data->helper.line)
	{
		elems = 0;
		while (elems < app->data->helper.index)
		{
			color = data[lines][elems].color;
			// printf("color = 0x%6.06X\n", color);
			// printf("x = %d, y = %d, z = %d\n",	data[lines][elems].x,
			// 									data[lines][elems].y,
			// 									data[lines][elems].z);
			mlx_put_pixel_to_image(app, &app->data->data_elem[lines][elems],
									color);
			++elems;
			// draw_line(app, coords_cur);
			// draw_columns(app, coords_cur, coords_next, i);
			//if (coords_next->next)
			// coords_next = coords_next->next;
			// i++;
		}
		++lines;
	}
}
