/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:11:49 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/20 14:33:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_affine(t_app *app, t_coords *c_elems, t_coords *n_elems,
							t_affine draw)
{
	draw.x = c_elems->x;
	while (draw.x < n_elems->x)
	{
		draw.y = draw.coef * draw.x + draw.cst;
		if (draw.y > draw.coef * (draw.x + 1) + draw.cst)
		{
			while (draw.y >= draw.coef * (draw.x + 1) + draw.cst)
			{
				mlx_put_pixel_to_image(app, &draw, c_elems->color);
				draw.y--;
			}
		}
		else
		{
			while (draw.y <= draw.coef * (draw.x + 1) + draw.cst)
			{
				mlx_put_pixel_to_image(app, &draw, c_elems->color);
				draw.y++;
			}
		}
		draw.x++;
	}
}

void			check_affine(t_app *app, t_coords *c_elems, t_coords *n_elems)
{
	t_affine affine;

	if (c_elems->x > n_elems->x)
		return (check_affine(app, n_elems, c_elems));
	affine.coef = (float)(n_elems->y - c_elems->y) /
					(float)(n_elems->x - c_elems->x);
	affine.cst = c_elems->y - (affine.coef * c_elems->x);
	draw_affine(app, c_elems, n_elems, affine);
}
