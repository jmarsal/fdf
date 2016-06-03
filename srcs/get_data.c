/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 12:03:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_z(t_app *app, const char *line, size_t *i, size_t y)
{
	size_t	x;
	size_t	len;
	char	*number;

	x = 0;
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
	coords_add_end(&app->data->data_val, init_coords(x, y, ft_atoi(number)));
	x++;
	(void)app, (void)y;
	return (0);
}

int		get_data(t_app *app, const char *line)
{
	size_t			i;
	static size_t	y;

	i = 0;
	y = 0;
	if (!ft_isdigit(line[0]))
		return (-1);
	while (line[i])
	{
		if (get_z(app, line, &i, y) == -1)
			return (-1);
		i++;
	}
	y++;
	printf("%s\n", line);
	return (0);
}
