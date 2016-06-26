/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:59:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 22:43:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_z(t_app *app, int KC)
{
	if (KC == Z_PLUS || KC == Z_PLUS2)
		app->win->move_z += Z_CHANGE;
	if (KC == Z_MINUS || KC == Z_MINUS2)
		app->win->move_z -= Z_CHANGE;
	refresh_win(app);
}

void	move_tray(t_app *app, int KC)
{
	if (KC == T_LEFT)
		app->win->move_horizontal -= T_MOVE;
	if (KC == T_RIGHT)
		app->win->move_horizontal += T_MOVE;
	if (KC == T_UP)
		app->win->move_vertical -= T_MOVE;
	if (KC == T_DOWN)
		app->win->move_vertical += T_MOVE;
	refresh_win(app);
}

void	get_original_pos(t_app *app)
{
	ZOOM_CHANGE = 1;
	app->win->move_z = 1;
	app->win->move_horizontal = WIDTH / 3;
	app->win->move_vertical = HEIGHT / 4;
	refresh_win(app);
}

void	change_proj(t_app *app, int KC)
{
	if (KC == ISO)
		app->win->witch_proj = 1;
	if (KC == PARALELLE)
		app->win->witch_proj = 0;
	refresh_win(app);
}

void	change_zoom(t_app *app, int button)
{
	if (button == UP_ZOOM)
		ZOOM_CHANGE += (app->win->zoom + ZOOM_CHANGE >= 100)
									? ZOOM_SPEED_P : ZOOM_SPEED_M;
	if ((button == DOWN_ZOOM) && (ZOOM_CHANGE > 1))
		ZOOM_CHANGE -= (app->win->zoom + ZOOM_CHANGE >= 100)
									? ZOOM_SPEED_P : ZOOM_SPEED_M;
	refresh_win(app);
}
