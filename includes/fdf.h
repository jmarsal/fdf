/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:32:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/09 16:01:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct		s_coords
{
	int				x;
	int				y;
	struct s_cords	*next;
}					t_coords;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

#endif
