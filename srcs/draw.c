/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/05 16:13:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 && c->y < app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

static void draw_lines(t_app *app)
{
	t_coords	*coords;
	t_coords	*cur;
	t_coords	*test;
	size_t		x;
	size_t		y;

	coords = app->data->data_val;
	while (coords->next)
	{
		test = coords;
		x = test->x;
		while (x <= coords->next->x)
		{
			test->x = x;
			mlx_put_pixel_to_image(app, test, coords->color);
			cur = test;
			while (cur->y != HEIGHT / 4 + test->y && cur->next)
				cur = cur->next;
			y = test->y;
			while (y <= coords->next->y)
			{
				test->y = y;
				mlx_put_pixel_to_image(app, test, coords->color);
				y++;
			}
			x++;
		}
		coords = coords->next;
	}
}

// static void draw_columns(t_app *app)
// {
// 	t_coords	*coords;
// 	t_coords	*test;
// 	size_t		y;
//
// 	coords = app->data->data_val;
// 	while (coords->next)
// 	{
// 		test = coords;
// 		y = test->y;
// 		while (y <= coords->next->y)
// 		{
// 			test->y = y;
// 			mlx_put_pixel_to_image(app, test, coords->color);
// 			y++;
// 		}
// 		coords = coords->next;
// 	}
// }

void	draw_windows(t_app *app)
{
	draw_lines(app);
	// draw_columns(app);
}
