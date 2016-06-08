/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:03:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/09 00:20:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

void			find_size_of_win(t_app *app, size_t *nb_elem, char **elems)
{
	size_t count_elems;

	count_elems = 0;
	while (elems[++count_elems])
	;
	app->win->space_pix = app->win->width / count_elems;
	*nb_elem = count_elems;
}

void			get_size(t_app *app, int **tab_of_size, int witch_file)
{
	app->win->width = tab_of_size[witch_file][0];
	app->win->height = tab_of_size[witch_file][1];
}

int				**init_size_win()
{
	int	**tab_of_size;
	int	index;

	index = 0;
	if ((tab_of_size = (int**)malloc(sizeof(int*) * NB_FILES)) == NULL)
		return (NULL);
	while (index < NB_FILES)
		tab_of_size[index++] = (int*)malloc(sizeof(int) * 2);
	tab_of_size[0][0] = 600;
	tab_of_size[0][1] = 350;
	tab_of_size[1][0] = 600;
	tab_of_size[1][1] = 600;
	tab_of_size[2][0] = 1840;
	tab_of_size[2][1] = 1080;
	tab_of_size[3][0] = 400;
	tab_of_size[3][1] = 400;
	tab_of_size[4][0] = 1920;
	tab_of_size[4][1] = 1080;
	tab_of_size[5][0] = 1520;
	tab_of_size[5][1] = 1080;
	return (tab_of_size);
}

void			mlx_start(t_app *app)
{
	app->win = init_win(app->win->width, app->win->height, 3, 0);
	if ((app->mlx = init_mlx(app)) == NULL ||
		(app->img = init_img(app)) == NULL)
	{
		print_error(app, 5);
		exit (-1);
	}
	mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
	mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
	draw_windows(app);
	mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
		app->img->img_ptr, 0, 0);
	mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
	mlx_loop(app->mlx->mlx_ptr);
}
