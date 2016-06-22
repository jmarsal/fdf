/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 16:06:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_funct(int keycode, t_app *app)
{
	if (keycode == QUIT)
		exit(0);
	if (keycode == Z_PLUS || keycode == Z_MINUS)
		move_z(app, keycode);
	if (keycode == T_LEFT || keycode == T_RIGHT ||
		keycode == T_UP || keycode == T_DOWN)
		move_tray(app, keycode);
	if (keycode == ORIGIN_POS)
		get_original_pos(app);
	if (keycode == ISO || keycode == PARALELLE)
		change_proj(app, keycode);
	return (0);
}

int		mouse_funct(int button, int x, int y, t_app *app)
{
	if (button == UP_ZOOM || button == DOWN_ZOOM)
		change_zoom(app, button);
	(void)x;
	(void)y;
	return (0);
}
