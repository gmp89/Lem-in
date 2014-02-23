/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:14:37 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 23:35:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

/*
**	Struct
*/

typedef struct		s_print
{
	char			*str;
	struct s_print	*next;
}					t_print;

typedef struct		s_path
{
	struct s_path	*next;
	struct s_room	*room;
}					t_path;

typedef struct		s_link
{
	struct s_link	*next;
	struct s_room	*room;
}					t_link;

typedef struct		s_lem
{
	char			*name;
	struct s_lem	*next;
	struct s_room	*prev;
	struct s_room	*tmp_prev;
	struct s_room	*room;
	struct s_path	*path;
}					t_lem;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				on;
	int				is_start;
	int				is_end;
	int				lem_number;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				i;
	int				valid;
	int				start_done;
	int				end_done;
	int				room_done;
	int				link_done;
	int				lem_number;
	int				start_ok;
	int				end_ok;
	t_room			*start;
	t_room			*end;
	t_room			*first;
	t_lem			*lemin;
	t_lem			*scout;
	t_path			*path;
	t_print			*map_print;
}					t_data;

/*
**	Prototypes
*/

/*
**	Data
*/

void	ft_get_data(t_data *d);
void	ft_get_data_help(int fd, char *line, t_data *d);
void	ft_get_data_help2(int fd, char *line, t_data *d);
void	ft_start_data(t_data *d, char *line);
void	ft_end_data(t_data *d, char *line);
int		ft_is_room(t_data *d, char *line);
t_room	*ft_add_new_room(t_data *d);
int		ft_is_link(char *line);
void	ft_add_link(t_data *d, char *line);
void	ft_add_link_help(t_room **tmp, t_room **tmp2, char **tab);
void	ft_link_them(t_room **r1, t_room **r2);
void	ft_link_them_help(t_link **tmp, t_link **new, t_room **r2);

/*
**	Path Finding
*/

void	ft_create_lemins(t_data *d);
void	ft_find_path(t_data *d);
void	ft_find_path_help(t_link **tmp, t_data *d, char *find);
void	ft_find_path_help2(t_link **tmp, t_data *d, char *find);
t_lem	*ft_add_lem(t_data *d, int name);
void	ft_play(t_data *d);
void	ft_play_help(t_link **tmp_link, t_lem **tmp, t_data *d);
void	ft_make_path(t_data *d, t_room *room);
void	ft_delete_path(t_data *d, t_room *room);
void	ft_guide_lemin(t_data *d);
void	ft_print_list(t_data *d);
void	ft_make_print(t_data *d, char *line);
void	ft_print_map(t_data *d);

/*
**	Error
*/

void	ft_error_stdin(void);
void	ft_check_first_line(char *line);
void	ft_check_start(char **tab);

#endif
