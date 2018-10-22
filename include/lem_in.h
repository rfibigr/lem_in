/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:49:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/22 18:40:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// --------- INCLUDE ---------
# include "../lib/libft/include/libft.h"

typedef	struct	s_room
{
	char	*name;
	int		x_coord;
	int		y_coord;
	struct s_room	**connection;
	struct s_room	*next;
	int		already_pass;
}				t_room;

typedef struct	s_anthill
{
	int		nb_ant;
	int		nb_start_pipe;
	int		nb_end_pipe;
	t_room	*start;
	t_room	*end;
}				t_anthill;

// --------------------------------------------
// ---------------CREATE LISTE-----------------
// --------------------------------------------

int		create_list(t_anthill *anthill, t_room **list_room, char *str);
void	ft_nbants(t_anthill *anthill, char *str);

// --------------------------------------------
// ---------------INITIALISE-------------------
// --------------------------------------------

void	init_anthill(t_anthill *anthill);

#endif
