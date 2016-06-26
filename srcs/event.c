/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:59:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 01:05:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_z(t_app *app, int keycode)
{
	if (keycode == Z_PLUS || keycode == Z_PLUS2)
		app->win->move_z += Z_CHANGE;
	if (keycode == Z_MINUS || keycode == Z_MINUS2)
		app->win->move_z -= Z_CHANGE;
	refresh_win(app);
}

void	move_tray(t_app *app, int keycode)
{
	if (keycode == T_LEFT)
		app->win->move_horizontal -= T_MOVE;
	if (keycode == T_RIGHT)
		app->win->move_horizontal += T_MOVE;
	if (keycode == T_UP)
		app->win->move_vertical -= T_MOVE;
	if (keycode == T_DOWN)
		app->win->move_vertical += T_MOVE;
	refresh_win(app);
}

void	get_original_pos(t_app *app)
{
	app->win->zoom_change = 1;
	app->win->move_z = 1;
	app->win->move_horizontal = 1920 / 3;
	app->win->move_vertical = 1080 / 4;
	refresh_win(app);
}

void	change_proj(t_app *app, int keycode)
{
	if (keycode == ISO)
		app->win->witch_proj = 1;
	if (keycode == PARALELLE)
		app->win->witch_proj = 0;
	refresh_win(app);
}

void	change_zoom(t_app *app, int button)
{
	if (button == UP_ZOOM)
		app->win->zoom_change += (app->win->zoom + app->win->zoom_change >= 100)
									? 0.6 : 0.2;
	if ((button == DOWN_ZOOM) && (app->win->zoom_change > 1))
		app->win->zoom_change -= (app->win->zoom + app->win->zoom_change >= 100)
									? 0.6 : 0.2;
	refresh_win(app);
}
