/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:59:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/08 15:17:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*init_number_z(const char *line, size_t *i)
{
	size_t	len;
	char	*number;

	len = 0;
	while (ft_isdigit(line[*i + len]) && line[*i + len])
		++len;
	if ((number = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	return (number);
}
