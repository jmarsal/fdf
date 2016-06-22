/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/22 11:40:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			*init_size_win_zoom()
{
	int	*tab_of_size;

	if (!(tab_of_size = ft_memalloc(sizeof(t_img) * NB_FILES)))
		return (NULL);
	tab_of_size[0] = 4;	//42.fdf zoom
	tab_of_size[1] = 3;	//elem-col.fdf zoom
	tab_of_size[2] = 1;	//elem-fract.fdf zoom 2
	tab_of_size[3] = 3;	//elem.fdf zoom
	tab_of_size[4] = 20;	//elem2.fdf zoom
	tab_of_size[5] = 1;	//julia.fdf zoom
	tab_of_size[6] = 2;	//mars.fdf zoom 10
	tab_of_size[7] = 1;	//t1.fdf zoom 10
	tab_of_size[8] = 2;	//t2.fdf zoom 10
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
