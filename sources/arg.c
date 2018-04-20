/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:45 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/20 03:26:47 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

void		remove_arg(t_arg *l)
{
	if (!l)
		return ;
	if (l->next)
	{
		l->next->prev = NULL;
		remove_arg(l->next);
	}
	l->next = NULL;
	if (l->prev)
	{
		l->prev->next = NULL;
		remove_arg(l->prev);
	}
	l->prev = NULL;
	if (l->s)
		free(l->s);
	l->s = NULL;
	free(l);
	l = NULL;
}

void		print_arg(t_arg *lst)
{
	if (!lst)
		return ;
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		ft_printf("%s\n", lst->s);
		if (!lst->next)
			return ;
		lst = lst->next;
	}
}

void		remove_links(t_link *link)
{
	if (!link)
		return ;
	if (link->next)
	{
		link->next->prev = NULL;
		remove_links(link->next);
	}
	link->next = NULL;
	if (link->prev)
	{
		link->prev->next = NULL;
		remove_links(link->prev);
	}
	link->prev = NULL;
	free(link);
	link = NULL;
}

void		remove_nodes(t_node *node)
{
	if (!node)
		return ;
	if (node->next)
	{
		node->next->prev = NULL;
		remove_nodes(node->next);
	}
	node->next = NULL;
	if (node->prev)
	{
		node->prev->next = NULL;
		remove_nodes(node->prev);
	}
	node->prev = NULL;
	if (node->links)
		remove_links(node->links);
	node->links = NULL;
	if (node->name)
		free(node->name);
	node->name = NULL ;
	free(node);
	node = NULL;
}

void		cleaner(t_graph *g)
{
	if (g->l)
		remove_arg(g->l);
	g->l = NULL;
	g->end = NULL ;
	g->start = NULL;
	if (g->node)
		remove_nodes(g->node);
	g->node = NULL;
}
