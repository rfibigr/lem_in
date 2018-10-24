/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:49:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/24 11:26:50 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// --------------------------------------------
// ------------------ DEFINE -----------------
// --------------------------------------------
# define TRUE 1
# define START 2
# define END 3
# define COMMENT 4

/*
** --------------------------------------------
** ------------------ INCLUDE -----------------
** --------------------------------------------
*/

# include "../lib/libft/include/libft.h"

typedef	struct		s_room
{
	char			*name;
	int				x_coord;
	int				y_coord;
	struct s_room	**connection;
	struct s_room	*next;
	int				already_pass;
}					t_room;

typedef struct		s_anthill
{
	int				nb_ant;
	int				nb_start_pipe;
	int				nb_end_pipe;
	int				command;
	int				input_pipe;
	t_list			*input;
	t_room			*start;
	t_room			*end;
}					t_anthill;


/*
** --------------------------------------------
** -------------- CREATE LIST  ----------------
** --------------------------------------------
*/

int					create_list(t_anthill *anthill, t_room **list_room, char *str);
void				ft_nbants(t_anthill *anthill, char *str);
void				ft_comment(t_anthill *anthill, char *str);
void				add_input(t_list **lst_input, char *str);
int					ft_ispipe(char *str);

/*
** --------------------------------------------
** -------------- CREATE ROOM  ----------------
** --------------------------------------------
*/

int					ft_create_room(t_anthill *anthill, t_room **room, char *str);
int					ft_create_pipe(t_anthill *anthill, t_room **room, char *str);
int					room_valid_format(char **split);
int					pipe_valid_format(char **split);
int					is_pipe(char *str);

/*
** --------------------------------------------
** -------------- CREATE ROOM 2 ----------------
** --------------------------------------------
*/
void				add_room_lst(t_room **room, char **split, t_anthill *anthill);
t_room				*ft_create_elem_room(char **split);
int					add_pipe_lst(t_room **room, char **split);
t_room				*ft_search_name(t_room **room, char *name);
void				ft_create_elem_pipe(t_room *elem_one, t_room *elem_two);

/*
** --------------------------------------------
** -------------- INITIALISATION  -------------
** --------------------------------------------
*/

void				init_anthill(t_anthill *anthill);

#endif
