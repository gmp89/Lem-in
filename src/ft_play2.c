/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:42:03 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 23:17:51 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_guide_lemin(t_data *d)
{
	t_lem	*tmp;

	tmp = d->lemin;
	while (tmp)
	{
		tmp->path = d->path;
		tmp = tmp->next;
	}
}

t_lem	*ft_add_lem(t_data *d, int name)
{
	t_lem	*new;
	t_lem	*tmp;

	new = (t_lem *)malloc(sizeof(t_lem));
	new->name = ft_itoa(name);
	new->room = d->start;
	new->prev = d->start;
	new->tmp_prev = d->start;
	tmp = d->lemin;
	if (d->lemin == NULL)
	{
		new->next = NULL;
		new->prev = d->start;
		return (new);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->prev = d->start;
	return (d->lemin);
}

void	ft_create_lemins(t_data *d)
{
	int		i;

	i = 1;
	d->lemin = NULL;
	while (i <= d->lem_number)
	{
		d->lemin = ft_add_lem(d, i);
		i++;
	}
}
