/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:20:02 by rfibigr           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/02 20:10:01 by rfibigr          ###   ########.fr       */
=======
/*   Updated: 2018/11/02 19:30:36 by rfibigr          ###   ########.fr       */
>>>>>>> 474a9833cb2352108bc8b201d408dd746676b1a0
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** creer une variable error : on rentre un enum correspondant a l'erreur que
** l'on imprimme apres.
*/

int		create_list(t_anthill *anthill, t_room **list_room, char *str)
{
	if (str[0] == 'L')
		return (0);
	else if (str[0] == '#')
		ft_comment(anthill, str);
	else if (anthill->nb_ant == 0)
	{
		if (!(ft_nbants(anthill, str)))
			return (0);
	}
	else if (is_room(str) && anthill->input_pipe == 0)
	{
		if (!ft_create_room(anthill, list_room, str))
			return (0);
	}
	else if (is_pipe(str))
	{
		if (!(ft_create_pipe(anthill, list_room, str)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		ft_nbants(t_anthill *anthill, char *str)
{
	int i;

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
	if (str[1] == '#')
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
