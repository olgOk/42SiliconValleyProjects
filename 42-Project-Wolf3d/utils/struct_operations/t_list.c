/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:54:05 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/27 18:54:06 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_list		*add_list_back(t_list *list, char *line)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	new->line = ft_strdup(line);
	new->next = NULL;
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

void		delete_list(t_list **list)
{
	t_list	*node;

	node = *list;
	if (node && node->next)
		delete_list(&node->next);
	free(node->line);
	free(node);
}

int			size_list(t_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}
