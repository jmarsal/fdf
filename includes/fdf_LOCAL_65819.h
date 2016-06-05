/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/04 23:27:19 by jmarsal          ###   ########.fr       */
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
# define NB_ERR 4

typedef struct		s_colors
{
	int				color1;
	int				color2;
	int				color3;
}					t_colors;

typedef struct		s_coords
{
	struct s_coords	*next;
	size_t			x;
	size_t			y;
	int				z;
	int				color;
}					t_coords;

typedef struct		s_error
{
	char			**p_err;
}					t_error;

typedef struct		s_win
{
	size_t			width;
	size_t			height;
	size_t			div_const;
	size_t			space_pix;
}					t_win;

typedef struct		s_img
{
	void 			*img_ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct		s_data
{
	t_coords		*data_val;
	size_t			x_max;
	size_t			y_max;
}					t_data;

typedef struct		s_app
{
	t_mlx			*mlx;
	t_img			*img;
	t_colors		color;
	t_win			*win;
	// t_coords		*coords;
	t_error			err;
	t_data			*data;
	int				fd;
	int				len;
}					t_app;

/*
**	init.c
*/

t_app		*init_app();
t_coords	*init_coords(int x, int y, int z, int color);
t_win		*init_win(size_t width, size_t heigth, size_t div_const, size_t space_pix);
t_mlx		*init_mlx(t_app *app);
t_img		*init_img(t_app *app);

/*
**	event.c
*/

int			key_hook(int keycode);
int			mouse_hook(int button, int x, int y);

/*
**	draw.c
*/

void		draw_windows(t_app *app);

/*
** get_data.c
*/

int			get_data(t_app *app, const char *line, t_coords *c_data);

/*
** perror.c
*/

int			print_error(t_app *app, int witch_one);

/*
** list.c
*/

void		coords_add_end(t_coords **alst, t_coords *new);

/*
** size_win.c
*/

int			find_and_init_good_size_of_win(t_app *app);

#endif
