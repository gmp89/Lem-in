/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:46:58 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 22:48:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_start_data(t_data *d, char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	ft_check_start(tab);
	d->start->name = ft_strdup(tab[0]);
	d->start->x = ft_atoi(tab[1]);
	d->start->y = ft_atoi(tab[2]);
	d->start->is_start = 1;
	d->start->lem_number = d->lem_number;
	d->start->on = 1;
	d->start_done = 1;
	if (d->first == NULL)
		d->first = d->start;
	else
	{
		d->start->next = d->first;
		d->first = d->start;
	}
	free(tab);
}

void	ft_end_data(t_data *d, char *line)
{
	char	**tab;
	t_room	*tmp;

	tab = ft_strsplit(line, ' ');
	ft_check_start(tab);
	d->end->name = ft_strdup(tab[0]);
	d->end->x = ft_atoi(tab[1]);
	d->end->y = ft_atoi(tab[2]);
	d->end->is_end = 1;
	d->end->lem_number = 0;
	d->end->on = 0;
	d->end_done = 1;
	if (d->first == NULL)
		d->first = d->end;
	else
	{
		tmp = d->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = d->end;
	}
	free(tab);
}

t_room	*ft_add_new_room(t_data *d)
{
	t_room	*new;
	t_room	*tmp;

	d->room_done = 1;
	if (d->first == NULL)
	{
		d->first = (t_room *)malloc(sizeof(t_room));
		d->first->link = (t_link *)malloc(sizeof(t_link));
		d->first->link->next = NULL;
		d->first->link->room = NULL;
		d->first->next = NULL;
		d->first->lem_number = 0;
		return (d->first);
	}
	tmp = d->first;
	new = (t_room *)malloc(sizeof(t_room));
	new->link = (t_link *)malloc(sizeof(t_link));
	new->link->next = NULL;
	new->link->room = NULL;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->lem_number = 0;
	return (new);
}

int		ft_is_room(t_data *d, char *line)
{
	char	**tab;
	t_room	*room;

	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	tab = ft_strsplit(line, ' ');
	ft_check_start(tab);
	room = ft_add_new_room(d);
	room->name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	room->is_start = 0;
	room->is_end = 0;
	room->on = 0;
	return (0);
}

void	ft_get_data(t_data *d)
{
	char	*line;
	int		fd;

	fd = 0;
	get_next_line(fd, &line);
	ft_check_first_line(line);
	d->lem_number = ft_atoi(line);
	ft_make_print(d, line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_make_print(d, line);
		if (ft_strcmp(line, "##start") == 0)
			ft_get_data_help(fd, line, d);
		else if (ft_strcmp(line, "##end") == 0)
			ft_get_data_help2(fd, line, d);
		else if (ft_strcmp(line, "##start") != 0 &&
		ft_strcmp(line, "##end") && line[0] == '#')
			continue ;
		else if (ft_strcmp(line, "\0") == 0)
			break ;
		else if (ft_is_link(line) == 0)
			ft_add_link(d, line);
		else if (ft_is_room(d, line) == 0)
			;
	}
}
