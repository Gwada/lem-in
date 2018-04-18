/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:39:44 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/18 19:25:32 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	int			wrong_value(int *n, char *arg)
{
	unsigned long	x;

	x = 0;
	while (*arg)
		if ((x = x * 10 + *arg++ - '0') > IMAX)
			return (0);
	*n = (int)x;
	return (1);
}

t_node				*new_node(char **data)
{
	int				i;
	t_node			*new;

	i = 0;
	if (!data || !(new = malloc(sizeof(t_node))))
		return (NULL);
	ft_bzero(new, sizeof(t_node));
	new->name = *data;
	if (!wrong_value(&new->x, data[1]) || !wrong_value(&new->y, data[2]))
	{
		free_tab(data, 4, -1);
		return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	free_tab(data, 4, 0);
	return (new);
}

t_node				*node_finder(t_node *node, char *name)
{
	int				ret;

	if ((ret = ft_strcmp(node->name, name)) < 0)
	{
		if (node->next && ft_strcmp(node->next->name, name) <= 0)
			return (node_finder(node->next, name));
		return (node);
	}
	else if (ret > 0)
	{
		if (node->prev && ft_strcmp(node->prev->name, name) >= 0)
			return (node_finder(node->prev, name));
		return (node);
	}
	return (node);
}

static	t_node		*insert_node(t_node *node, t_node *new)
{
	int				ret;

	if ((ret = ft_strcmp(node->name, new->name)) < 0)
	{
		new->next = node->next ? node->next : NULL;
		node->next ? node->next->prev = new : NULL;
		new->prev = node;
		node->next = new;
	}
	else if (ret > 0)
	{
		new->prev = node->prev ? node->prev : NULL;
		node->prev ? node->prev->next = new : NULL;
		new->next = node;
		node->prev = new;
	}
	return (new);
}

int					add_node(t_graph *g, char **arg)
{
	t_node			*new;

	if (!(new = new_node(arg)) && (g->bd = ERROR))
		return (0);
	if (!g->node && ++g->n_nodes)
		g->node = new;
	else
	{
		g->node = node_finder(g->node, new->name);
		if (!(ft_strcmp(g->node->name, new->name)))
		{
			g->node->x = new->x;
			g->node->y = new->y;
			free(new->name);
			free(new);
		}
		else if (++g->n_nodes)
			g->node = insert_node(g->node, new);
	}
	if (g->bd & GET_START && (g->start = g->node->name))
		g->bd &= ~GET_START;
	if (g->bd & GET_END && (g->end = g->node->name))
		g->bd &= ~GET_END;
	return (1);
}
