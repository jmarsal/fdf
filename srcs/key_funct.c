/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:46:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/03 16:37:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	keyfunct2(int keycode, t_app *app)
{
	if (KC == ENTER)
		change_map(app, KC);
	else if (KC == Z_PLUS || KC == Z_MINUS || KC == Z_PLUS2 || KC == Z_MINUS2)
		move_z(app, KC);
	else if (KC == T_LEFT || KC == T_RIGHT || KC == T_UP || KC == T_DOWN)
		move_tray(app, KC);
	else if (KC == ORIGIN_POS)
		get_original_pos(app);
	else if (KC == ISO || KC == PARALELLE)
		change_proj(app, KC);
	return (0);
}

int			key_funct(int keycode, t_app *app)
{
	// printf("keycode = %d\n", keycode);
	if (KC == QUIT)
		exit(0);
	if (app->if_menu == 1)
	{
		if (KC == A || KC == B || KC == C || KC == D ||
			KC == E || KC == F || KC == G || KC == H ||
			KC == I || KC == J || KC == K || (KC == R && app->c_map != NULL) ||
			KC == 83 || KC == 84 || KC == 85 || KC == 86 ||
			KC == 87 || KC == 88 || KC == 89 || KC == 91 ||
			KC == 92 || KC == 82)
			new_map(app, KC);
	}
	else
		keyfunct2(KC, app);
	return (0);
}

int			mouse_funct(int button, int x, int y, t_app *app)
{
	if (button == UP_ZOOM || button == DOWN_ZOOM)
		change_zoom(app, button);
	(void)x;
	(void)y;
	return (0);
}
