/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:49:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/06 15:22:44 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** --------------------------------------------
** ------------------ DEFINE -----------------
** --------------------------------------------
*/
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
	int				use;
	int				index;
	struct s_room	*parent;
	t_list			*ant;
}					t_room;

typedef struct		s_anthill
{
	int				nb_ant;
	int				command;
	int				input_pipe;
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

typedef struct		s_lst
{
	t_room			*elem;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_ant
{
	int				name;
	t_list			*path;
	struct s_ant	*next;
	struct s_ant	*previous;
}					t_ant;



/*
** --------------------------------------------
** -------------- CREATE LIST  ----------------
** --------------------------------------------
*/

int					create_list(t_anthill *anthill, t_room **list_room, char *str);
int					ft_nbants(t_anthill *anthill, char *str);
void				ft_comment(t_anthill *anthill, char *str);
t_room				*ft_search_name(t_room **room, char *name);

/*
** --------------------------------------------
** -------------- CREATE ROOM  ----------------
** --------------------------------------------
*/
int					ft_create_room(t_anthill *anthill, t_room **room, char *str);
void				add_room_lst(t_room **room, char **split, t_anthill *anthill);
t_room				*ft_create_elem_room(char **split);

/*
** --------------------------------------------
** -------------- TEST VALID ROOM--------------
** --------------------------------------------
*/
int					room_valid_format(t_room **room, char **split);
int					check_duplicate_room(t_room **room, char *name);
int					is_room(char *str);

/*
** --------------------------------------------
** -------------- CREATE PIPE -----------------
** --------------------------------------------
*/
int					ft_create_pipe(t_anthill *anthill, t_room **room, char *str);
int					add_pipe_lst(t_room **room, char **split);
void				ft_create_elem_pipe(t_room **elem_one, t_room *elem_two);
void				add_elem_connection(t_room **elem_room, t_room *elem_connected);

/*
** --------------------------------------------
** --------------TEST VALID PIPE --------------
** --------------------------------------------
*/
int					pipe_valid_format(t_room **room, char **split);
int					is_pipe(char *str);
int					check_duplicate_pipe(t_room **room, char *name_one, char *name_two);

/*
** --------------------------------------------
** -------------- INITIALISATION  -------------
** --------------------------------------------
*/
void				init_anthill(t_anthill *anthill);
void				init_room(t_room **elem);

/*
** --------------------------------------------
** -----------TEST VALID ANTHILL  -------------
** --------------------------------------------
*/
int					test_anthill(t_anthill anthill, t_room *room);
int					test_valid_path(t_anthill *anthill, t_room **room);

/*
** --------------------------------------------
** --------------- FT_PATH  -------------------
** --------------------------------------------
*/
void				ft_path(t_anthill *anthill, t_room **room);
int					ft_add_path(t_list **path_list, t_room **end, t_room **start);
void				ft_shortest_path(t_room **start);
void				add_list_to_explore(t_room **elem, t_lst **list_to_explore);
void				del_list_to_explore(t_lst **list);
/*
** --------------------------------------------
** --------------- FT_PATH TOOLS---------------
** --------------------------------------------
*/
int					ft_condition_to_explore(t_room *room, int index);
int					ft_connection_use(t_room **room);
void				ft_reinit_room(t_room **room, int option_use);
int					direct_path(t_room **room, char *start_name);

/*
** --------------------------------------------
** --------------- FT_ADD_PATH  ---------------
** --------------------------------------------
*/
void				add_to_path(t_list **path, t_room **elem);
void				add_to_pathlist(t_list **path, t_list **elem);

/*
** --------------------------------------------
** --------------- FT_SEND ANT ----------------
** --------------------------------------------
*/
void				ft_send_ant(t_list **path_list, int nb_ant, char *ant_name);
void				create_ant_list(t_ant **ant_list, int nb_ant);
void				ft_add_size_to_path(t_list **list_of_path);

/*
** --------------------------------------------
** --------------- FT_SEND ANT 2 --------------
** --------------------------------------------
*/
void				start_ant(t_ant **ant_list, t_list *path_list, int *ant_start);
t_ant 				*skip_used_ant(t_ant **ant_list);
void				move_ant(t_ant **ant_list);
void				delete_ant_arrived(t_ant **to_ant_list, char *end_name);
void				ft_delete_ant(t_ant **ant, t_ant **ant_list);

/*
** --------------------------------------------
** ------------------ PRINT -------------------
** --------------------------------------------
*/
void				ft_print_input(t_list *list);
void				print_ant_list(t_ant *ant_list);
void				ft_send_all_ant(int nb_ant, char *end_name);

/*
** --------------------------------------------
** ------------------- TOOLS  -----------------
** --------------------------------------------
*/
void				print_room(t_room *room, t_anthill anthill);
int					ft_tablen(t_room **tab);
void				print_explore(t_list *list);
void				ft_print_pathlist(t_list **list_of_path);
void				print_room_solo(t_room *room);
void				print_ant(t_ant *ant);

/*
** --------------------------------------------
** ------------------- EXIT -------------------
** --------------------------------------------
*/
void				ft_exit_error(t_list *input, t_room *room, char **str);
void				ft_exit_malloc(void);
void				free_all(t_list *input, t_room *room, char **str);
void				free_split(char **split);

#endif
