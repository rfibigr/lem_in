/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:20:02 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/22 18:40:34 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
Lire ligne par ligne
lire nb fourmis
lire les salle
lire les tubes


*/

int		create_list(t_anthill *anthill, t_room **list_room, char *str)
{
	(void)list_room;
	if (anthill->nb_ant == 0)
			ft_nbants(anthill, str);




	ft_printf("str = %s\n", str);

	return (1);
}

void	ft_nbants(t_anthill *anthill, char *str)
{

}
