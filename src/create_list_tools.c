/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:10:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 12:23:18 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_input(t_list **lst_input, char *str)
{
	if (*lst_input == NULL)
		*lst_input = ft_lstnewcpy(str, ft_strlen(str) + 1);
	else
		ft_list_push_back_cpy(lst_input, str, ft_strlen(str) + 1);
}

int		is_pipe(char *str)
{
	int i;

	i = 0;
	if (!(ft_isascii(str[0])))
		return (0);
	while (str[i] != '-' && str[i])
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	if (str[i] == 0)
		return (0);
	i++;
	while (str[i])
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	if (!(ft_isascii(str[i - 1])))
		return (0);
	return (1);
}

t_room	*ft_search_name(t_room **room, char *name)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		pipe_valid_format(char **split)
{
	int i;

	i = 0;
	if (!(split[0] && split[1]))
		return (0);
	while (split[0][i])
	{
		if (!(ft_isascii(split[0][i])))
			return (0);
		i++;
	}
	i = 0;
	while (split[1][i])
	{
		if (!(ft_isascii(split[1][i])))
			return (0);
		i++;
	}
	return (1);
}

int		room_valid_format(char **split)
{
	if (!(split[0] && split[1] && split[2]))
		return (0);
	if (!(ft_isnumber(split[2])) && !(ft_isnumber(split[1])))
		return (0);
	return (1);
}
