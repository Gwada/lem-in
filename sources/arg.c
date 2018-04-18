/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:45 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/18 15:26:36 by dlavaury         ###   ########.fr       */
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
	if (l->prev)
	{
		l->prev->next = NULL;
		remove_arg(l->prev);
	}
	if (l->s)
		free(l->s);
	free(l);
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
	if (link->prev)
	{
		link->prev->next = NULL;
		remove_links(link->prev);
	}
	free(link);
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
	if (node->prev)
	{
		node->prev->next = NULL;
		remove_nodes(node->prev);
	}
	if (node->name)
		free(node->name);
	if (node->links)
		remove_links(node->links);
	free(node);
}

void		cleaner(t_graph *g)
{
	if (g->l)
		remove_arg(g->l);
	g->l = NULL;
	if (g->node)
		remove_nodes(g->node);
	g->node = NULL;
}
