/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/31 14:55:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h> // WARNING !!!

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# define BUFF_SIZE 1024
# define WIDTH 1920
# define HEIGHT 1080
# define TIER WIDTH / 3

typedef struct		s_coords
{
	struct s_cords	*next;
	int				x;
	int				y;
	int				z;
}					t_coords;

typedef struct		s_colors
{
	int				color1;
	int				color2;
	int				color3;
}					t_colors;

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

typedef struct		s_app
{
	t_mlx			*mlx;
	t_img			*img;
	t_colors		color;
	t_coords		*coords;
	int				len;
	char			*buf;
	char			**data;
}					t_app;

/*
**	init.c
*/

t_app		*init_app();
t_mlx		*init_mlx();
t_img		*init_img(t_app *env);
t_colors	init_colors();
t_coords	*init_coords();

/*
**	event.c
*/

int			close_win(t_mlx *mlx);
int			key_hook(int keycode);
int			mouse_hook(int button, int x, int y);

/*
**	draw.c
*/

void		mlx_put_pixel_to_image(t_app *app, t_coords *c, int color);
void		draw_windows(t_app *app);

/*
** get_data.c
*/


#endif
