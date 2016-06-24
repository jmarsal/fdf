/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/25 01:14:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_col_bet_points(t_app *app, t_coords c_line, t_coords n_line,
								t_affine draw)
{
	if (draw.y < n_line.y)
	{
		while (draw.y < n_line.y)
		{
			mlx_put_pixel_to_image(app, &draw, c_line.color);
			draw.y++;
		}
	}
	else if (draw.y > n_line.y)
	{
		while (draw.y > n_line.y)
		{
			mlx_put_pixel_to_image(app, &draw, c_line.color);
			draw.y--;
		}
	}
}

t_coords	witch_proj(int is_color, t_win *win, t_coords data)
{
	t_coords	modify;

	if (win->witch_proj == 0)
		modify = ch_data_paralelle(is_color, win, data);
	else
		modify = ch_data_isometric(is_color, win, data);
	return (modify);
}

static void	draw_columns(t_app *app, t_coords **n_data, size_t lines,
							size_t elems)
{
	t_coords	c_line;
	t_coords	n_line;
	t_affine	draw;

	c_line = witch_proj(app->data->is_colors, app->win,
									n_data[lines][elems]);
	draw.x = c_line.x;
	draw.y = c_line.y;
	if (n_data[lines + 1])
		n_line = witch_proj(app->data->is_colors, app->win,
										n_data[lines + 1][elems]);
	else
		n_line = c_line;
	if (c_line.x - n_line.x == 0)
		draw_col_bet_points(app, c_line, n_line, draw);
	else
		check_affine(app, &c_line, &n_line);
}

static void	draw_line(t_app *app, t_coords **n_data, size_t lines, size_t elems)
{
	t_coords	c_elems;
	t_coords	n_elems;
	t_affine	draw;

	c_elems = witch_proj(app->data->is_colors, app->win,
									n_data[lines][elems]);
	draw.x = c_elems.x;
	draw.y = c_elems.y;
	if (elems + 1 < app->params->x_max)
		n_elems = witch_proj(app->data->is_colors, app->win,
										n_data[lines][elems + 1]);
	else
		n_elems = c_elems;
	if (c_elems.y - n_elems.y == 0)
	{
		while (draw.x < n_elems.x)
		{
			mlx_put_pixel_to_image(app, &draw, c_elems.color);
			draw.x++;
		}
	}
	else
		check_affine(app, &c_elems, &n_elems);
}

void		draw_windows(t_app *app)
{
	t_coords	**n_data;
	size_t		lines;
	size_t		elems;

	n_data = app->data->data_elem;
	lines = 0;
	while (n_data[lines])
	{
		elems = 0;
		while (elems < app->params->x_max)
		{
			draw_line(app, n_data, lines, elems);
			draw_columns(app, n_data, lines, elems);
			elems++;
		}
		lines++;
	}
	elems = 0;
}
