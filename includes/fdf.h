/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/15 15:03:41 by jmarsal          ###   ########.fr       */
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

typedef struct			s_coords
{
	// struct s_coords		*next;
	int					x;
	int					y;
	int					z;
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
	int					*tab_of_size_space_pix;
}						t_size_win;

typedef struct			s_win
{
	t_size_win			*size;
	int					width;
	int					height;
	size_t				div_const;
	size_t				space_pix;
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
	size_t				elem;
	size_t				i;
	size_t  			j;
}						t_get_data;

typedef struct			s_data
{
	// struct s_data		*next;
	t_coords			**data_elem;
	t_get_data			helper;
	// t_coords			*data_val;
	int					is_colors;
}						t_data;

typedef struct			s_params
{
	size_t				x_max;
	size_t				y_max;
	size_t				check_elements;
	double				const_power;
	int					move;
	int					zoom;
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
t_win		*init_win(int width, int heigth, size_t space_pix);
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
						t_data *data, t_coords **tab);

/*
** perror.c
*/

int			print_error(t_error err, int witch_one);

/*
** list.c
*/

void		coords_add_end(t_coords **alst, t_coords *new);
void		data_add_end(t_data **alst, t_data *new);

/*
** mlx_start.c
*/

void		mlx_start(t_app *app);

/*
** init_data.c
*/

char		*init_number_z(const char *line, size_t *i);
t_coords	*init_coords(int x, int y, int z, int color);
t_data		*init_data();

/*
** size_win.c
*/

int		 	read_name_for_size_win(const char *av, t_win *win);
int			*init_size_win_space_pix();
int			*init_size_win_height();
int			*init_size_win_width();

#endif
