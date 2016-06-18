/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/19 00:00:49 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coords		**init_tab(t_coords **tab, size_t line, size_t nb_elems)
{
	if (!(tab[line] = ft_memalloc(sizeof(t_coords) * nb_elems + 1)))
		return (NULL);
	return (tab);
}

t_coords	*init_coords(int x, int y, int z, int color)
{
	t_coords	*coords;

	if (!(coords = ft_memalloc(sizeof(coords))))
		return (NULL);
	coords->x = x;
	coords->y = y;
	coords->z = z;
	coords->color = color;
	return (coords);
}

t_data		*init_data()
{
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->data_elem = NULL;
	data->oldsize = 16;
	data->newsize = data->oldsize * 2;
	data->is_colors = 0;
	data->helper.line = 0;
	return (data);
}
