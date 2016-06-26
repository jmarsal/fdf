/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 02:18:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_app *app)
{
	printf("key = %d\n", keycode);
	if (keycode == A || keycode == B || keycode == C || keycode == D ||
		keycode == E || keycode == F || keycode == G || keycode == H ||
		keycode == I || keycode == J || keycode == K || (keycode == R && app->c_map != NULL) ||
		keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86 ||
		keycode == 87 || keycode == 88 || keycode == 89 || keycode == 91 ||
		keycode == 92 || keycode == 82)
		new_map(app, keycode);
	else if (keycode == ENTER)
		change_map(app, keycode);
	else if (keycode == QUIT)
		exit(0);
	else if (keycode == Z_PLUS || keycode == Z_MINUS ||
		keycode == Z_PLUS2 || keycode == Z_MINUS2)
		move_z(app, keycode);
	else if (keycode == T_LEFT || keycode == T_RIGHT ||
		keycode == T_UP || keycode == T_DOWN)
		move_tray(app, keycode);
	else if (keycode == ORIGIN_POS)
		get_original_pos(app);
	else if (keycode == ISO || keycode == PARALELLE)
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
