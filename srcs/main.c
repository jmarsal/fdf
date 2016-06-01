/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/01 16:13:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		read_file(char **av, t_app *app)
{
	char	*line;
	int		tmp;
	int		i;

	line = NULL;
	tmp = 0;
	i = 0;
	if (error_read(app, av[1]) == -1)
		return (-1);
	while ((ft_get_next_line(app->fd, &line)) > 0)
	{
		app->len = ft_strlen(line);
		if (tmp == 0)
			tmp = app->len;
		if (tmp == app->len && line)
			app->data->data[i] = line;
		else
			return (print_error(app, 2));
		i++;
	}
	if (close(app->fd) == -1)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_app		*app;

	if (ac == 2)
	{
		if ((app = init_app(av)) == NULL)
		{
			ft_putstr("\033[31mERROR\033[0m\n--> Can't create app !\n");
			exit (-1);
		}
		if (read_file(av, app) == -1)
			exit (-1);
		mlx_key_hook(app->mlx->mlx_win, key_hook, &app->mlx);
		mlx_mouse_hook(app->mlx->mlx_win, mouse_hook, &app->mlx);
		draw_windows(app);
		mlx_put_image_to_window(app->mlx->mlx_ptr, app->mlx->mlx_win, app->img->img_ptr, 0, 0);
		mlx_hook(app->mlx->mlx_win, 17, 1L << 17, close_win, &app->mlx);
		mlx_loop(app->mlx->mlx_ptr);
	}
	else
		ft_putstr("\n\033[31mERROR\033[0m\n--> usage : ./fdf template.fdf\n");
	return (0);
}
