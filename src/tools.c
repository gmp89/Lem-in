/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 16:20:09 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 21:12:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error_stdin(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	ft_check_first_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i]))
			i++;
		else
			ft_error_stdin();
	}
}

void	ft_check_start(char **tab)
{
	if (!tab[1] && !tab[2])
		ft_error_stdin();
	ft_check_first_line(tab[1]);
	ft_check_first_line(tab[2]);
}

void	ft_make_print(t_data *d, char *line)
{
	t_print	*new;
	t_print	*tmp;

	new = (t_print *)malloc(sizeof(t_print));
	new->str = ft_strdup(line);
	new->next = NULL;
	if (d->map_print == NULL)
	{
		d->map_print = new;
		return ;
	}
	tmp = d->map_print;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_print_map(t_data *d)
{
	t_print	*tmp;

	tmp = d->map_print;
	while (tmp)
	{
		ft_putstr(tmp->str);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
