/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/15 16:17:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*init_number_z(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		++len;
	if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	return (number);
}

t_coords		**init_tab(t_coords **tab, size_t line, size_t nb_elems)
{
	size_t		x;

	x = nb_elems;
	if ((tab[line] = (t_coords*)malloc(sizeof(t_coords) * x + 1)) == NULL)
		return (NULL);
	return (tab);
}

t_coords	*init_coords(int x, int y, int z, int color)
{
	t_coords	*coords;

	if ((coords = (t_coords*)malloc(sizeof(t_coords))) == NULL)
		return (NULL);
	coords->x = x;
	coords->y = y;
	coords->z = z;
	if (color == 0)
		coords->color = 0xFFFFFF;
	else
		coords->color = color;
	return (coords);
}

t_data		*init_data()
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if (!(data->data_elem = (t_coords**)malloc(sizeof(t_coords*) * 8)))
		return (NULL);
	data->oldsize = 4;
	data->newsize = data->oldsize * 2;
	return (data);
}
