/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cremove_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:01 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/18 05:18:23 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				cremove_node(t_clist **list, t_node *node)
{
	if (list && *list && node)
	{
		if ((*list)->nb_nodes > 1)
		{
			if (node == (*list)->start)
				(*list)->start = node->next;
			if (node == (*list)->end)
				(*list)->end = node->prev;
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		else
		{
			(*list)->start = NULL;
			(*list)->end = NULL;
		}
		ft_memdel((void **)&(node->content));
		ft_memdel((void **)&node);
		(*list)->nb_nodes -= 1;
	}
}
