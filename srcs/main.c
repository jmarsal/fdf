/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/31 16:21:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		read_file(char **av, t_app *app)
{
	size_t	i;
	int		fd;
	int		len;
	int		len_test;
	char	*line;
	char	*tmp;

	(void)app;
	i = 0;
	len = 0;
	len_test = 0;
	line = NULL;
	tmp = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((ft_get_next_line(fd, &line)) > 0)
	{
		if (tmp)
		{
			len_test = ft_strlen(line);
			if (len != len_test)
				return (-1);
			tmp = ft_strjoin(tmp, line);
		}
		else
		{
			len = ft_strlen(line);
			tmp = line;
		}
		i++;
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_app		*app;

	if (ac == 2)
	{
		if ((app = init_app()) == NULL)
		{
			ft_putstr("\033[31mERROR\033[0m\n--> Can't create app !\n");
			exit (-1);
		}
		if (read_file(av, app) == -1)
		{
			ft_putstr("\033[31mERROR\033[0m\n--> Can't read file !\n");
			exit (-1);
		}
		mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
		mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
		draw_windows(app);
		mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win, app->img->img_ptr, 0, 0);
		mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
		mlx_loop(app->mlx->mlx_ptr);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf exemple.fdf\n");
	return (0);
}
