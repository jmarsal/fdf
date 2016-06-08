/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 23:12:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 11:01:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void 		init_perror(t_error *err)
{
	err->p_err[0] = "\n\033[31mERROR\033[0m\n--> Can't read file !\n";
	err->p_err[1] = "\n\033[31mERROR\033[0m\n--> Empty file !\n";
	err->p_err[2] = "\n\033[31mERROR\033[0m\n--> Invalid file !\n";
	err->p_err[3] = "\n\033[31mERROR\033[0m\n--> Can't create image.\n";
	err->p_err[4] = "\n\033[31mERROR\033[0m\n--> File isn't a fdf map !\n";
	err->p_err[5] = "\033[31mERROR\033[0m\n--> Can't create app !\n";
}

int			print_error(t_app *app, const int witch_one)
{
	init_perror(&app->err);
	ft_putstr(app->err.p_err[witch_one]);
	return (-1);
}
