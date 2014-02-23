/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 17:40:36 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/22 20:18:57 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	ft_link_them_help(t_link **tmp, t_link **new, t_room **r2)
{
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = *new;
	(*new)->room = *r2;
	(*new)->next = NULL;
}

void	ft_link_them(t_room **r1, t_room **r2)
{
	t_link	*tmp;
	t_link	*new;
	t_link	*new2;

	tmp = (*(r1))->link;
	new = (t_link *)malloc(sizeof(t_link));
	new2 = (t_link *)malloc(sizeof(t_link));
	if (tmp->room == NULL)
		tmp->room = *r2;
	else
		ft_link_them_help(&tmp, &new, r2);
	tmp = (*(r2))->link;
	if (tmp->room == NULL)
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

void	ft_add_link_help(t_room **tmp, t_room **tmp2, char **tab)
{
	while (*tmp)
	{
		if (ft_strcmp((*tmp)->name, tab[0]) == 0)
		{
			*tmp2 = *tmp;
			break ;
		}
		*tmp = (*tmp)->next;
	}
}

void	ft_add_link(t_data *d, char *line)
{
	char	**tab;
	t_room	*tmp;
	t_room	*tmp2;

	tab = ft_strsplit(line, '-');
	tmp = d->first;
	ft_add_link_help(&tmp, &tmp2, tab);
	tmp = d->first;
	d->link_done = 1;
	while (tmp)
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
