/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:02:50 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/24 00:07:58 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_make_path(t_data *d, t_room *room)
{
	t_path	*new;
	t_path	*tmp;

	new = (t_path *)malloc(sizeof(t_path));
	new->room = room;
	new->next = NULL;
	if (d->path == NULL)
	{
		d->path = new;
		return ;
	}
	tmp = d->path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_delete_path(t_data *d, t_room *room)
{
	t_path	*tmp;

	tmp = d->path;
	while (tmp->next && tmp->room != room)
		tmp = tmp->next;
	tmp = NULL;
}
