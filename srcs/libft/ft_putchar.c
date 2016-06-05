/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 17:01:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/27 18:50:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Affiche le caractère c sur la sortie standard.
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}
