/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:25:10 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/27 16:29:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_filename(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*ret;
	char	*tmp;

	len = 0;
	i = 0;
	tmp = (char *)s;
	tmp = ft_strrchr(s, '/');
	while (tmp[++len] != (char)c)
		;
	if ((ret = ft_memalloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (tmp[i] && i < len - 1)
	{
		ret[i] = tmp[i + 1];
		i++;
	}
	ret[++i] = '\0';
	return (ret);
}

static void	check_name(const char *filename, t_win *win)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strrchr(filename, '/');
	if (tmp != NULL)
		win->filename = ft_strtoupper(get_filename(filename, '.'));
	else
		win->filename = ft_strtoupper(ft_strchr_bef(filename, '.'));
}

static void	get_size(const char *filename, t_win *win, int witch_file)
{
	check_name(filename, win);
	win->zoom = win->size->tab_of_size_zoom[witch_file];
}

static int	read_name_for_size_win2(const char *av, t_win *win)
{
	if (ft_strstr(av, "pylone.fdf"))
		get_size(av, win, 11);
	else if (ft_strstr(av, "pnp_flat.fdf"))
		get_size(av, win, 12);
	else if (ft_strstr(av, "plat.fdf"))
		get_size(av, win, 13);
	else if (ft_strstr(av, "pentenegpos.fdf"))
		get_size(av, win, 14);
	else if (ft_strstr(av, "basictest.fdf"))
		get_size(av, win, 15);
	else if (ft_strstr(av, "100-6.fdf"))
		get_size(av, win, 16);
	else if (ft_strstr(av, "50-4.fdf"))
		get_size(av, win, 17);
	else if (ft_strstr(av, "20-60.fdf"))
		get_size(av, win, 18);
	else if (ft_strstr(av, "10-70.fdf"))
		get_size(av, win, 19);
	else if (ft_strstr(av, "10-2.fdf"))
		get_size(av, win, 20);
	else if (ft_strstr(av, "IGN_France_250_ASC_L93_OCEAN0_M.fdf"))
		get_size(av, win, 21);
	else
		get_size(av, win, 5);
	return (0);
}

int			read_name_for_size_win(const char *av, t_win *win)
{
	if (ft_strstr(av, "42.fdf"))
		get_size(av, win, 0);
	else if (ft_strstr(av, "elem-col.fdf"))
		get_size(av, win, 1);
	else if (ft_strstr(av, "elem-fract.fdf"))
		get_size(av, win, 2);
	else if (ft_strstr(av, "elem.fdf"))
		get_size(av, win, 3);
	else if (ft_strstr(av, "elem2.fdf"))
		get_size(av, win, 4);
	else if (ft_strstr(av, "julia.fdf"))
		get_size(av, win, 5);
	else if (ft_strstr(av, "mars.fdf"))
		get_size(av, win, 6);
	else if (ft_strstr(av, "t1.fdf"))
		get_size(av, win, 7);
	else if (ft_strstr(av, "t2.fdf"))
		get_size(av, win, 8);
	else if (ft_strstr(av, "pyramide.fdf"))
		get_size(av, win, 9);
	else if (ft_strstr(av, "pyra.fdf"))
		get_size(av, win, 10);
	else
		read_name_for_size_win2(av, win);
	return (0);
}
