/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:34:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/08 00:16:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strchr() function locates the first occurrence of c (converted to
**	a char) in the string pointed to by s.  The terminating null character is
**	considered to be part of the string; therefore if c is `\0', the functions
**	locate the terminating `\0'.
*/

char	*ft_strchr(const char *s, int c)
{
	char	cpy_c;

	cpy_c = (char)c;
	if (s)
	{
		while (*s != cpy_c && *s != '\0')
			s++;
		if (*s == cpy_c)
			return ((char*)s);
	}
	return (NULL);
}
