/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:39:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/22 18:32:57 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_anthill	anthill;
	t_room		*list_room;
	char		*str;

	list_room = NULL;
	str	= NULL;
	init_anthill(&anthill);
	while (get_next_line(0, &str))
	{
		if(create_list(&anthill, &list_room, str) == 0)
			break;
	}


	return (0);
}
