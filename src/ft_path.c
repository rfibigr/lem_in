/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 13:57:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	on entre les valeurs dans anthill START

	on parcourt le graphe en largeur


*/


int		ft_path(t_anthill *anthill, t_room *room)
{
	(void)room;
	anthill->nb_start_pipe = ft_tablen(anthill->start->connection);
	anthill->nb_end_pipe = ft_tablen(anthill->end->connection);


	return (0);
}


/*  ALGO PARCOUR LARGEUR

// Reflechir au nombre de chemin a emprunter en fonction du nombre de foumies
// a faire traverser.



start->compteur = 0
fonction add_list(start, list)


function de calcul des chemins les plus courts

	while (list)

		Function list_head = get_element(list)
		parent = list_head;
		while (list_head->connection[i])
			If si connection[i]->explored == 0 || connection[i]->compteur > parent->compteur + 1.
				conneciton[i]->parent = parent;
				connection[i]->compteur = parent->compteur + 1;
				connection[i]->explored = 1;
				fonction add_list(connection[i], list)
			else
		fonction del_first_list(list);

while (chemin possible)

	function de calcul des chemins les plus courts
	function qui remonte chemin le plus court et supprime toutes les connections.
	et sauvagrde dans une liste

si chemin_possible = Error






list = 0
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;

list = 2 1
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;

list = 1 5 6
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;

list = 5 6 3 4 7
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;

list =  6 3 4 7 8
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;
8 compteur = 3 / explored = 1 / parent = 5;
4 compteur = 3 / explored = 1 / parent = 5;

list =  3 4 7 8  8
2 compteur = 1 / explored = 1 / parent = 0;
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;
8 compteur = 3 / explored = 1 / parent = 6;
4 compteur = 3 / explored = 1 / parent = 5;

list =  4 7 8 4 8 2 7
2 compteur = 1 / explored = 1 / parent = 0; // on ajoute pas 2 car compteur = 3
1 compteur = 1 / explored = 1 / parent = 0;
5 compteur = 2 / explored = 1 / parent = 2;
6 compteur = 2 / explored = 1 / parent = 2;
8 compteur = 3 / explored = 1 / parent = 5; //creer un tableau de parent si explorated = 0
8 compteur = 3 / explored = 1 / parent = 6;
4 compteur = 3 / explored = 1 / parent = 5;

*/
