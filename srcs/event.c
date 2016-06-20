/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:59:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/21 00:02:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// if (keycode == 69) // +
// if (keycode == 78) // -

/*int		key_hook(int keycode)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}*/

int		mouse_hook(int button, int x, int y)
{
	printf("button : %d, pos : (%d,%d)\n", button, x, y);
	return (0);
}
