/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:59:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/31 12:33:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("button : %d, pos : (%d,%d)\n", button, x, y);
	return (0);
}

int		close_win(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}
