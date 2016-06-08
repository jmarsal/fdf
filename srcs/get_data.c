/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 15:21:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_color(const char *line, size_t *i)
{
	int		len;
	int		color;
	char	*number;

	*i += 3;
	len = 0;
	while (!ft_isspace(line[*i + len]) && line[*i + len])
		++len;
	if ((number = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (-1);
	len = 0;
	while (line[*i + len] != ' ' && line[*i + len])
		{
			number[len] = line[*i + len];
			len++;
		}
	number[len] = '\0';
	color = ft_atoi_base(number, 16);
	free(number);
	return (color);
}

static char	*get_number(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	if ((number = init_number_z(line, i)) == NULL)
		return (NULL);
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		{
			number[len] = line[*i + len];
			len++;
		}
	number[len] = '\0';
	return (number);
}

static int	get_z(t_app *app, const char *line, size_t *i, t_coords *c_data)
{
	char	*number;

	if ((number = get_number(line, i)) == NULL)
		return (-1);
	if (line[*i] == ',')
	{
		if ((c_data->color = get_color(line, i)) == -1)
		{
			free(number);
			return (-1);
		}
		coords_add_end(&app->data->data_val,
			init_coords(c_data->x, c_data->y, ft_atoi(number), c_data->color));
	}
	else
		coords_add_end(&app->data->data_val,
			init_coords(c_data->x, c_data->y, ft_atoi(number), 0));
	c_data->x += app->win->space_pix;
	app->data->x_max++;
	free(number);
	return (0);
}

static int	parse_data(t_app *app, const char *line, t_coords *c_data)
{
	if (line[0] == ' ')
		while (!(ft_isspace(line[app->data->get_data.i++])) &&
											line[app->data->get_data.i])
	if (!ft_isdigit(line[app->data->get_data.i]))
		return (-1);
	app->data->get_data.elems = ft_strsplit(line, ' ');
	if (!app->data->get_data.nb_elems)
		find_size_of_win(app, &app->data->get_data.nb_elems,
			app->data->get_data.elems);
	while (app->data->get_data.elems[app->data->get_data.j])
	{
		app->data->get_data.i = 0;
		if (get_z(app, app->data->get_data.elems[app->data->get_data.j],
			&app->data->get_data.i,	c_data) == -1)
				return (-1);
		app->data->get_data.j++;
	}
	if (app->data->check_elements == 0)
		app->data->check_elements = app->data->x_max;
	return (0);
}

int			get_data(t_app *app, const char *line, t_coords *c_data)
{
	if ((app->data->get_data.elems = (char**)malloc(sizeof(char *) *
													ft_strlen(line))) == NULL)
	return (-1);
	app->data->get_data.j = 0;
	app->data->get_data.nb_elems = 0;
	c_data->x = 0;
	if ((parse_data(app, line, c_data)) == -1)
		return (-1);
	return ((app->data->check_elements != app->data->x_max) ? -1 : 0);
}
