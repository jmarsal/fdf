/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:17:33 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/25 11:45:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
**	If insufficient memory is available, NULL is returned and errno is set
**	to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	if ((new_str = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	return (ft_strcpy(new_str, s1));
}
