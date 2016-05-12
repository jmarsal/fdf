/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/09 16:32:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		main()
{
	t_mlx	data;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480,
					"fdf by jmarsal")) == NULL)
		return (-1);
	while (x <= 640 && y <= 160)
	{
		if (x == 640)
		{
			y++;
			x = 0;
		}
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xADFF2F);
		x++;
	}
	while (x <= 640 && y <= 320)
	{
		if (x == 640)
		{
			y++;
			x = 0;
		}
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xFFFF00);
		x++;
	}
	while (x <= 640 && y <= 480)
	{
		if (x == 640)
		{
			y++;
			x = 0;
		}
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xFF0000);
		x++;
	}
	mlx_loop(data.mlx_ptr);
	return (0);
}
