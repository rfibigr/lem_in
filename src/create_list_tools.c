/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:10:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/01 23:31:02 by rfibigr          ###   ########.fr       */
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
	if (!(ft_isalpha(str[0])))
		return (0);
	while (str[i] != '-')
	{
		if (!(ft_isalpha(str[i])))
			return (0);
		i++;
	}
	i++;
	while (str[i])
	{
		if (!(ft_isalpha(str[i])))
			return (0);
		i++;
	}
	if (!(ft_isalpha(str[i - 1])))
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
