/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:12:12 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/20 02:56:34 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	t_link		*create_link(t_graph *g, t_node *node)
{
	t_link			*link;

	if (!(link = malloc(sizeof(t_link))))
	{
		g->bd = ERROR;
		cleaner(g);
		return (NULL);
	}
	link->node = node;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

t_link				*link_finder(t_node *node, char *name)
{
	int				ret;

	if (!node->links)
		return (NULL);
	if ((ret = ft_strcmp(node->links->node->name, name)) < 0)
	{
		if (node->links->next
		&& ft_strcmp(node->links->next->node->name, name) <= 0)
		{
			node->links = node->links->next;
			return (link_finder(node, name));
		}
		return (NULL);
	}
	else if (ret > 0)
	{
		if (node->links->prev
		&& ft_strcmp(node->links->prev->node->name, name) >= 0)
		{
			node->links = node->links->prev;
			return (link_finder(node, name));
		}
		return (NULL);
	}
	return (node->links);
}

static	t_link		*insert_link(t_node *node, t_link *link)
{
	int				ret;

	if (!node->links)
		return (link);
	if ((ret = ft_strcmp(node->links->node->name, link->node->name)) < 0)
	{
		link->next = node->links->next ? node->links->next : NULL;
		if (node->links->next)
			node->links->next->prev = link;
		link->prev = node->links;
		node->links->next = link;
	}
	else if (ret > 0)
	{
		link->prev = node->links->prev ? node->links->prev : NULL;
		if (node->links->prev)
			node->links->prev->next = link;
		link->next = node->links;
		node->links->prev = link;
	}
	return (link);
}

int					add_link(t_graph *g, char *name_1, char *name_2)
{
	t_link			*link_1;
	t_link			*link_2;
	t_node			*node_1;
	t_node			*node_2;

	if (!g || !name_1 || !*name_1 || !name_2 || !*name_2)
		return (0);
	link_1 = NULL;
	link_2 = NULL;
	node_1 = node_finder(g->node, name_1);
	node_2 = node_finder(g->node, name_2);
	if (!link_finder(node_1, name_2) && ++g->n_links)
	{
		if (!(link_1 = create_link(g, node_2))
		|| !(link_2 = create_link(g, node_1)))
			return (0);
		++node_1->n_links;
		++node_2->n_links;
		node_1->links = insert_link(node_1, link_1);
		node_2->links = insert_link(node_2, link_2);
	}
	return (1);
}
