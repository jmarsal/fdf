/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/17 13:10:53 by jmarsal          ###   ########.fr       */
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
	if (!(number = ft_memalloc(sizeof(char) * (len + 1))))
		return (-1);
	len = 0;
	while (line[*i + len] != ' ' && line[*i + len])
	{
		number[len] = line[*i + len];
		len++;
	}
	number[len] = '\0';
	color = ft_atoi_base(number, 16);
	if (color == 0)
		color = 0xFFFFFF;
	free(number);
	return (color);
}

static char	*get_number(const char *line, size_t *i)
{
	size_t	len;
	size_t	sign;
	size_t	index;
	char	*number;

	len = 0;
	sign = (line[*i] == '-') ? 1 : 0;
	index = 0;
	if ((number = init_number_z(line, i, sign)) == NULL)
		return (NULL);
	if (sign)
		number[index++] = '-';
	*i = (sign) ? *i += 1 : *i;
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		number[index++] = line[*i + len++];
	number[index] = '\0';
	*i += len;
	return (number);
}

static int	get_z(t_app *app, const char *line, t_get_data *h, t_coords *c_data)
{
	char	*number;
	int		z;
	int		color;

	color = 0xFFFFFF;
	if (!(number = get_number(line, &h->i)))
		return (-1);
	z = ft_atoi(number);
	c_data->z = z;
	if (line[h->i] && line[h->i] == ',')
	{
		if ((c_data->color = get_color(line, &h->i)) == -1)
		{
			free(number);
			return (-1);
		}
		color = c_data->color;
		app->data->is_colors = 1;
	}
	else
		c_data->color = color;
	c_data->x += app->win->space_pix;
	free(number);
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
