/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/26 23:01:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h> // WARNING !!!

# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "define.h"
# include "structs.h"
# include "../libft/includes/libft.h"

/*
** main.c
*/

int			read_file(const char *av, t_app *app);
void		free_data(t_coords **data);

/*
**	init_app.c
*/

t_app		*init_app();
t_win		*init_win(int zoom, float move_z);
t_mlx		*init_mlx();
t_img		*init_img(t_app *app, int width, int height);

/*
**	event.c
*/

void		move_z(t_app *app, int keycode);
void		move_tray(t_app *app, int keycode);
void		get_original_pos(t_app *app);
void		change_proj(t_app *app, int keycode);
void		change_zoom(t_app *app, int button);

/*
**	draw.c
*/

void		draw_windows(t_app *app);

/*
** get_data.c
*/

int			get_data(t_app *app, const char *line, t_coords *c_data,
						t_data *data);

/*
** perror.c
*/

int			print_error(t_error err, int witch_one);

/*
** mlx_start.c
*/

void		mlx_start(t_app *app);
void 		print_info(t_app *app);
void 		refresh_win(t_app *app);

/*
** init_data.c
*/

t_coords	**init_tab(t_coords **tab, size_t line, size_t nb_elems);
t_coords	*init_coords(int y);
t_data		*init_data();

/*
** size_win.c
*/

int		 	read_name_for_size_win(const char *av, t_win *win);

/*
** affine.c
*/

void		check_affine(t_app *app, t_coords *c_elems, t_coords *n_elems);

/*
** draw_tools.c
*/

void		mlx_put_pixel_to_image(t_app *app, t_affine *c, int color);
t_coords	ch_data_paralelle(int is_color, t_win *win, t_coords data);
t_coords	ch_data_isometric(int is_color, t_win *win, t_coords data);

/*
** init_size_win.c
*/

int			*init_size_win_zoom(int *tab);

/*
** key_funct.c
*/

int			key_funct(int keycode, t_app *app);
int			mouse_funct(int button, int x, int y, t_app *app);

/*
** print_strings.c
*/

void		print_info(t_app *app);
void 		print_map_menu(t_app *app);

/*
** change_map.c
*/

void		change_map(t_app *app, int keycode);
void		new_map(t_app *app, int keycode);

#endif
