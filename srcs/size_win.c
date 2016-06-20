/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:25:10 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/20 22:28:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		get_size(t_win *win, int witch_file)
{
	win->width = win->size->tab_of_size_width[witch_file];
	win->height = win->size->tab_of_size_height[witch_file];
	win->zoom = win->size->tab_of_size_zoom[witch_file];
}

int		 	read_name_for_size_win(const char *av, t_win *win)
{
	if (ft_strstr(av, "42.fdf"))
		get_size(win, 0);
	else if (ft_strstr(av, "elem-col.fdf"))
		get_size(win, 1);
	else if (ft_strstr(av, "elem-fract.fdf"))
		get_size(win, 2);
	else if (ft_strstr(av, "elem.fdf"))
		get_size(win, 3);
	else if (ft_strstr(av, "elem2.fdf"))
		get_size(win, 4);
	else if (ft_strstr(av, "julia.fdf"))
		get_size(win, 5);
	else if (ft_strstr(av, "mars.fdf"))
		get_size(win, 6);
	else if (ft_strstr(av, "t1.fdf"))
		get_size(win, 7);
	else if (ft_strstr(av, "t2.fdf"))
		get_size(win, 8);
	else
		get_size(win, 6);
	return (0);
}
