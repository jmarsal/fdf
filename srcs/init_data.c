/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/14 13:49:59 by jmarsal          ###   ########.fr       */
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

t_coords	*init_coords(int x, int y, int z, int color)
{
	t_coords	coords;

	if ((coords = (t_coords)malloc(sizeof(t_coords))) == NULL)
		return (NULL);
	coords.x = x;
	coords.y = y;
	coords.z = z;
	if (color == 0)
		coords->color = 0xFFFFFF;
	else
		coords->color = color;
	// coords->next = NULL;
	return (coords);
}

t_data		*init_data(t_coords *lst_lines)
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->data_elem = NULL;
	// data->data_val = lst_lines;
	// data->next = NULL;
	return (data);
}
