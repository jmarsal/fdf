/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 22:43:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_z(t_app *app, const char *line, t_get_data *h, t_coords *c_data)
{
	char	*number;

	if (!(number = ft_get_number(line, &h->i)))
		return (-1);
	c_data->z = ft_atoi(number);
	ft_free_null(number);
	if (line[h->i] && line[h->i] == ',')
	{
		h->i++;
		if ((c_data->color = ft_get_color_mlx(line, &h->i)) == -1)
			return (-1);
		app->data->is_colors = 1;
	}
	c_data->color = (c_data->color == 0) ? COLOR_DEF : c_data->color;
	c_data->x += 1;
	return (0);
}

static int	parse_data(t_app *app, const char *line, t_coords *c_data,
						t_get_data *helper)
{
	if ((helper->elems = ft_strsplit(line, ' ')) == NULL)
		return (-1);
	if (!helper->nb_elems)
		while (helper->elems[++helper->nb_elems])
			;
	app->params->x_max = helper->nb_elems;
	if (!(app->data->data_elem = init_tab(app->data->data_elem, helper->line,
		helper->nb_elems + 1)))
		return (-1);
	while (helper->elems[helper->j])
	{
		helper->i = 0;
		if (get_z(app, helper->elems[helper->j], helper, c_data) == -1)
			return (-1);
		ELEMS_LINES_INDEX.x = c_data->x;
		ELEMS_LINES_INDEX.y = c_data->y;
		ELEMS_LINES_INDEX.z = c_data->z;
		ELEMS_LINES_INDEX.color = c_data->color;
		helper->index++;
		helper->j++;
	}
	if (app->params->check_elements == 0)
		app->params->check_elements = app->params->x_max;
	return (0);
}

static void	init_helper_and_x_max(t_get_data *helper, size_t *x_max)
{
	helper->elems = NULL;
	helper->i = 0;
	helper->j = 0;
	helper->nb_elems = 0;
	helper->index = 0;
	*x_max = 0;
}

int			get_data(t_app *app, const char *line, t_coords *c_data,
						t_data *data)
{
	t_coords	*new_data;

	if (!(new_data = init_coords(c_data->y)))
		return (-1);
	init_helper_and_x_max(&data->helper, &app->params->x_max);
	if (ft_strlen(line) == 0)
		print_error(app->err, 1);
	if ((parse_data(app, line, new_data, &data->helper)) == -1)
	{
		while (data->helper.nb_elems--)
			ft_strdel(&data->helper.elems[data->helper.nb_elems]);
		free_data(app->data->data_elem);
		return (-1);
	}
	return ((app->params->check_elements != app->params->x_max) ? -1 : 0);
}
