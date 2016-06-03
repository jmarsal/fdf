/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:59:39 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 08:55:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_color(const char *line, int *i, t_coords *get_c)
{
	char	*tmp_color;
	int		len;
	int		j;
	int 	ret;

	len = 0;
	j = 0;
	ret = 0;
	while (!(ft_isspace(line[len++])) && line[len])
		;
	if ((tmp_color = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (-1);
	while (!(ft_isspace(line[*i])) && line[*i])
		tmp_color[j++] = line[*(i++)];
	tmp_color[j] = '\0';
	get_c->color = ft_atoi_base(tmp_color, "0123456789abcdef");
	return (ret);
}

static int	get_coords_and_color(const char *line, int *i, t_coords *get_c)
{
	char	*tmp_z;
	int		len;
	int		j;
	int		ret;

	len = 0;
	j = 0;
	ret = 0;
	while (ft_isdigit(line[len++]) && line[len])
		;
	if ((tmp_z = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (-1);
	while (ft_isdigit(line[*i]) && line[*i])
		tmp_z[j++] = line[*(i++)];
	tmp_z[j] = '\0';
	get_c->z = ft_atoi(tmp_z);
	if (line[*i] == ',')
	{
		*i += 1;
		ret = get_color(line, i, get_c);
	}
	get_c->x++;
	return (ret);
}

/*
** Va me servire a recuperer le nombre de points par ligne,
** ainsi que le z pour la hauteur;
*/

int			get_data(t_app *app, const char *line)
{
	//t_coords	*get_c;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!ft_isdigit(line[0]))
		return (-1);
	//get_c = NULL;
	while (line[i] && ret != -1)
	{
		//get_c = init_coords();
		while (ft_isspace(line[i]))
			i++;
		//ret = get_coords_and_color(line, &i, get_c);
		//lst_coords_push_end(&app->data->data_val, get_c);
		i++;
	}
	if (ret == -1)
		return (-1);
	//get_c->y++;
	(void)app;
	return (0);
}
