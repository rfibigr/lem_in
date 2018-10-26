/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:31:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/26 17:14:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit_malloc(void)
{
	ft_printf("malloc fail");
	exit(1);
}

void	free_all(t_list *input, t_room *room)
{
	t_room	*tmp;
	t_list	*lst_tmp;

	while (input)
	{
		lst_tmp = input;
		input = input->next;
		ft_memdel((void**)&(lst_tmp->content));
		ft_memdel((void**)&lst_tmp);
	}
	while (room)
	{
		tmp = room;
		room = room->next;
		if (tmp->connection)
			ft_memdel((void**)&(tmp->connection));
		ft_memdel((void**)&(tmp->name));
		ft_memdel((void**)&tmp);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_memdel((void**)&(split[i]));
		i++;
	}
	ft_memdel((void**)&split);
}
