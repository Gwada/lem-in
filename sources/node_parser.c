/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 13:40:10 by dlavaury         ###   ########.fr       */
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
//		ft_printf("{green}{bold}IS START COMMAND\n{eoc}");///////////////////////
		return (1);
	}
	if (!ft_strcmp(s, "##end"))
	{
		g->bd & CHECK_NODE ? g->bd &= ~GET_START : 0;
		g->bd & CHECK_NODE ? g->bd |= GET_END : 0;
//		ft_printf("{green}{bold}IS END COMMAND\n{eoc}");/////////////////////////
		return (1);
	}
//	ft_printf("{red}{bold}NO COMMAND\n{eoc}");///////////////////////////////////
	return (0);
}


static    int        in_grap(t_node *node, char *name, int ret)
{
    !ret ? ret = ft_strcmp(node->name, name) : 0;
    if (ret < 0)
    {
        if (!node->next || (ret = ft_strcmp(node->next->name, name)) > 0)
            return (0);
        return (ret ? in_grap(node->next, name, ret) : 1);
    }
    if (ret > 0)
    {
        if (!node->prev || (ret = ft_strcmp(node->prev->name, name)) < 0)
            return (0);
        return (ret ? in_grap(node->prev, name, ret) : 1);
    }
    return (1);
}

int				is_location(t_graph *g, char *s)
{
	char		**name;
	int			i;
	int			link;
	int			minus;

	i = -1;
	link = 0;
	name = NULL;
	minus = 0;
	while (s[++i])
		s[i] == '-' && s[i + 1] ? ++minus : 0;
	if (minus == 1 && g->n_nodes > 0)
	{
		if (!(name = ft_strsplit(s, '-')) && (g->bd = ERROR))
			return (0);
		if (in_grap(g->node, *name, 0) && in_grap(g->node, name[1], 0))
			link = ft_strcmp(*name, name[1]) ? add_link(g, name) : 1;
		free(name[0]);
		free(name[1]);
		free(name[2]);
		free(name);
//		!link ? ft_printf("{green}{bold}FALSE NAME\n{eoc}") : 0;/////////////////
	}
//	else/////////////////////////////////////////////////////////////////////////
//		ft_printf("{red}NO LOCATION\n{eoc}");////////////////////////////////////
	return (link);
}
