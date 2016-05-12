/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:21:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/03 21:57:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	print_hex(unsigned char *chars, size_t new_size)
{
	char	*charset;
	size_t	i;

	i = 0;
	charset = "0123456789abcdef";
	while (new_size--)
	{
		ft_putchar(charset[chars[i] / 16]);
		ft_putchar(charset[chars[i] % 16]);
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
	}
	return (i);
}

static void		print_padding(size_t padding)
{
	unsigned char p;

	p = 40 - (padding * 2 + padding / 2);
	while (p--)
		ft_putchar(' ');
}

static void		print_ascii(unsigned char *chars, size_t new_size)
{
	size_t	i;

	i = 0;
	while (new_size--)
	{
		if (ft_isprint(chars[i]))
			ft_putchar(chars[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void			ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*chars;
	size_t			padding;
	size_t			new_size;

	chars = (unsigned char*)addr;
	while (size)
	{
		new_size = (size > 16) ? 16 : size;
		padding = print_hex(chars, new_size);
		print_padding(padding);
		print_ascii(chars, new_size);
		size -= new_size;
		chars += new_size;
	}
}
