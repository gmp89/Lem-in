/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:46:58 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/18 21:45:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_start_data(t_data *d, char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (!ft_isdigit((int)tab[1][0]) || !ft_isdigit((int)tab[2][0]))
		ft_error_stdin();
	d->start->name = ft_strdup(tab[0]);
	d->start->x = ft_atoi(tab[1]);
	d->start->y = ft_atoi(tab[2]);
	d->start->is_start = 1;
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
	if (!ft_isdigit((int)tab[1][0]) || !ft_isdigit((int)tab[2][0]))
		ft_error_stdin();
	d->end->name = ft_strdup(tab[0]);
	d->end->x = ft_atoi(tab[1]);
	d->end->y = ft_atoi(tab[2]);
	d->end->is_end = 1;
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

	if (d->first == NULL)
	{
		d->first = (t_room *)malloc(sizeof(t_room));
		d->first->link = (t_link *)malloc(sizeof(t_room));
		d->first->link->next = NULL;
		d->first->link->room = NULL;
		return (d->first);
	}
	tmp = d->first;
	new = (t_room *)malloc(sizeof(t_room));
	new->link = (t_link *)malloc(sizeof(t_room));
	new->link->next = NULL;
	new->link->room = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

int		ft_is_room(t_data *d, char *line)
{
	char	**tab;
	t_room	*room;

	tab = ft_strsplit(line, ' ');
	if (!ft_isdigit((int)tab[1][0]) || !ft_isdigit((int)tab[2][0]))
		ft_error_stdin();
	room = ft_add_new_room(d);
	room->name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	room->is_start = 0;
	room->is_end = 0;
	return (0);
}

int		ft_is_link(char *line)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (line[i] != 0)
	{
		if (line[i] == '-')
			counter++;
		i++;
	}
	if (counter != 1)
		return (-1);
	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '-' && line[i - 1] && line[i + 1])
			return (0);
		i++;
	}
	return (-1);
}

void	ft_link_them(t_room **r1, t_room **r2)
{
	t_link	*tmp;
	t_link	*new;
	t_link	*new2;

	tmp = (*(r1))->link;
	new = (t_link *)malloc(sizeof(t_link));
	new2 = (t_link *)malloc(sizeof(t_link));
	if (tmp->next == NULL)
		tmp->room = *r2;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->room = *r2;
		new->next = NULL;
	}
	tmp = (*(r2))->link;
	if (tmp->next == NULL)
		tmp->room = *r1;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new2;
		new2->room = *r1;
		new2->next = NULL;
	}
}

void	ft_add_link(t_data *d, char *line)
{
	char	**tab;
	t_room	*tmp;
	t_room	*tmp2;

	tab = ft_strsplit(line, '-');
	tmp = d->first;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, tab[0]) == 0)
		{
			tmp2 = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = d->first;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, tab[1]) == 0)
		{
			ft_link_them(&tmp2, &tmp);
			break ;
		}
		tmp = tmp->next;
	}
	free(tab);
}

void	ft_get_data(t_data *d)
{
	char	*line;
	int		fd;

	fd = 0;
	get_next_line(fd, &line);
	d->lem_number = ft_atoi(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			get_next_line(fd, &line);
			ft_start_data(d, line);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			get_next_line(fd, &line);
			ft_end_data(d, line);
		}
		else if (ft_is_link(line) == 0)
			ft_add_link(d, line);
		else if (ft_is_room(d, line) == 0)
			;
	}
}
