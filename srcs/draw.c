/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/05 00:49:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mlx_put_pixel_to_image(t_app *app, t_coords *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < app->win->width && c->y > 0 && c->y < app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

static void	draw_lines(t_app *app)
{
	t_coords	*coords;
	// t_coords	*test;
	// size_t		x;

	coords = app->data->data_val;
	while (coords->next)
	{
		// test = coords;
		// x = test->x + app->win->space_pix;
		// while (x <= coords->next->x + app->win->space_pix)
		// {
			// test->x = x;
			// mlx_put_pixel_to_image(app, test, coords->color);
			mlx_put_pixel_to_image(app, coords, coords->color);
			// x++;
		// }
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

static t_coords	*get_good_pos_in_win(t_app *app)
{
	t_coords	*new_pos;
	t_coords	*cur;
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	cur = app->data->data_val;
	while (cur)
	{
		if (cur->x < app->data->x_max - 2)
			x += app->win->space_pix;
		else
			x = 0;
		y += app->win->space_pix;
		printf("x = %lu, n_x = %lu\n", cur->x, x);
		printf("y = %lu, n_y = %lu\n", cur->y, y);
		coords_add_end(&new_pos, init_coords(x, cur->y, cur->z, cur->color));
		cur = cur->next;
	}
	return (new_pos);
}

void	draw_windows(t_app *app)
{
	app->data->data_val = get_good_pos_in_win(app);
	draw_lines(app);
	//draw_columns(app);
}
