/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 23:12:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/02 10:52:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 		init_perror(t_error *err)
{
	err->p_err[0] = "\n\033[31mERROR\033[0m\n--> Can't read file !\n";
	err->p_err[1] = "\n\033[31mERROR\033[0m\n--> Empty file !\n";
	err->p_err[2] = "\n\033[31mERROR\033[0m\n--> Invalid file !\n";
	err->p_err[3] = "\n\033[31mERROR\033[0m\n--> Can't create image.\n";
	err->p_err[4] = "\n\033[31mERROR\033[0m\n--> File isn't a fdf map !\n";
}

int			print_error(t_app *app, int witch_one)
{
	ft_putstr(app->err.p_err[witch_one]);
	return (-1);
}

int			error_read(t_app *app, char *av)
{
	char	*line;

	line = NULL;
	if (!(ft_strstr(av, ".fdf")))
		return (print_error(app, 5));
	if (app->fd < 0)
		return (print_error(app, 0));
	return (0);
}
