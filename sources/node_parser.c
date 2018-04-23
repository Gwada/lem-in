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

static	int		in_graph(t_graph *g, char *s)
{
	int			ret;

	if (!g || !s || !*s)
		return (0);
	if ((ret = ft_strcmp(g->node->name, s)) < 0)
	{
		if (g->node->next && ft_strcmp(g->node->next->name, s) <= 0)
		{
			g->node = g->node->next;
			return (in_graph(g, s));
		}
		return (0);
	}
	if (ret > 0)
	{
		if (g->node->prev && ft_strcmp(g->node->prev->name, s) >= 0)
		{
			g->node = g->node->prev;
			return (in_graph(g, s));
		}
		return (0);
	}
	return (1);
}

int				is_location(t_graph *g, char *s, int i)
{
	char		*tmp;
	char		*name;

	if (!(tmp = ft_strnew(ft_strlen(s))))
		if (error_display(g, 23, NULL, 1) && (g->bd = ERROR))
			return (0);
	if (!g || !s || !*s || g->n_nodes < 2)
		return (0);
	while (s[++i] && s[i] != '-')
		tmp[i] = s[i];
	while (s[i] && s[i] == '-')
	{
		if (in_graph(g, tmp) && (name = g->node->name))
			if (s[i] == '-' && in_graph(g, &s[i + 1]))
			{
				free(tmp);
				if (!ft_strcmp(name, &s[++i]))
					return (1);
				return (add_link(g, name, &s[i]));
			}
		(tmp[i] = s[i]) ? ++i : 0;
	}
	free(tmp);
	error_display(g, 9, g->l->s, g->line);
	return (0);
}
