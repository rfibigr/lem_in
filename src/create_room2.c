/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:18:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/25 20:47:18 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room_lst(t_room **room, char **split, t_anthill *anthill)
{
	t_room	*elem;

	elem = ft_create_elem_room(split);
	if (anthill->command == START)
		anthill->start = elem;
	else if (anthill->command == END)
		anthill->end = elem;
	anthill->command = 0;
	elem->next = *room;
	*room = elem;
}

t_room	*ft_create_elem_room(char **split)
{
	t_room	*elem;

	elem = (t_room*)malloc(sizeof(t_room));
	elem->name = split[0];
	elem->x_coord = ft_atoi(split[1]);
	elem->y_coord = ft_atoi(split[2]);
	elem->already_pass = 0;
	elem->next = NULL;
	elem->connection = NULL;
	free(split[1]);
	free(split[2]);
	return(elem);
	//CREER UN TABLE DE HASH POUR RETROUVER LES NOMS
}

int		add_pipe_lst(t_room **room, char **split)
{
	t_room	*elem_one;
	t_room	*elem_two;

	elem_one = ft_search_name(room, split[0]);
	elem_two = ft_search_name(room, split[1]);
	if (elem_one == NULL || elem_two == NULL)
		return (0);
	ft_create_elem_pipe(&elem_one, elem_two);
	ft_create_elem_pipe(&elem_two, elem_one);
	return(1);
}

t_room	*ft_search_name(t_room **room, char *name)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_create_elem_pipe(t_room **elem_room, t_room *elem_connected)
{
	t_room **tab_connection;
	t_room **tab_new;
	int len;

	tab_connection = NULL;
	tab_new = NULL;
	if ((*elem_room)->connection == NULL)
	{
		//FONCTION CREATE NEW CONNECTION
		tab_connection = (t_room**)malloc(sizeof(t_room *) * 2);
		tab_connection[0] = elem_connected;
		tab_connection[1] = NULL;
		(*elem_room)->connection = tab_connection;
	}
	else
	{
		//FONCTION ADD CONNECTION
		len = 0;
		tab_connection = (*elem_room)->connection;
		//Calcul size of connection
		while (tab_connection[len])
			len++;
		// malloc size of connection + 2
		tab_new = (t_room**)malloc(sizeof(t_room *) * (len + 2));
		len = 0;
		//copy connection in new
		while (tab_connection[len])
		{
			tab_new[len] = tab_connection[len];
			len ++;
		}
		// add elem_two and NULL
		tab_new[len] = elem_connected;
		len = len + 1;
		tab_new[len] = NULL;
		//free connection;
		ft_memdel((void **)&((*elem_room)->connection));
		(*elem_room)->connection = tab_new;
	}
}
