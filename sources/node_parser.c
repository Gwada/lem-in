/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/23 18:59:14 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"/////////////////////////////////////////

int				is_com(char *s)
{
	return (*s && *s == '#');
}

int				is_command(t_graph *g, char *s)
{
	if (!ft_strcmp(s, "##start"))
	{
		g->bd & CHECK_NODE ? g->bd &= ~GET_END : 0;
		g->bd & CHECK_NODE ? g->bd |= GET_START : 0;
		return (1);
	}
	if (!ft_strcmp(s, "##end"))
	{
		g->bd & CHECK_NODE ? g->bd &= ~GET_START : 0;
		g->bd & CHECK_NODE ? g->bd |= GET_END : 0;
		return (1);
	}
	return (0);
}

static	int		in_graph(t_graph *g, char *s, size_t len, int ret)
{
	ft_printf("in in_graph *s = %s\n", s);
	ret = ft_strncmp(g->node->name, s, len);
	ft_printf("ret = %d\n", ret);
	if (ret < 0)
	{
		if (!g->node->next)
			return (0);
		if (ft_strncmp(g->node->next->name, s, len) > 0
		&& ft_strlen(g->node->next->name) != len)
			return (0);
		g->node = g->node->next;
		return (in_graph(g, s, len, 0));
	}
	if (ret > 0)
	{
		if (!g->node->prev)
			return (0);
		if (ft_strncmp(g->node->prev->name, s, len) < 0
		&& ft_strlen(g->node->prev->name) != len)
			return (0);
		g->node = g->node->prev;
		return (in_graph(g, s, len, 0));
	}
	if (!ret)
	{
		if (ft_strlen(g->node->name) > len && g->node->prev)
			if (ft_strncmp(g->node->prev->name, s, len) >= 0)
			{
				g->node = g->node->prev;
				return (in_graph(g, s, len, 0));
			}
		if (ft_strlen(g->node->name) < len && g->node->next)
			if (ft_strncmp(g->node->next->name, s, len) <= 0)
			{
				g->node = g->node->next;
				return (in_graph(g, s, len, 0));
			}
	}
	return (!ret && ft_strlen(g->node->name) == len ? 1 : 0);
}

int				is_location(t_graph *g, char *s)
{
	char		*name;
	int			i;

	i = 0;
	name = NULL;
	if (!g || !s || !*s || g->n_nodes < 2)
		return (0);
	while (s[i] && s[i] != '-')
		++i;
	ft_printf("%s\n", s);
	while (s[i] && s[i] == '-')
	{
		if (in_graph(g, s, i, 0) && (name = g->node->name))
			if (s[i] == '-' && in_graph(g, &s[i + 1], ft_strlen(&s[i + 1]), 0))
			{
				if (!ft_strcmp(name, &s[i + 1]))
					return (1);
				return (add_link(g, name, &s[i + 1]));
			}
		++i;
	}
	error_display(g, 9, g->l->s, g->line);
	return (0);
}
