/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/10 09:58:53 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mlx_put_pixel_to_image(t_app *app, t_affine *c, int color)
{
	int		octet;

	octet = app->img->bpp / 8;
	if (c->x > 0 && c->x < (int)app->win->width && c->y > 0 && c->y < (int)app->win->height)
		ft_memcpy(&app->img->data[octet * (c->x + app->img->sizeline /
					octet * c->y)], &color, octet);
}

static void		get_color(t_app *env, t_coords *start, t_coords *end, t_affine c)
{
	if (start->color > end->color)
		mlx_put_pixel_to_image(env, &c, end->color);
	else
		mlx_put_pixel_to_image(env, &c, start->color);
}

static void		draw_affine(t_app *env, t_coords *start, t_coords *end, t_affine c)
{
	c.x = start->x;
	while (c.x < (int)end->x)
	{
		c.y = c.coef * c.x + c.cst;
		if (c.y > c.coef * (c.x + 1) + c.cst)
		{
			while (c.y >= c.coef * (c.x + 1) + c.cst)
			{
				get_color(env, start, end, c);
				c.y--;
			}
		}
		else
		{
			while (c.y <= c.coef * (c.x + 1) + c.cst)
			{
				get_color(env, start, end, c);
				c.y++;
			}
		}
		c.x++;
	}
}

void			check_affine(t_app *env, t_coords *start, t_coords *end)
{
	t_affine affine;

	if (start->x > end->x)
		return (check_affine(env, end, start));
	affine.coef = (float)(end->y - start->y) / (float)(end->x - start->x);
	affine.cst = start->y - (affine.coef * start->x);
	draw_affine(env, start, end, affine);
}

void			draw_vertical(t_app *env, t_coords *start, t_coords *end)
{
	t_affine		c;

	c.x = (int)start->x;
	c.y = (int)start->y;
	if (c.y < (int)end->y)
	{
		while (c.y <= (int)end->y)
		{
			mlx_put_pixel_to_image(env, &c, start->color);
			c.y++;
		}
	}
	else if (c.y > (int)end->y)
	{
		while (c.y >= (int)end->y)
		{
			mlx_put_pixel_to_image(env, &c, start->color);
			c.y--;
		}
	}
}

static t_coords	*parallel(t_app *app, t_coords *coords)
{
	t_coord		tmp;

	tmp.z = -coords->z * app->params->const_power;
	tmp.y = coords->y * app->win->space_pix;
	tmp.x = coords->x * tmp.z * app->win->space_pix;
	if (coords->color == 0xFFFFFF && tmp.z > 0)
		coords->color = 0xff0000;
	// printf("%lu\n", app->win->space_pix);
	return (init_coords(tmp.x, tmp.y, tmp.z, coords->color));
}

static void		check_lines(t_app *app, t_coords *coord, t_coords *next)
{
	t_coords		*tmp1;
	t_coords		*tmp2;

	tmp1 = parallel(app, coord);
	tmp2 = parallel(app, next);
	if ((tmp1->x - tmp2->x) == 0)
		draw_vertical(app, coord, next);
	else
		check_affine(app, coord, next);
}

void			draw_line(t_app *app, t_coords *coord, t_coords *next)
{
	if (coord->x != app->params->x_max)
		check_lines(app, coord, next);
}

void	draw_windows(t_app *app)
{
	t_data		*lst_cur;
	t_coords	*coords_cur;
	t_coords	*coords_next;

	lst_cur = app->data;
	while (lst_cur->next)
	{
		coords_cur = lst_cur->data_val;
		coords_next = lst_cur->next->data_val;
		while (coords_cur && coords_next->next)
		{
			draw_line(app, coords_cur, coords_next);
			coords_cur = coords_cur->next;
			coords_next = coords_next->next;
		}
		lst_cur = lst_cur->next;
	}
}
