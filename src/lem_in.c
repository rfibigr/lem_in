/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:39:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/01 18:37:57 by rfibigr          ###   ########.fr       */
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
		add_input(&anthill.input, str);
		ft_memdel((void**)&str);
	}
	ft_memdel((void**)&str);
	if (!(test_anthill(anthill, list_room)))
	{
		free_all(anthill.input, list_room);
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("=============== ROOM BEFORE ==================\n");
	// print_room(list_room, anthill);
	ft_path(&anthill, &list_room);
	ft_printf("=============== ROOM AFTER ==================\n");
	// print_room(list_room, anthill);

//	MINILIBIX
	// t_mlx	mlx;
	// mlx.init = mlx_init();
	// mlx.name = mlx_new_window(mlx.init, 1000, 1000, "Lem-in");
	// mlx_loop(mlx.init);
	free_all(anthill.input, list_room);
	return (0);
}
