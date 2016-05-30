/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 16:09:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h> // WARNING !!!

# include "../libft/includes/libft.h"
# include <string.h>
# include <mlx.h>
# define WIDTH 1920
# define HEIGHT 1080
# define TIER WIDTH / 3

typedef struct		s_coords
{
	int				x;
	int				y;
	int				z;
	struct s_cords	*next;
}					t_coords;

typedef struct		s_colors
{
	int				color1;
	int				color2;
	int				color3;
}					t_colors;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void 			*img_ptr;
}					t_mlx;

/*
 **	init.c
 */

t_mlx		*init_mlx();
t_colors	init_colors();
t_coords	*init_coords();
int			close_win(t_mlx *mlx);

/*
 **	event.c
 */

int			key_hook(int keycode);
int			mouse_hook(int button, int x, int y);

/*
 **	draw.c
 */

void		draw_windows(t_coords *coords, t_mlx *data, t_colors color);

#endif
