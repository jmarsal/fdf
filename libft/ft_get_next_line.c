/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:56:45 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/31 15:05:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl		*new_file(const int fd)
{
	t_gnl	*new_link;

	if (!(new_link = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new_link->fd = fd;
	new_link->line = ft_strnew(0);
	new_link->next = NULL;
	return (new_link);
}

char		*get_line(t_gnl *list, char **line)
{
	char	*swap;
	char	*complete_line;
	int		i;

	swap = NULL;
	i = 0;
	complete_line = list->line;
	while (complete_line[i])
	{
		if (complete_line[i] == EOL)
		{
			*line = ft_strsub(complete_line, 0, i);
			swap = complete_line;
			complete_line = ft_strdup(complete_line + (i + 1));
			free(swap);
			return (complete_line);
		}
		i++;
	}
	*line = ft_strdup(complete_line);
	ft_strclr(complete_line);
	ft_strclr(list->line);
	return (complete_line);
}

int			read_file_gnl(int fd, t_gnl *list)
{
	int		ret;
	char	buffer[GNL_BUFF_SIZE + 1];
	char	*swap;

	swap = NULL;
	while (!ft_strchr(list->line, EOL))
	{
		if ((ret = read(fd, buffer, GNL_BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buffer[ret] = 0;
			swap = list->line;
			if (!(list->line = ft_strjoin(list->line, buffer)))
				return (-1);
			free(swap);
		}
		if (ret < GNL_BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

int			ft_get_next_line(int const fd, char **line)
{
	static	t_gnl		*list_files;
	int					ret;
	t_gnl				*file_tmp;

	if (!list_files)
		list_files = new_file(fd);
	file_tmp = list_files;
	if (fd < 0 || !line)
		return (-1);
	while (file_tmp)
	{
		if (file_tmp->fd == fd)
			break ;
		if (file_tmp->next == NULL)
			ft_lstadd_end((t_list**)&file_tmp, (t_list*)new_file(fd));
		file_tmp = file_tmp->next;
	}
	if ((ret = read_file_gnl(fd, file_tmp)) == -1)
		return (-1);
	file_tmp->line = get_line(file_tmp, line);
	return ((!ft_strlen(file_tmp->line) && !ft_strlen(*line) && !ret) ? 0 : 1);
}
