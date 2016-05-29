/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:11:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/27 23:11:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_windows(t_coords *coords, t_mlx *data, t_colors color)
{
	while (coords->x <= WIDTH && coords->y <= HEIGHT)
	{
		if (coords->x == WIDTH)
		{
			coords->y++;
			coords->x = 0;
		}
		if (coords->x <= TIER * 1)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, coords->x, coords->y, color.color1);
		if (coords->x >= TIER * 1 && coords->x <= TIER * 2)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, coords->x, coords->y, color.color2);
		if (coords->x >= TIER * 2 && coords->x <= TIER * 3)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, coords->x, coords->y, color.color3);
		coords->x++;
	}
}
