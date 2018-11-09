/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:50:48 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 15:24:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant_list(t_ant *ant_list)
{
	t_room *room;

	while (ant_list->path && ant_list)
	{
		room = ant_list->path->content;
		ft_printf("L%d-%s", ant_list->name, room->name);
		ant_list = ant_list->next;
		if (ant_list)
			write(1, " ", 1);
		else
			break ;
	}
	write(1, "\n", 1);
}

void	ft_send_all_ant(int nb_ant, char *end_name)
{
	int	i;

	i = 1;
	while (i <= nb_ant)
	{
		ft_printf("L%d-%s", i, end_name);
		if (i != nb_ant)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_input(t_list *list)
{
	while (list)
	{
		ft_printf("%s", list->content);
		ft_printf("\n");
		list = list->next;
	}
	ft_printf("\n");
}
