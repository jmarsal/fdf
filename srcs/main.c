/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 22:41:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}

static int			error_read(t_app *app, const char *av)
{
	char	*line;

	line = NULL;
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(app, 5));
	if (app->fd < 0)
		return (print_error(app, 0));
	return (0);
}

static int		read_file(const char **av, t_app *app)
{
	t_coords	*c_data;
	char		*line;
	int			ret;

	line = NULL;
	if ((c_data = init_coords(0, 0, 0, 0)) == NULL)
		return (-1);
	app->fd = open(av[1], O_RDONLY);
	if (error_read(app, av[1]) == -1)
		return (-1);
	while ((ft_get_next_line(app->fd, &line)) > 0)
	{
		if ((ret = get_data(app, line, c_data)) == -1)
			return (print_error(app, 2));
		c_data->y += 1 + TIER;
		app->data->y_max++;
	}
	if (app->data->y_max == 0)
		return (print_error(app, 1));
	if (close(app->fd) == -1)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_app		*app;

	if (ac == 2)
	{
		if ((app = init_app(av)) == NULL)
		{
			ft_putstr("\033[31mERROR\033[0m\n--> Can't create app !\n");
			exit (-1);
		}
		if (read_file((const char**)av, app) == -1)
			exit (-1);
		mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
		mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
		draw_windows(app);
		mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win,
			app->img->img_ptr, 0, 0);
		mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
		mlx_loop(app->mlx->mlx_ptr);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n");
	return (0);
}
