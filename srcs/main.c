/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/03 16:34:45 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	error_read(t_error err, const char *av, int fd)
{
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(err, 4));
	if (fd < 1)
		return (print_error(err, 0));
	return (0);
}

static int	get_data_in_line(t_app *app, t_data *data, char *line,
									t_coords *c_data)
{
	void	*new;
	size_t	new_size;

	new_size = sizeof(void *) * data->oldsize * 2;
	if (data->helper.line % (data->oldsize - 1) == 0)
	{
		if (!(new = ft_realloc(data->data_elem, new_size, data->oldsize)))
			return (-1);
		data->data_elem = new;
		data->oldsize = new_size;
	}
	data->data_elem[app->params->y_max] = NULL;
	if ((get_data(app, line, c_data, data)) == -1)
		return (print_error(app->err, 2));
	c_data->y += 1;
	app->params->y_max++;
	data->helper.line++;
	return (0);
}

void		free_data(t_coords **data)
{
	size_t	lines;

	lines = 0;
	while (data[lines])
	{
		ft_free(data[lines]);
		lines++;
	}
	ft_free(data);
}

int			read_file(const char *av, t_app *app)
{
	t_coords	*c_data;
	char		*line;
	int			fd;

	line = NULL;
	if ((fd = open(av, O_RDONLY)) < 1)
		exit(-1);
	if (error_read(app->err, av, fd) == -1)
		exit(-1);
	read_name_for_size_win(av, app->win);
	if ((c_data = init_coords(0)) == NULL)
		return (-1);
	while ((ft_get_next_line(fd, &line)) > 0)
		if ((get_data_in_line(app, app->data, line, c_data)) == -1)
		{
			free_data(app->data->data_elem);
			return (-1);
		}
	ft_free(c_data);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_app		*app;

	if (ac == 2)
	{
		if ((app = init_app(av[1])) == NULL)
		{
			ft_putstr(ERR_APP);
			exit(-1);
		}
		if (read_file((const char*)av[1], app) == -1)
		{
			ft_free(app->data->helper.elems);
			exit(-1);
		}
		mlx_start(app);
	}
	else
		ft_putstr(ERR_USAGE);
	return (0);
}
