/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:20:02 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/23 19:23:19 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
Lire ligne par ligne
lire nb fourmis
lire les salle
lire les tubes

sauvegarder les noms dans un tableau pour verif des pipes ??

create fonction for error and free
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
		ft_nbants(anthill, str);
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

void	ft_nbants(t_anthill *anthill, char *str)
{
	int i;
	int str_len;

	str_len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			ft_printf("Error : Ant's number invalid");
			free(str);
			exit(1);
		}
		i++;
	}
	anthill->nb_ant = ft_atoi(str);
	if (anthill->nb_ant == 0)
	{
		ft_printf("Error : No ants");
		free(str);
		exit(1);
	}
	add_input(&anthill->input, str);
}


void	ft_comment(t_anthill *anthill, char *str)
{
	//IF COMMAND check if start or end, then add to input
	if(str[1] == '#')
	{
		anthill->command = TRUE;
		if (ft_strcmp(str, "##start"))
			anthill->command = START;
		else if (ft_strcmp(str, "##end"))
			anthill->command = END;
			//CREATE A FONCTION
		add_input((&anthill->input), str);
	}
	// IF COMMENT add to input
	else
	{
		anthill->command = COMMENT;
		add_input(&anthill->input, str);
	}
}

void	add_input(t_list **lst_input, char *str)
{

	if (*lst_input == NULL)
		*lst_input = ft_lstnew(str, ft_strlen(str));
	else
		ft_list_push_back(lst_input, str, ft_strlen(str));
}
