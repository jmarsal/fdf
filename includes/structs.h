/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 21:56:20 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 17:38:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int					*tab_of_size_zoom;
}						t_size_win;

typedef struct			s_win
{
	t_size_win			*size;
	double				move_z;
	float				zoom;
	float				zoom_change;
	int					move_horizontal;
	int					move_vertical;
	int					witch_proj;
	char				*filename;
}						t_win;

typedef struct			s_img
{
	void				*img_ptr;
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
	size_t				j;
}						t_get_data;

typedef struct			s_data
{
	t_coords			**data_elem;
	t_get_data			helper;
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
	t_img				*img_ecole;
	t_img				*cadre;
	t_img				*phenix;
	t_img				*rtfm;
	t_img				*menu;
	t_img				*c_map;
	t_win				*win;
	t_error				err;
	t_data				*data;
	t_params			*params;
	int					if_menu;
}						t_app;

#endif
