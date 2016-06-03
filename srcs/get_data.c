/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 10:23:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Va me servire a recuperer le nombre de points par ligne,
** ainsi que le z pour la hauteur;
*/

int		get_data(t_app *app, const char *line)
{
	int		i;
	int		x;
	int		y;
	int		len;
	char	*number;

	i = 0;
	x = 0;
	y = 0;
	len = 0;
	number = NULL;
	app->data->data_val = NULL;
	while (line[i])
	{
		if (ft_isdigit(line[0]))
		{
			while (ft_isdigit(line[++len]) && line[len])
				;
			if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
				return (-1);
			len = 0;
			while (ft_isdigit(line[i]) && line[i])
				number[len++] = line[i++];
			number[len] = '\0';
			coords_add_end(&app->data->data_val, init_coords(x, y, ft_atoi(number)));
			x++;
		}
		i++;
	}
	y++;
	printf("%s\n", line);
	(void)app;
	(void)line;
	return (0);
}
