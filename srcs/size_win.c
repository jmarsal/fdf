/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:25:10 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/25 01:14:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_size(const char *filename, t_win *win, int witch_file)
{
	win->filename = ft_strtoupper(ft_strcut_before(filename, '.'));
	win->width = 1300;
	win->height = 800;
	win->zoom = win->size->tab_of_size_zoom[witch_file];
}

static int	 	read_name_for_size_win2(const char *av, t_win *win)
{
	if (ft_strstr(av, "pylone.fdf"))
		get_size(av, win, 11);
	else if (ft_strstr(av, "pnp_flat.fdf"))
		get_size(av, win, 12);
	else if (ft_strstr(av, "plat.fdf"))
		get_size(av, win, 13);
	else if (ft_strstr(av, "pentenegpos.fdf"))
		get_size(av, win, 14);
	else if (ft_strstr(av, "basictest.fdf"))
		get_size(av, win, 15);
	else if (ft_strstr(av, "100-6.fdf"))
		get_size(av, win, 16);
	else if (ft_strstr(av, "50-4.fdf"))
		get_size(av, win, 17);
	else if (ft_strstr(av, "20-60.fdf"))
		get_size(av, win, 18);
	else if (ft_strstr(av, "10-70.fdf"))
		get_size(av, win, 19);
	else if (ft_strstr(av, "10-2.fdf"))
		get_size(av, win, 20);
	else
		get_size(av, win, 6);
	return (0);
}

int		 	read_name_for_size_win(const char *av, t_win *win)
{
	if (ft_strstr(av, "42.fdf"))
		get_size(av, win, 0);
	else if (ft_strstr(av, "elem-col.fdf"))
		get_size(av, win, 1);
	else if (ft_strstr(av, "elem-fract.fdf"))
		get_size(av, win, 2);
	else if (ft_strstr(av, "elem.fdf"))
		get_size(av, win, 3);
	else if (ft_strstr(av, "elem2.fdf"))
		get_size(av, win, 4);
	else if (ft_strstr(av, "julia.fdf"))
		get_size(av, win, 5);
	else if (ft_strstr(av, "mars.fdf"))
		get_size(av, win, 6);
	else if (ft_strstr(av, "t1.fdf"))
		get_size(av, win, 7);
	else if (ft_strstr(av, "t2.fdf"))
		get_size(av, win, 8);
	else if (ft_strstr(av, "pyramide.fdf"))
		get_size(av, win, 9);
	else if (ft_strstr(av, "pyra.fdf"))
		get_size(av, win, 10);
	else
		read_name_for_size_win2(av, win);
	return (0);
}
