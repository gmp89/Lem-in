/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:13:20 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 23:34:37 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_init_struct(t_data *d)
{
	d->start = (t_room *)malloc(sizeof(t_room));
	d->start->link = (t_link *)malloc(sizeof(t_link));
	d->start->next = NULL;
	d->start->link->next = NULL;
	d->start->link->room = NULL;
	d->end = (t_room *)malloc(sizeof(t_room));
	d->end->link = (t_link *)malloc(sizeof(t_link));
	d->end->link->next = NULL;
	d->end->link->room = NULL;
	d->first = NULL;
	d->scout = (t_lem *)malloc(sizeof(t_lem));
	d->path = (t_path *)malloc(sizeof(t_path));
	d->path = NULL;
	d->map_print = (t_print *)malloc(sizeof(t_print));
	d->map_print = NULL;
	d->start_done = 0;
	d->end_done = 0;
	d->room_done = 0;
	d->link_done = 0;
}

void		ft_print_list(t_data *d)
{
	t_lem	*tmp;

	tmp = d->lemin;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

int			main(void)
{
	t_data	d;

	ft_init_struct(&d);
	ft_get_data(&d);
	if (d.start_done == 0 || d.link_done == 0 ||
	d.start_done == 0 || d.end_done == 0)
		ft_error_stdin();
	ft_create_lemins(&d);
	ft_find_path(&d);
	ft_guide_lemin(&d);
	ft_print_map(&d);
	ft_play(&d);
	return (0);
}
