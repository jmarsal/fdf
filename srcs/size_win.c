/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:25:10 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/16 23:57:22 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			*init_size_win_space_pix()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 33;	//42.fdf space_pix
	tab_of_size[1] = 31;	//elem-col.fdf stace_pix
	tab_of_size[2] = 2;		//elem-fract.fdf space_pix 2
	tab_of_size[3] = 30;	//elem.fdf space_pix
	tab_of_size[4] = 30;	//elem2.fdf space_pix
	tab_of_size[5] = 2;		//julia.fdf space_pix
	tab_of_size[6] = 8;		//mars.fdf space_pix 10
	tab_of_size[7] = 3;		//t1.fdf space_pix 10
	tab_of_size[8] = 10;	//t2.fdf space_pix 10
	return (tab_of_size);
}

int			*init_size_win_height()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 500;	//42.fdf height
	tab_of_size[1] = 450;	//elem-col.fdf height
	tab_of_size[2] = 1105;	//elem-fract.fdf height 1005
	tab_of_size[3] = 400;	//elem.fdf height
	tab_of_size[4] = 700;	//elem2.fdf height
	tab_of_size[5] = 1080;	//julia.fdf height
	tab_of_size[6] = 1000;	//mars.fdf height 1080
	tab_of_size[7] = 700;	//t1.fdf height 1080
	tab_of_size[8] = 1080;	//t2.fdf height 1080
	return (tab_of_size);
}

int			*init_size_win_width()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 800;	//42.fdf width
	tab_of_size[1] = 500;	//elem-col.fdf width
	tab_of_size[2] = 1100;	//elem-fract.fdf width 1000
	tab_of_size[3] = 400;	//elem.fdf width
	tab_of_size[4] = 750;	//elem2.fdf width
	tab_of_size[5] = 1220;	//julia.fdf width
	tab_of_size[6] = 1750;	//mars.fdf width 1840
	tab_of_size[7] = 850;	//t1.fdf width 1840
	tab_of_size[8] = 1220;	//t2.fdf width 1220
	return (tab_of_size);
}

static void		get_size(t_win *win, int witch_file)
{
	win->width = win->size->tab_of_size_width[witch_file];
	win->height = win->size->tab_of_size_height[witch_file];
	win->space_pix = win->size->tab_of_size_space_pix[witch_file];
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
