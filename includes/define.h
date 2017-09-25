/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 21:56:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/27 16:14:45 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** get_data
*/

# define BUFF_SIZE 1024
# define NB_FILES 22
# define NB_ERR 5
# define COLOR_DEF 0xFFFFFF
# define CST1 0.8
# define CST2 0.8
# define TAB_S_O_Z tmp->size->tab_of_size_zoom
# define ELEMS_LINES_INDEX app->data->data_elem[helper->line][helper->index]
# define Z_CHANGE 0.1
# define ZOOM_SPEED_P 0.6
# define ZOOM_SPEED_M 0.2
# define ZOOM_CHANGE app->win->zoom_change
# define FILENAME app->win->filename

/*
** keyhook
*/

# define KC keycode
# define QUIT 53
# define Z_PLUS 69
# define Z_MINUS 78
# define Z_PLUS2 24
# define Z_MINUS2 27
# define T_LEFT 123
# define T_RIGHT 124
# define T_UP 126
# define T_DOWN 125
# define T_MOVE 5
# define ORIGIN_POS 31
# define ISO 116
# define PARALELLE 121
# define UP_ZOOM 4
# define DOWN_ZOOM 5
# define ENTER 36
# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define H 4
# define I 34
# define J 38
# define K 40
# define R 15

/*
** win
*/

# define TITLE "fdf by jmarsal"
# define MLX_WIN app->mlx->mlx_win
# define MLX_PTR app->mlx->mlx_ptr
# define SIZE_MENU_W 350
# define SIZE_MENU_H 100
# define WIDTH 1920
# define WIDTH_DRAW 1300
# define HEIGHT 1080
# define HEIGHT_DRAW 800
# define MASK_CLOSE 1L << 17

/*
** print_strings
*/
# define PAR "Current proj   : paralelle"
# define ISOMETRIC "Current proj   : iso"
# define ERR_APP "\033[31mERROR\033[0m\n--> Can't create app !\n"
# define ERR_USAGE "\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n"

#endif
