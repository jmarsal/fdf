/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/19 00:38:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_z(t_app *app, const char *line, t_get_data *h, t_coords *c_data)
{
	char	*number;

	if (!(number = ft_get_number(line, &h->i)))
		return (-1);
	c_data->z = ft_atoi(number);
	free(number);
	if (line[h->i] && line[h->i] == ',')
	{
		h->i++;
		if ((c_data->color = ft_get_color_mlx(line, &h->i)) == -1)
			return (-1);
		app->data->is_colors = 1;
	}
	else
		c_data->color = (c_data->color == 0) ? 0xFFFFFF : c_data->color;
	c_data->x += 1;
	return (0);
}

static int	parse_data(t_app *app, const char *line, t_coords *c_data,
						t_get_data *helper)
{
	helper->elems = ft_strsplit(line, ' ');
	if (!helper->nb_elems)
		while (helper->elems[++helper->nb_elems])
			;
	app->params->x_max = helper->nb_elems;
	if (!(app->data->data_elem = init_tab(app->data->data_elem, helper->line,
		helper->nb_elems)))
		return (-1);
	while (helper->elems[helper->j])
	{
		helper->i = 0;
		if (get_z(app, helper->elems[helper->j], helper, c_data) == -1)
			return (-1);
		app->data->data_elem[helper->line][helper->index].x = c_data->x;
		app->data->data_elem[helper->line][helper->index].y = c_data->y;
		app->data->data_elem[helper->line][helper->index].z = c_data->z;
		app->data->data_elem[helper->line][helper->index].color = c_data->color;
		helper->index++;
		helper->j++;
	}
	if (app->params->check_elements == 0)
		app->params->check_elements = app->params->x_max;
	return (0);
}

int			get_data(t_app *app, const char *line, t_coords *c_data,
						t_data *data)
{
	if (!(c_data = init_coords(0, c_data->y, c_data->z, c_data->color)))
		return (-1);
	if (!(data->helper.elems = ft_memalloc(sizeof(char) * ft_strlen(line))))
		return (-1);
	data->helper.i = 0;
	data->helper.j = 0;
	data->helper.nb_elems = 0;
	data->helper.index = 0;
	app->params->x_max = 0;
	if ((parse_data(app, line, c_data, &data->helper)) == -1)
		return (-1);
	return ((app->params->check_elements != app->params->x_max) ? -1 : 0);
}
