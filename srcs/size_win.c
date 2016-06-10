/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:25:10 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/10 13:52:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			**init_size_win()
{
	int	**tab_of_size;
	int	index;

	index = 0;
	if ((tab_of_size = (int**)malloc(sizeof(int*) * NB_FILES)) == NULL)
		return (NULL);
	while (index < NB_FILES)
		tab_of_size[index++] = (int*)malloc(sizeof(int) * 3);
	tab_of_size[0][0] = 1000;
	tab_of_size[0][1] = 1000;
	tab_of_size[0][2] = 33;
	tab_of_size[1][0] = 600;
	tab_of_size[1][1] = 600;
	tab_of_size[1][2] = 31;
	tab_of_size[2][0] = 1840;
	tab_of_size[2][1] = 1080;
	tab_of_size[2][2] = 10;
	tab_of_size[3][0] = 400;
	tab_of_size[3][1] = 400;
	tab_of_size[3][2] = 30;
	tab_of_size[4][0] = 1920;
	tab_of_size[4][1] = 1080;
	tab_of_size[4][2] = 2;
	tab_of_size[5][0] = 1000;
	tab_of_size[5][1] = 1005;
	tab_of_size[5][2] = 2;
	return (tab_of_size);
}

static void		get_size(t_app *app, int **tab_of_size, int witch_file)
{
	app->win->width = tab_of_size[witch_file][0];
	app->win->height = tab_of_size[witch_file][1];
	app->win->space_pix = tab_of_size[witch_file][2];
}

void		 	read_name_for_size_win(const char *av, t_app *app)
{
	int **tab_of_size;

	tab_of_size = init_size_win();
	if (ft_strstr(av, "42.fdf"))
		get_size(app, tab_of_size, 0);
	else if (ft_strstr(av, "elem-col.fdf"))
		get_size(app, tab_of_size, 1);
	else if (ft_strstr(av, "elem-fract.fdf"))
		get_size(app, tab_of_size, 5);
	else if (ft_strstr(av, "elem.fdf"))
		get_size(app, tab_of_size, 3);
	else if (ft_strstr(av, "elem2.fdf"))
		get_size(app, tab_of_size, 1);
	else if (ft_strstr(av, "julia.fdf"))
		get_size(app, tab_of_size, 4);
	else if (ft_strstr(av, "mars.fdf"))
		get_size(app, tab_of_size, 2);
	else if (ft_strstr(av, "t1.fdf"))
		get_size(app, tab_of_size, 2);
	else if (ft_strstr(av, "t2.fdf"))
		get_size(app, tab_of_size, 4);
	else
		get_size(app, tab_of_size, 4);
}
