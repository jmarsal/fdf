/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 10:41:56 by jmarsal          ###   ########.fr       */
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
static char	*init_number_z(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		++len;
	if ((number = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	return (number);
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

int		get_data(t_app *app, const char *line, t_coords *c_data)
{
	char	**elems;
	size_t	nb_elems;
	size_t	i;
	size_t  j;

	i = 0;
	j = 0;
	nb_elems = 0;
	if ((elems = (char**)malloc(sizeof(char *) * ft_strlen(line))) == NULL)
		return (-1);
	c_data->x = 0;
	if (line[0] == ' ')
		while (!(ft_isspace(line[i++])) && line[i])
	if (!ft_isdigit(line[i]))
		return (-1);
	elems = ft_strsplit(line, ' ');
	if (!nb_elems)
	{
		while (elems[nb_elems++])
		;
		if (app->win->height)
			app->win->height = nb_elems;
		app->win->space_pix = (app->win->height / nb_elems);
	}
	while (elems[j])
	{
		i = 0;
		if (get_z(app, elems[j], &i, c_data) == -1)
			return (-1);
		j++;
	}
	if (app->data->check_elements == 0)
		app->data->check_elements = app->data->x_max;
	return ((app->data->check_elements != app->data->x_max) ? -1 : 0);
}
