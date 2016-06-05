/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:52:20 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/05 00:49:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		find_and_init_good_size_of_win(t_app *app)
{
	size_t	width;
	size_t	height;

	width = ((app->data->x_max * 530) / 20);
	height = ((app->data->y_max * 410) / 12);
	printf("width = %lu, height = %lu\n", width, height);
	// if (width <= 1920 || height <= 1080)
	// 	app->win = init_win(width, height, 3, 50);
	// else
		app->win = init_win(1920, 1080, 3, 50);
	if ((app->mlx = init_mlx(app)) == NULL ||
		(app->img = init_img(app)) == NULL)
	{
		ft_putstr("\033[31mERROR\033[0m\n--> Can't create app !\n");
		return (-1);
	}
	return (0);
}
