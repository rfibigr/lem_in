/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:21:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/06 14:34:03 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_send_ant(t_list **path_list, int nb_ant, char *end_name)
{
	int		ant_start;
	t_ant	*ant_list;

	ant_list = NULL;
	ant_start = nb_ant;
	create_ant_list(&ant_list, nb_ant);
	ft_add_size_to_path(path_list);
	while (ant_list)
	{
		move_ant(&ant_list);
		if (ant_start > 0)
			start_ant(&ant_list, *path_list, &ant_start);
		print_ant_list(ant_list);
		delete_ant_arrived(&ant_list, end_name);
	}
}

void	create_ant_list(t_ant **ant_list, int nb_ant)
{
	t_ant *ant;

	while (nb_ant)
	{
		if(!(ant = (t_ant*)malloc(sizeof(t_ant))))
			ft_exit_malloc();
		ant->name = nb_ant;
		ant->path = NULL;
		ant->next = NULL;
		ant->previous = NULL;

		if (*ant_list == NULL)
			*ant_list = ant;
		else
		{
			ant->next = *ant_list;
			(*ant_list)->previous = ant;
			*ant_list = ant;
		}
		nb_ant--;
	}
}

void	ft_add_size_to_path(t_list **list_of_path)
{
	t_list	*path;
	t_list *tmp;

	tmp = *list_of_path;
	path = NULL;
	while (tmp)
	{
		path = tmp->content;
		tmp->content_size = ft_list_size(path) - 1;
		tmp = tmp->next;
	}
}
