/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 22:23:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	**init_tab(t_coords **tab, size_t line, size_t nb_elems)
{
	if (!(tab[line] = ft_memalloc(sizeof(t_coords) * nb_elems + 1)))
		return (NULL);
	return (tab);
}

t_coords	*init_coords(int y)
{
	t_coords	*coords;

	if (!(coords = ft_memalloc(sizeof(t_coords))))
		return (NULL);
	coords->x = 0;
	coords->y = y;
	coords->z = 0;
	coords->color = 0;
	return (coords);
}

t_data		*init_data(void)
{
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->data_elem = NULL;
	data->oldsize = 1024;
	data->is_colors = 0;
	data->helper.line = 0;
	data->helper.elems = NULL;
	data->helper.nb_elems = 0;
	data->helper.index = 0;
	data->helper.i = 0;
	data->helper.j = 0;
	return (data);
}

void		init_for_draw_line_or_column(t_coords *c_elems, t_coords *n_elems,
								t_affine *draw)
{
	draw->x = c_elems->x;
	draw->y = c_elems->y;
	draw->coef = 0;
	draw->cst = 0;
	n_elems->x = 0;
	n_elems->y = 0;
	n_elems->z = 0;
	n_elems->color = 0;
}
