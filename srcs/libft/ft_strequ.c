/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:40:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:32:39 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare lexicographiquement s1 et s2. Si les deux chaines sont égales,
**	la fonction retourne 1, ou 0 sinon.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int	test;

	if (s1 && s2)
	{
		test = ft_strcmp(s1, s2);
		if (test == 0)
			return (1);
	}
	return (0);
}
