/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:21:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/01 19:19:03 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	//calcul longueur de chaque path_list
	//calcul du nombre de fourmis par path
	//envoie des fourmis

	LIST PATH		0	6
				x2	x10	x1
				x3
				x7
				x78
				89
					1	1
2
					123


	ant_arrive = 0;

	Boucle (ant_arrive != nb_ant)
		faire avancer les fourmis(parcours path, ).
			(on regarde si fourmis dans la case, on les )
			mettre le premier 1 a 0
			mettre le premier 0 a 1
		faire partir des fourmies (mettre a 1 ant dans les paths)
			on cree les fourmis path = 0

*/

//send end room and not end_name
void	ft_send_ant(t_list **path_list, int nb_ant, char *end_name)
{
	int		ant_start;
	t_ant	*ant_list;

	ant_list = NULL;
	ant_start = nb_ant;
	create_ant_list(&ant_list, nb_ant);
	ft_add_size_to_path(path_list);

	// ft_printf("===========ANT BEFORE=============\n");
	// print_ant(ant_list);
	// ft_printf("===========/ANT BEFORE============\n");
	while (ant_list)
	{
	// ft_printf("===========ANT MOVE===============\n");
		move_ant(&ant_list);
	// ft_printf("===========/ANT MOVE==============\n");

	// ft_printf("===========ANT START===============\n");
	if (ant_start > 0)
		start_ant(&ant_list, *path_list, &ant_start);
	// print_ant(ant_list);
	// ft_printf("===========/ANT START==============\n");
		print_ant_list(ant_list);
		// ft_printf("PRINTF LIST OF ANT\n");
		delete_ant_arrived(&ant_list, end_name);
	}
}

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

void	start_ant(t_ant **ant_list, t_list *path_list, int *ant_start)
{
	t_ant	*ant_list_free;

	//on avance ant_list jusqu'au premier libre
	// si plus de gfournis de libre / on exit
	if (!(ant_list_free = skip_used_ant(ant_list)))
		return ;
	// si des fourmis de libre on fait partir dans le premier chemin
	// si le chemin est direct // on supprime la fourmis et on ajoute +1 a ant_end
		// start_ant_in_path(&ant, path);
	ant_list_free->path = path_list->content;
	ant_list_free = ant_list_free->next;
	(*ant_start)--;
	path_list = path_list->next;

	// tant qu'on a des chemins ou des fourmis de libre
	while (path_list && ant_list_free)
	{
		if (*ant_start > (int)path_list->content_size)
		{
			ant_list_free->path = path_list->content;
			ant_list_free = ant_list_free->next;
			(*ant_start)--;
		}
		path_list = path_list->next;
	}
}

t_ant 	*skip_used_ant(t_ant **ant_list)
{
	t_ant	*ant_list_free;

	ant_list_free = *ant_list;
	while (ant_list_free->path && ant_list_free)
	{
		ant_list_free = ant_list_free->next;
	}
	return (ant_list_free);
}

void	move_ant(t_ant **ant_list)
{
	t_ant	*ant;
	t_room	*room;
	t_list	*path;

	ant = *ant_list;
	path = NULL;

	while (ant)
	{
		if (!(ant->path))
			break ;
		path = ant->path;
		path = path->next;
		ant->path = path;
		room = ant->path->content;
		ant = ant->next;
	}
}

void	delete_ant_arrived(t_ant **ant_list, char *end_name)
{
	t_ant	*ant;
	t_room	*room;
	t_ant	*previous;

	ant = *ant_list;
	room = ant->path->content;
	while (ant)
	{
		if(!(ant->path))
			break ;
		room = ant->path->content;
		if(!ft_strcmp(room->name, end_name))
		{
			previous = ant->previous;
			if (previous == NULL)
			{
				*ant_list = (*ant_list)->next;
				if (*ant_list)
					(*ant_list)->previous = NULL;
			}
			else
			{
				ant->next->previous = ant->previous;
				ant->previous->next = ant->next;
			}
			ft_memdel((void**)&ant);
			ant = *ant_list;
		}
		else
			ant = ant->next;
	}
}

// void	ft_del_elem(t_ant **ant_list, t_ant **ant)
// {
// 	if ((*ant)->previous == NULL)
// 	{
// 		*ant_list = (*ant_list)->next;
// 		ft_memdel((void**)ant);
// 		*ant = *ant_list;
// 	}
// 	else
// 	{
// 		tmp = *ant;
// 		*ant = (*ant)->next;
// 		(*ant)->previous = tmp;
// 		ft_memdel((void**)&tmp);
// 	}
//
// }



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
