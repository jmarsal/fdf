/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/07 14:12:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_color(const char *line, size_t *i)
{
	int		len;
	int		color;
	char	*number;

	*i += 3;
	// printf("line[i] = %c\n", line[*i]);
	len = 0;
	while (!ft_isspace(line[*i + len]) && line[*i + len])
		++len;
	// printf("len = %d\n", len);
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
	//printf("0x%06.6X\n", color);
	free(number);
	return (color);
}
static char	*init_number_z(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	// printf("line[*i] = %c && *i = %lu\n", line[*i], *i);
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		++len;
	// printf("len_z = %lu\n", len);
	if ((number = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	return (number);
}

static char	*get_number(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	// printf("line[0] dans get_z = %c\n", line[0]);
	if ((number = init_number_z(line, i)) == NULL)
		return (NULL);
	// printf("line[i] dans get_z = %c\n", line[*i]);
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		{
			number[len] = line[*i + len];
			len++;
			// *i += 1;
		}
	number[len] = '\0';
	// printf("number_z = %s\n", number);
	return (number);
}

static int	get_z(t_app *app, const char *line, size_t *i, t_coords *c_data)
{
	char	*number;

	// printf("line[i] dans get_z = %c\n", line[*i]);
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
	c_data->x += PIX_SPACE;
	app->data->x_max++;
	free(number);
	return (0);
}

int		get_data(t_app *app, const char *line, t_coords *c_data)
{
	char	**g_data;
	size_t	i;
	size_t  j;

	i = 0;
	j = 0;
	if ((g_data = (char**)malloc(sizeof(char *) * ft_strlen(line))) == NULL)
	{
		printf("Prob malloc g_data\n");
		return (-1);
	}
	c_data->x = 0;
	if (line[0] == ' ')
		while (!(ft_isspace(line[i++])) && line[i])
	if (!ft_isdigit(line[i]))
	{
		printf("line[0] n'est pas un nombre\n");
		return (-1);
	}
	g_data = ft_strsplit(line, ' ');
	while (g_data[j])
	{
		i = 0;
		if (get_z(app, g_data[j], &i, c_data) == -1)
		{
			printf("prob avec get_z\n");
			return (-1);
		}
		j++;
	}
	if (app->data->check_elements == 0)
		app->data->check_elements = app->data->x_max;
	if (app->data->check_elements != app->data->x_max)
	{
		printf("ligne actuel differente de precedente\n");
		return (-1);
	}
	return (0);
}
