/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:49:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 16:23:39 by rfibigr          ###   ########.fr       */
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
# include "../lib/minilibx/mlx.h"

/*
** --------------------------------------------
** ------------------ TYPE_DEF-----------------
** --------------------------------------------
*/
typedef	struct		s_room
{
	char			*name;
	int				x_coord;
	int				y_coord;
	struct s_room	**connection;
	struct s_room	*next;
	int				explored;
	int				index;
	struct s_room	*parent;
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

typedef struct		s_mlx
{
	void			*init;
	void			*image;
	void			*name;
	int				bpp;
	int				size_line;
	int				endian;
	char			*str;
}					t_mlx;

/*
** --------------------------------------------
** -------------- CREATE LIST  ----------------
** --------------------------------------------
*/

int					create_list(t_anthill *anthill, t_room **list_room, char *str);
int					ft_nbants(t_anthill *anthill, char *str);
void				ft_comment(t_anthill *anthill, char *str);

/*
** --------------------------------------------
** -------------- CREATE LIST TOOL-------------
** --------------------------------------------
*/
void				add_input(t_list **lst_input, char *str);
int					is_pipe(char *str);
t_room				*ft_search_name(t_room **room, char *name);
int					ft_isnumber(char *str);

/*
** --------------------------------------------
** -------------- CREATE ROOM  ----------------
** --------------------------------------------
*/

int					ft_create_room(t_anthill *anthill, t_room **room, char *str);
int					check_duplicate_room(t_room **room, char *name);
void				add_room_lst(t_room **room, char **split, t_anthill *anthill);
t_room				*ft_create_elem_room(char **split);

/*
** --------------------------------------------
** -------------- CREATE PIPE -----------------
** --------------------------------------------
*/
int					ft_create_pipe(t_anthill *anthill, t_room **room, char *str);
int					check_duplicate_pipe(t_room **room, char *name_one, char *name_two);
void				add_pipe_lst(t_room **room, char **split);
void				ft_create_elem_pipe(t_room **elem_one, t_room *elem_two);
void				add_elem_connection(t_room **elem_room, t_room *elem_connected);

/*
** --------------------------------------------
** -------------- INITIALISATION  -------------
** --------------------------------------------
*/
void				init_anthill(t_anthill *anthill);

/*
** --------------------------------------------
** -----------TEST VALID ANTHILL  -------------
** --------------------------------------------
*/
int					test_anthill(t_anthill anthill, t_room *room);
int					pipe_valid_format(char **split);
int					room_valid_format(char **split);

/*
** --------------------------------------------
** --------------- FT_PATH  -------------------
** --------------------------------------------
*/
int					ft_path(t_anthill *anthill);
void				ft_shortest_path(t_room **start);
void				add_list_to_explore(t_room **elem, t_list **list_to_explore);
void				del_list_to_explore(t_list **list);

/*
** --------------------------------------------
** ------------------- TOOLS  -----------------
** --------------------------------------------
*/
void				print_room(t_room *room, t_anthill anthill);
int					ft_tablen(t_room **tab);
void				print_explore(t_list *list);

/*
** --------------------------------------------
** ------------------- EXIT -------------------
** --------------------------------------------
*/
void				ft_exit_malloc(void);
void				free_all(t_list *input, t_room *room);
void				free_split(char **split);

#endif
