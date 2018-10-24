/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:51:33 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/24 11:26:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_room(t_anthill *anthill, t_room **room, char *str)
{
	(void) room;
	(void) anthill;
	char	**split;
	int		i;

	add_input(&anthill->input, str);
	anthill->command = 0;
	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i != 3 || room_valid_format(split) == 0)
	{
		ft_printf("error : room format");
		return (0);
	}
	add_room_lst(room, split, anthill);
	return (1);
}

int		ft_create_pipe(t_anthill *anthill, t_room **room, char *str)
{
	(void) room;
	(void) anthill;
	char	**split;
	int		i;

	add_input(&anthill->input, str);
	anthill->command = 0;
	anthill->input_pipe = 1;
	i = 0;
	split = ft_strsplit(str, '-');
	while (split[i])
		i++;
	if (i != 2 || pipe_valid_format(split) == 0)
	{
		ft_printf("error : pipe format");
		return (0);
	}
	// Attention addinput
	if (add_pipe_lst(room, split) == 0)
		return (0);
	return (1);
}

int		room_valid_format(char **split)
{
	int i;

	i = 0;
	if (split[0] && split[1] && split[2])
		return(0);
	//CREATE FONCTION ISNUMBER
	while (split[1][i])
	{
		if (!(ft_isdigit(split[1][i])))
			return (0);
		i++;
	}
	//END FONCTION
	//CREATE FONCTION ISNUMBER
	while (split[2][i])
	{
		if (!(ft_isdigit(split[1][i])))
			return (0);
		i++;
	}
	//END FONCTION
	return (1);
}

int		pipe_valid_format(char **split)
{
	int i;

	i = 0;
	if (split[0] && split[1])
		return(0);
	//CREATE FONCTION ISNUMBER
	while (split[0][i])
	{
		if (!(ft_isdigit(split[1][i])))
			return (0);
		i++;
	}
	//END FONCTION
	//CREATE FONCTION ISNUMBER
	while (split[1][i])
	{
		if (!(ft_isdigit(split[1][i])))
			return (0);
		i++;
	}
	//END FONCTION
	return (1);
}

int		is_pipe(char *str)
{
	int i;
	i = 0;
	if (!(ft_isdigit(str[0])))
		return(0);
	while (str[i] != '-')
	{
		if (!(ft_isdigit(str[i])))
			return(0);
		i++;
	}
	i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return(0);
		i++;
	}
	if (!(ft_isdigit(str[i - 1])))
		return(0);
	return (1);
}
