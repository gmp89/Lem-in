/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:13:20 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/18 21:45:45 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>		/* careful printf */
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
}

void		ft_print_list(t_data *d)
{
	t_room	*tmp;

	tmp = d->first;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		ft_print_link(t_data *d)
{
	t_room	*tmp;
	t_link	*tmp2;

	tmp = d->first;
	while (tmp)
	{
		tmp2 = tmp->link;
		while (tmp2)
		{
			printf("%s-%s\n", tmp->name, tmp2->room->name);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int			main(void)
{
	t_data	d;

	ft_init_struct(&d);
	ft_get_data(&d);
	ft_print_list(&d);
	ft_print_link(&d);
	return (0);
}
