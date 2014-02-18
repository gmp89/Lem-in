/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:14:37 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/18 19:50:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

/*
**	Struct
*/

typedef struct		s_link
{
	struct s_link	*next;
	struct s_room	*room;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
	int				lem_number;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				lem_number;
	int				start_ok;
	int				end_ok;
	t_room			*start;
	t_room			*end;
	t_room			*first;
}					t_data;

/*
**	Prototypes
*/

/*
**	Data
*/

void	ft_get_data(t_data *d);
void	ft_start_data(t_data *d, char *line);
void	ft_end_data(t_data *d, char *line);
int		ft_is_room(t_data *d, char *line);
t_room	*ft_add_new_room(t_data *d);
int		ft_is_link(char *line);

/*
**	Error
*/

void	ft_error_stdin(void);

#endif
