/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:39:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 14:47:28 by rfibigr          ###   ########.fr       */
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
		if (!(create_list(&anthill, &list_room, str)))
			break;
		add_input(&anthill.input, str);
	}
	if (!(test_anthill(anthill, list_room)) || !(test_valid_path(&anthill, &list_room)))
	{
		free_all(anthill.input, list_room, &str);
		ft_printf("Error\n");
		return (0);
	}
	ft_print_input(anthill.input);
	ft_path(&anthill, &list_room);
	free_all(anthill.input, list_room, &str);
	return (0);
}

void	ft_print_input(t_list *list)
{
	while (list)
	{
		ft_printf("%s", list->content);
		ft_printf("\n");
		list = list->next;
	}
	ft_printf("\n");
}
