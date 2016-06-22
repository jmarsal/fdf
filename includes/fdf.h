/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 12:36:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h> // WARNING !!!

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# define BUFF_SIZE 1024
# define NB_FILES 9
# define H_RESIZE 18
# define NB_ERR 5
# define CST1 0.8
# define QUIT 53
# define Z_PLUS 69
# define Z_MINUS 78
# define T_LEFT 123
# define T_RIGHT 124
# define T_UP 126
# define T_DOWN 125

typedef struct			s_affine
{
	int					x;
	int					y;
	float				coef;
	float				cst;
}						t_affine;

typedef struct			s_coords
{
	int					x;
	int					y;
	float				z;
	int					color;
}						t_coords;

typedef struct			s_error
{
	char				**p_err;
}						t_error;

typedef struct			s_size_win
{
	int					*tab_of_size_width;
	int					*tab_of_size_height;
	int					*tab_of_size_zoom;
}						t_size_win;

typedef struct			s_win
{
	t_size_win			*size;
	float				const_power;
	double				move_z;
	float				zoom;
	int					width;
	int					height;
	int					move_horizontal;
	int					move_vertical;
}						t_win;

typedef struct			s_img
{
	void 				*img_ptr;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*mlx_win;
}						t_mlx;

typedef struct			s_get_data
{
	char				**elems;
	size_t				nb_elems;
	size_t				line;
	size_t				index;
	size_t				i;
	size_t  			j;
}						t_get_data;

typedef struct			s_data
{
	t_coords			**data_elem;
	t_get_data			helper;
	size_t				newsize;
	size_t				oldsize;
	int					is_colors;
}						t_data;

typedef struct			s_params
{
	size_t				x_max;
	size_t				y_max;
	size_t				check_elements;
}						t_params;

typedef struct			s_app
{
	t_mlx				*mlx;
	t_img				*img;
	t_win				*win;
	t_error				err;
	t_data				*data;
	t_params			*params;
}						t_app;

/*
**	init_app.c
*/

t_app		*init_app();
t_win		*init_win(int zoom, int width, int heigth, float move_z);
t_mlx		*init_mlx(t_win *win);
t_img		*init_img(t_mlx *mlx, t_win *win, t_error err);

/*
**	event.c
*/

int			key_hook(int keycode);
int			mouse_hook(int button, int x, int y);
int			change_z(int keycode, t_app *app);

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

/*
** init_size_win.c
*/

int			*init_size_win_zoom();
int			*init_size_win_height();
int			*init_size_win_width();

/*
** key_funct.c
*/

int			key_funct(int keycode, t_app *app);

#endif
