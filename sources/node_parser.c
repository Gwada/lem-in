/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/18 19:57:31 by dlavaury         ###   ########.fr       */
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


static	int		in_grap(t_node *n, char *s, int ret)
{
	!ret ? ret = ft_strncmp(n->name, s, ft_strlen(n->name)) : 0;
	if (ret < 0)
	{
		if (!n->next
		|| (ret = ft_strncmp(n->next->name, s, ft_strlen(n->next->name))) > 0)
			return (0);
		return (ret ? in_grap(n->next, s, ret) : 1);
	}
	if (ret > 0)
	{
		if (!n->prev
		|| (ret = ft_strncmp(n->prev->name, s, ft_strlen(n->prev->name))) < 0)
			return (0);
		return (ret ? in_grap(n->prev, s, ret) : 1);
	}
	return (1);
}

int				is_location(t_graph *g, char *s)
{
	char		**name;
	int			i;
	int			link;

	i = -1;
	link = 0;
	if (g->n_nodes < 2)
		return (0);
	if (!(name = make_tab(2)))
	{
		g->bd = ERROR;
		return (0);
	}
//	if (!(name = ft_strsplit(s, '-')) && (g->bd = ERROR))
//		return (0);
	if (in_grap(g->node, s, 0))
		ft_printf("{green}good work\n");
	else
		ft_printf("{red}big shit{eoc}\n");
/*	if (in_grap(g->node, *name, 0) && in_grap(g->node, name[1], 0))
		link = ft_strcmp(*name, name[1]) ? add_link(g, name) : 1;
	free(name[0]);
	free(name[1]);
	free(name[2]);
	free(name);*/
	return (link);
}
