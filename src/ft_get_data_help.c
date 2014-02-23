/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:38:17 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/23 21:07:14 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_get_data_help(int fd, char *line, t_data *d)
{
	get_next_line(fd, &line);
	ft_make_print(d, line);
	ft_start_data(d, line);
}

void	ft_get_data_help2(int fd, char *line, t_data *d)
{
	get_next_line(fd, &line);
	ft_make_print(d, line);
	ft_end_data(d, line);
}
