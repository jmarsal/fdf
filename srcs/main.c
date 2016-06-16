/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/16 12:45:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		error_read(t_error err, const char *av, int fd)
{
	char	*line;

	line = NULL;
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(err, 4));
	if (fd < 0)
		return (print_error(err, 0));
	return (0);
}

static int		read_file(const char **av, t_app *app)
{
	t_coords	*c_data;
	char		*line;
	int			fd;

	read_name_for_size_win(av[1], app->win);
	if ((c_data = init_coords(0, 0, 0, 0)) == NULL)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (error_read(app->err, av[1], fd) == -1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	while ((ft_get_next_line(fd, &line)) > 0)
	{
		if (app->data->helper.line % (app->data->oldsize - 1) == 0)
		{
			if (!(app->data->data_elem = ft_realloc(app->data->data_elem,
				app->data->newsize * app->data->oldsize, app->data->oldsize)))
			return (-1);
			app->data->oldsize = app->data->newsize;
			app->data->newsize = app->data->oldsize * 2;
		}
		if ((get_data(app, line, c_data, app->data, app->data->data_elem))
			== -1)
			return (print_error(app->err, 2));
		c_data->y += app->win->space_pix;
		app->params->y_max++;
		app->data->helper.line++;
	}
	free (c_data);
	if (app->data->helper.line == 0)
		return (print_error(app->err, 1));
	if (close(fd) == -1)
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
		// mlx_start(app);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n");
	return (0);
}
