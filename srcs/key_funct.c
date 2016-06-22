/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 12:52:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_funct(int keycode, t_app *app)
{
	printf("keycode = %d\n", keycode);
	if (keycode == QUIT)
		exit(0);
	if (keycode == Z_PLUS || keycode == Z_MINUS)
		move_z(app, keycode);
	if (keycode == T_LEFT || keycode == T_RIGHT ||
		keycode == T_UP || keycode == T_DOWN)
		move_tray(app, keycode);
	if (keycode == ORIGIN_POS)
		get_original_pos(app);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("button : %d, pos : (%d,%d)\n", button, x, y);
	return (0);
}
