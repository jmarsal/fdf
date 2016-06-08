/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 23:56:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			error_read(t_app *app, const char *av)
{
	char	*line;

	line = NULL;
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(app, 4));
	if (app->fd < 0)
		return (print_error(app, 0));
	return (0);
}

static void		find_good_size_win(const char *av, t_app *app)
{
	int **tab_of_size;

	tab_of_size = init_size_win();
	if (ft_strstr(av, "42.fdf"))
		get_size(app, tab_of_size, 0);
	else if (ft_strstr(av, "elem-col.fdf"))
		get_size(app, tab_of_size, 1);
	else if (ft_strstr(av, "elem-fract.fdf"))
		get_size(app, tab_of_size, 2);
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

static int		read_file(const char **av, t_app *app)
{
	t_coords	*c_data;
	char		*line;
	int			ret;

	find_good_size_win(av[1], app);
	if ((c_data = init_coords(0, 0, 0, 0)) == NULL)
		return (-1);
	app->fd = open(av[1], O_RDONLY);
	if (error_read(app, av[1]) == -1)
		return (-1);
	while ((ft_get_next_line(app->fd, &line)) > 0)
	{
		app->data->x_max = 0;
		if ((ret = get_data(app, line, c_data)) == -1)
			return (print_error(app, 2));
		c_data->y += app->win->space_pix;
		app->data->y_max++;
	}
	free (c_data);
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
			printf("width = %lu\n", app->win->width);
			printf("height = %lu\n", app->win->height);
		mlx_start(app);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n");
	return (0);
}
