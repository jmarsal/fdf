/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/11 22:57:26 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static void echangerEntiers(int* x, int* y)
// {
//   int t = *x;
//   *x = *y;
//   *y = t;
// }

// static void draw_line(t_app *app, t_coords *current, t_coords *next, size_t i)
// {
// 	t_coords	*tmp;
// 	// t_coords	*tmp2;
// 	size_t		y;
// 	size_t		x;
//
// 	tmp = current;
// 	// tmp2 = tmp;
// 	y = current->y;
// 	x = current->x;
// 	while (i-- && next->next)
// 		next = next->next;
// 	while (y < next->y)
// 	{
// 		tmp->y = y;
// 		mlx_put_pixel_to_image(app, tmp, current->color);
// 		y++;
// 	}
// 	while (x < next->x)
// 	{
// 		tmp->x = x;
// 		mlx_put_pixel_to_image(app, tmp, current->color);
// 		x++;
// 	}
// 	// mlx_put_pixel_to_image(app, current, current->color);
// }

static void	mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 && c->y < app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

static void change_data(t_app *app, t_coords *coords_currrent)
{
	// printf("move = %d\n", app->params->move);
	coords_currrent->x = (((coords_currrent->x + coords_currrent->z) +
				app->win->space_pix) * app->params->zoom);
	coords_currrent->y = (((coords_currrent->y - coords_currrent->z) +
				app->win->space_pix) * app->params->zoom);
	if (coords_currrent->z > 0 && coords_currrent->color == 0xffffff)
		coords_currrent->color = 0xff0000;
}

void		draw_windows(t_app *app)
{
	t_data		*lst_cur;
	t_coords	*coords_cur;
	t_coords	*coords_next;
	size_t		i;

	lst_cur = app->data;
	while (lst_cur->next)
	{
		coords_cur = lst_cur->data_val;
		coords_next = lst_cur->next->data_val;
		i = 0;
		while (coords_cur && coords_next)
		{
			coords_cur->x += app->params->move;
			coords_cur->y += app->params->move;
			change_data(app, coords_cur);
			mlx_put_pixel_to_image(app, coords_cur, coords_cur->color);
			// draw_line(app, coords_cur, coords_next, i);
			coords_cur = coords_cur->next;
			coords_next = coords_next->next;
			i++;
		}
		lst_cur = lst_cur->next;
	}
}
