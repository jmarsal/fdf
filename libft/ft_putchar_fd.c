/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 10:37:01 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:47:42 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	Ecrit le caractère c sur le descripteur de fichier fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
