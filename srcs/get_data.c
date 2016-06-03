/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 13:59:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_color(t_app *app, const char *line, size_t *i, t_coords *c_data)
{
	size_t	len;
	char	*number;

	*i += 1;
	len = *i;
	number = NULL;
	while (ft_isspace(line[len++]) && line[len])
		;
	if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (-1);
	len = 0;
	while (!ft_isspace(line[*i]))
		number[len++] = line[*i += 1];
	number[len++] = '\0';
	printf("color = %s\n", number);
	(void)app, (void)c_data;
	return (0);
}

static int	get_z(t_app *app, const char *line, size_t *i, t_coords *c_data)
{
	size_t	len;
	char	*number;

	len = 0;
	number = NULL;
	while (ft_isdigit(line[len++]) && line[len])
		;
	if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (-1);
	len = 0;
	while (ft_isdigit(line[*i]) && line[*i])
		number[len++] = line[*i += 1];
	number[len++] = '\0';
	coords_add_end(&app->data->data_val,
		init_coords(c_data->x, c_data->y, ft_atoi(number)));
	c_data->x++;
	return (0);
}

int		get_data(t_app *app, const char *line, t_coords *c_data)
{
	size_t			i;

	i = 0;
	c_data->x = 0;
	if (!ft_isdigit(line[0]))
		return (-1);
	while (line[i])
	{
		while (ft_isspace(line[i++]));
		if (get_z(app, line, &i, c_data) == -1)
			return (-1);
		if (line[i] == ',')
		{
			if (get_color(app, line, &i, c_data) == -1)
				return (-1);
		}
		i++;
	}
	printf("%s\n", line);
	return (0);
}
