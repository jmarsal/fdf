/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/13 15:42:58 by jmarsal          ###   ########.fr       */
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
	*i += len;
	return (number);
}

static int	get_z(t_app *app, const char *line, size_t *i, t_coords *c_data)
{
	char	*number;
	int		z;
	int		color;

	color = 0;
	if ((number = get_number(line, i)) == NULL)
		return (-1);
	z = ft_atoi(number);
	if (line[*i] && line[*i] == ',')
	{
		if ((c_data->color = get_color(line, i)) == -1)
		{
			free(number);
			return (-1);
		}
		color = c_data->color;
		app->data->is_colors = 1;
	}
	coords_add_end(&app->data->data_val, init_coords(c_data->x, c_data->y, z,
														color));
	c_data->x += app->win->space_pix;
	app->params->x_max++;
	free(number);
	return (0);
}

static int	parse_data(t_app *app, const char *line, t_coords *c_data,
						t_get_data *helper)
{
	helper->elems = ft_strsplit(line, ' ');
	if (!helper->nb_elems)
	{
		while (helper->elems[++helper->nb_elems])
			;
	}
	while (helper->elems[helper->j])
	{
		helper->i = 0;
		if (get_z(app, helper->elems[helper->j], &helper->i, c_data) == -1)
				return (-1);
		helper->j += 1;
	}
	if (app->params->check_elements == 0)
		app->params->check_elements = app->params->x_max;
	return (0);
}

int			get_data(t_app *app, const char *line, t_coords *c_data)
{
	t_get_data	helper;

	if (!(helper.elems = (char**)malloc(sizeof(char *) * ft_strlen(line))))
		return (-1);
	helper.i = 0;
	helper.j = 0;
	helper.nb_elems = 0;
	c_data->x = 0;
	if ((parse_data(app, line, c_data, &helper)) == -1)
		return (-1);
	data_add_end(&app->data, init_data(app->data->data_val));
	app->data->data_val = NULL;
	return ((app->params->check_elements != app->params->x_max) ? -1 : 0);
}
