/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:39:44 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/13 18:21:41 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

t_node			*new_node(char **data)
{
	int			i;
	t_node		*new;

	i = 0;
	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	ft_bzero(new, sizeof(t_node));
	if (data)
	{
		new->name = *data;
		new->x = ft_atoi(*(data + 1));
		new->y = ft_atoi(*(data + 2));
		new->next = NULL;
		new->prev = NULL;
		while (++i < 4)
			free(data[i]);
		free(data);
	}
	return (new);
}

t_node		*node_finder(t_node *node, char *name)
{
	int		ret;
//	ft_printf("node = %s\tname = %s\t", node->name, name);

	if ((ret = ft_strcmp(node->name, name)) < 0)
	{
//		ft_printf("< 0\n");
		if (node->next && ft_strcmp(node->next->name, name) < 0)
		{
//			ft_printf("{red}if (node->next && ft_strcmp(node->next->name, name) < 0)\n\n{eoc}");
			return (node_finder(node->next, name));
		}
//		ft_printf("\n");
		return (node);
	}
	else if (ret > 0)
	{
//		ft_printf("> 0\n");
		if (node->prev && ft_strcmp(node->prev->name, name) > 0)
		{
//			ft_printf("{green}if (node->prev && ft_strcmp(node->prev->name, name) > 0)\n\n{eoc}");
			return (node_finder(node->prev, name));
		}
//		ft_printf("\n");
		return (node);
	}
	return (node);
}

t_node		*insert_node(t_node *node, t_node *new)
{
	if (ft_strcmp(node->name, new->name) < 0)
	{
//		ft_printf("< 0\n\n");
		new->next = node->next ? node->next : NULL;
		node->next ? node->next->prev = new : NULL;
		new->prev = node;
		node->next = new;
	}
	else if (ft_strcmp(node->name, new->name) > 0)
	{
//		ft_printf("> 0\n\n");
		new->prev = node->prev ? node->prev : NULL;
		node->prev ? node->prev->next = new : NULL;
		new->next = node;
		node->prev = new;
	}
	return (new);
}

int			add_node(t_graph *g, char **data)
{
	t_node	*new;

	if (!(new = new_node(data)))
		return (0);
	if (!g->node)
		g->node = new;
	else
	{
//		ft_printf("1 g->node = %s\tnew = %s\n", g->node->name, new->name);
		g->node = node_finder(g->node, new->name);
//		ft_printf("2 g->node = %s\tnew = %s\t", g->node->name, new->name);
		if (!(ft_strcmp(g->node->name, new->name)))
		{
			g->node->x = new->x;
			g->node->y = new->y;
			free(new->name);
			free(new);
		}
		else
			g->node = insert_node(g->node, new);
	}
	new = g->node;
	while (new->prev)
		new = new->prev;
	while(new)
	{
//		printf("new->name = %s\n", new->name);
		new = new->next;
	}
//	ft_printf("\n");
//	ft_printf("\n");
	return (1);
}
