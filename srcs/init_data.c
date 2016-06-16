/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/16 22:31:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*init_number_z(const char *line, size_t *i, size_t sign)
{
	size_t	len;
	char	*number;

	len = 0;
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		++len;
	len = (sign) ? len += 1 : len;
	if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	return (number);
}

t_coords		**init_tab(t_coords **tab, size_t line, size_t nb_elems)
{
	if (!(tab[line] = ft_memalloc(sizeof(t_coords) * nb_elems + 1)))
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
	coords->color = color;
	return (coords);
}

t_data		*init_data()
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->data_elem = NULL;
	data->oldsize = 8;
	data->newsize = data->oldsize * 2;
	data->is_colors = 0;
	data->helper.line = 0;
	return (data);
}
