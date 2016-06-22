/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/23 00:27:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			*init_size_win_zoom()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 20;	//42.fdf zoom
	tab_of_size[1] = 20;	//elem-col.fdf zoom
	tab_of_size[2] = 1;	//elem-fract.fdf zoom 2
	tab_of_size[3] = 20;	//elem.fdf zoom
	tab_of_size[4] = 15;	//elem2.fdf zoom
	tab_of_size[5] = 1;	//julia.fdf zoom
	tab_of_size[6] = 5;	//mars.fdf zoom 10
	tab_of_size[7] = 2;	//t1.fdf zoom 10
	tab_of_size[8] = 4;	//t2.fdf zoom 10
	return (tab_of_size);
}

int			*init_size_win_height()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 500;	//42.fdf height
	tab_of_size[1] = 800;	//elem-col.fdf height
	tab_of_size[2] = 1105;	//elem-fract.fdf height 1005
	tab_of_size[3] = 800;	//elem.fdf height
	tab_of_size[4] = 1100;	//elem2.fdf height
	tab_of_size[5] = 1080;	//julia.fdf height
	tab_of_size[6] = 1000;	//mars.fdf height 1080
	tab_of_size[7] = 1080;	//t1.fdf height 1080
	tab_of_size[8] = 1080;	//t2.fdf height 1080
	return (tab_of_size);
}

int			*init_size_win_width()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 800;	//42.fdf width
	tab_of_size[1] = 800;	//elem-col.fdf width
	tab_of_size[2] = 1100;	//elem-fract.fdf width 1000
	tab_of_size[3] = 800;	//elem.fdf width
	tab_of_size[4] = 1200;	//elem2.fdf width
	tab_of_size[5] = 1100;	//julia.fdf width
	tab_of_size[6] = 1750;	//mars.fdf width 1840
	tab_of_size[7] = 1220;	//t1.fdf width 1840
	tab_of_size[8] = 1220;	//t2.fdf width 1220
	return (tab_of_size);
}
