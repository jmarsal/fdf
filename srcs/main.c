/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/10 09:57:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		error_read(t_app *app, const char *av, int fd)
{
	char	*line;

	line = NULL;
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(app, 4));
	if (fd < 0)
		return (print_error(app, 0));
	return (0);
}

static int		read_file(const char **av, t_app *app)
{
	t_coords	*c_data;
	char		*line;
	int			fd;

	read_name_for_size_win(av[1], app);
	if ((c_data = init_coords(0, 0, 0, 0)) == NULL)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (error_read(app, av[1], fd) == -1)
		return (-1);
	while ((ft_get_next_line(fd, &line)) > 0)
	{
		app->params->x_max = 0;
		if ((get_data(app, line, c_data)) == -1)
			return (print_error(app, 2));
		c_data->y += app->win->space_pix;
		app->params->y_max++;
	}
	free (c_data);
	if (app->params->y_max == 0)
		return (print_error(app, 1));
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
		mlx_start(app);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n");
	return (0);
}
