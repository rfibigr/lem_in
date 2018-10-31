/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:21:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/31 17:56:14 by rfibigr          ###   ########.fr       */
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

void	ft_send_ants(t_list **path_list, int nb_ant)
{
	int		ant_number;
	t_list	*ant_list;

	ant_list = NULL;
	ant_number = 1;
	create_ant_list(&ant_list, nb_ant);
	ft_printf("before print\n");
	print_ant(ant_list);
	ft_printf("after print\n");
	ft_add_size_to_path(path_list);

	while (ant_list)
	{
		ft_printf("hello\n");
		//If path_len < nb_fourmis
			//create_ant
	// on assigne la room a la fourmis.

	// on assigne
		// nb_ant--;
		// if (nb_ant == 0)
		// 	break;
		ant_list = ant_list->next;
	}
}

void	create_ant_list(t_list **ant_list, int nb_ant)
{
	t_ant	*ant;
	while (nb_ant)
	{
		if(!(ant = (t_ant*)malloc(sizeof(t_ant))))
			ft_exit_malloc();
		ant->name = nb_ant;
		ant->path = NULL;
		ft_list_push_front(ant_list, ant);
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
		tmp->content_size = ft_list_size(path) - 2;
		tmp = tmp->next;
	}
}
