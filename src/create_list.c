/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:20:02 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/25 20:19:13 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
Lire ligne par ligne
lire nb fourmis
lire les salle
lire les tubes

sauvegarder les noms dans un tableau pour verif des pipes ??


A FAIRE

gestion des duplicatats des salles.
gestion des duplicatats de pipe.
gestion des leaks et des erreurs.

*/


int		create_list(t_anthill *anthill, t_room **list_room, char *str)
{
	(void)list_room;

	if (str[0] =='L')
		return(0);
	//Check if command or comment
	if (str[0] =='#' && (anthill->command == COMMENT || anthill->command == 0))
		ft_comment(anthill, str);
	// check ants number
	else if (anthill->nb_ant == 0)
	{
		if (!(ft_nbants(anthill, str)))
			return (0);
	}
	//create room
	else if (anthill->input_pipe == 0 && is_pipe(str) == 0)
	{
		if (!ft_create_room(anthill, list_room, str))
			return (0);
	}
	//create pipe
	else
		if (!(ft_create_pipe(anthill, list_room, str)))
			return (0);
	return (1);
}

int		ft_nbants(t_anthill *anthill, char *str)
{
	int i;
	int str_len;

	str_len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	anthill->nb_ant = ft_atoi(str);
	if (anthill->nb_ant == 0)
		return (0);
	return (1);
}


void	ft_comment(t_anthill *anthill, char *str)
{
	//IF COMMAND check if start or end, then add to input
	if(str[1] == '#')
	{
		anthill->command = TRUE;
		if (!(ft_strcmp(str, "##start")))
			anthill->command = START;
		else if (!(ft_strcmp(str, "##end")))
			anthill->command = END;
	}
	else
		anthill->command = COMMENT;
}

void	add_input(t_list **lst_input, char *str)
{

	if (*lst_input == NULL)
		*lst_input = ft_lstnew(str, ft_strlen(str));
	else
		ft_list_push_back(lst_input, str, ft_strlen(str));
}
