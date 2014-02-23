/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 18:31:13 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 23:33:14 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_find_path_help(t_link **tmp, t_data *d, char *find)
{
	while (*tmp)
	{
		if ((*tmp)->room && (*tmp)->room->on == 0)
		{
			d->scout->room->on = 1;
			ft_make_path(d, d->scout->room);
			d->scout->prev = d->scout->room;
			d->scout->room = (*tmp)->room;
			*find = 1;
			break ;
		}
		*tmp = (*tmp)->next;
	}
}

void	ft_find_path_help2(t_link **tmp, t_data *d, char *find)
{
	while (*tmp)
	{
		if ((*tmp)->room && (*tmp)->room->on == 1)
		{
			d->scout->room->on = -1;
			ft_delete_path(d, d->scout->room);
			d->scout->prev = d->scout->room;
			d->scout->room = (*tmp)->room;
			*find = 1;
			break ;
		}
		*tmp = (*tmp)->next;
	}
}

void	ft_find_path(t_data *d)
{
	t_link	*tmp;
	char	find;

	d->scout->room = d->start;
	d->scout->name = "scout";
	while (d->scout->room != d->end)
	{
		find = 0;
		tmp = d->scout->room->link;
		ft_find_path_help(&tmp, d, &find);
		if (find == 0)
		{
			tmp = d->scout->room->link;
			ft_find_path_help2(&tmp, d, &find);
		}
		if (find == 0)
			ft_error_stdin();
	}
	d->end->on = 1;
	ft_make_path(d, d->end);
}

void	ft_help_bis(t_lem **tmp, t_data *d)
{
	if (d->i == 1)
		ft_putchar(' ');
	d->i = 1;
	(*tmp)->room->lem_number -= 1;
	(*tmp)->room = (*tmp)->path->next->room;
	(*tmp)->path = (*tmp)->path->next;
	(*tmp)->room->lem_number += 1;
	ft_putstr("L");
	ft_putstr((*tmp)->name);
	ft_putstr("-");
	ft_putstr((*tmp)->room->name);
}

void	ft_play(t_data *d)
{
	t_lem	*tmp;

	d->i = 0;
	while (d->end->lem_number != d->lem_number)
	{
		tmp = d->lemin;
		while (tmp)
		{
			if (tmp->next && tmp->room == d->end)
				tmp = tmp->next;
			if ((tmp->path->next) && (tmp->path->next) &&
			((tmp->path->next->room->lem_number == 0) ||
			(tmp->path->next->room == d->end)))
				ft_help_bis(&tmp, d);
			tmp = tmp->next;
		}
		d->i = 0;
		ft_putchar('\n');
	}
}
