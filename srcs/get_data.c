/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/15 14:35:18 by jmarsal          ###   ########.fr       */
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

static int	get_z(t_app *app, const char *line, t_get_data *h,
					t_coords *c_data, t_coords **tab)
{
	char	*number;
	int		z;
	int		color;

	color = 0;
	if ((number = get_number(line, &h->i)) == NULL)
		return (-1);
	z = ft_atoi(number);
	c_data->z = z;
	// printf("z = %d\n", z);
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
	// printf("line = %lu, elem = %lu\n", h->line, h->elem);
	tab[h->line][h->elem].x = c_data->x;
	tab[h->line][h->elem].y = c_data->y;
	tab[h->line][h->elem].z = c_data->z;
	tab[h->line][h->elem].color = color;
	// printf("x = %d, y = %d, z = %d, color = 0x0%6.6X\n",
	// tab[h->line][h->elem].x,
	// tab[h->line][h->elem].y,
	// tab[h->line][h->elem].z,
	// tab[h->line][h->elem].color);
	h->elem++;
	c_data->x += app->win->space_pix;
	app->params->x_max++;
	free(number);
	return (0);
}

static int	parse_data(t_app *app, const char *line, t_coords *c_data,
						t_get_data *helper, t_coords **tab)
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
		if (get_z(app, helper->elems[helper->j], helper, c_data, tab) == -1)
				return (-1);
		helper->j++;
	}
	if (app->params->check_elements == 0)
		app->params->check_elements = app->params->x_max;
	return (0);
}

int			get_data(t_app *app, const char *line, t_coords *c_data,
						t_data *data, t_coords **tab)
{
	if ((c_data = init_coords(0, c_data->y, c_data->z, c_data->color)) == NULL)
		return (-1);
	if (!(data->helper.elems = (char**)malloc(sizeof(char *) * ft_strlen(line))))
		return (-1);
	data->helper.i = 0;
	data->helper.j = 0;
	data->helper.nb_elems = 0;
	data->helper.elem = 0;
	if ((parse_data(app, line, c_data, &data->helper, tab)) == -1)
		return (-1);
	return ((app->params->check_elements != app->params->x_max) ? -1 : 0);
}
