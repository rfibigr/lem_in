/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:39:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/07 20:31:00 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_anthill	anthill;
	t_room		*list_room;
	t_list		*lst_input;
	char		*str;
	t_list	*list_of_path;

	list_of_path = NULL;
	list_room = NULL;
	str	= NULL;
	lst_input = NULL;
	init_anthill(&anthill);
	while (get_next_line(0, &str))
	{
		if (!(create_list(&anthill, &list_room, str)))
			break;
		ft_list_push_back_cpy(&lst_input, str, ft_strlen(str) + 1);
	}
	if (!(test_anthill(anthill, list_room)))
		ft_exit_error(lst_input, list_room, &str);
	ft_print_input(lst_input);
	ft_path(&anthill, &list_room, &list_of_path);
	if (argc == 2)
		visualizer(argv, list_room, list_of_path, anthill);
	free_all(lst_input, list_room, &str);
	return (0);
}
