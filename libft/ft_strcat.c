/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:32:13 by jmarsal           #+#    #+#             */
/*   Updated: 2015/12/19 09:14:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char		*t_dest;
	const char	*t_src;

	t_dest = dest;
	t_src = src;
	while (*t_dest)
		t_dest++;
	while (*t_src)
	{
		*t_dest = *t_src;
		t_dest++;
		t_src++;
	}
	*t_dest = '\0';
	return (dest);
}
