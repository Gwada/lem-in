/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/15 21:11:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"/////////////////////////////////////////

int				is_com(char *s)
{
	if (*s && *s == '#' && *(s + 1) != '#')//////////////////////////////////////
		ft_printf("{green}{bold}IS COM\n{eoc}");/////////////////////////////////
	else/////////////////////////////////////////////////////////////////////////
		ft_printf("{red}{bold}NO COM\n{eoc}");///////////////////////////////////
	return (*s && *s == '#' && *(s + 1) != '#');
}

int				is_command(t_graph *g, char *s)
{
	if (!ft_strcmp(s, "##start"))
	{
		g->bd &= ~GET_END;
		g->bd |= GET_START;
		ft_printf("{green}{bold}IS START COMMAND\n{eoc}");///////////////////////
		return (1);
	}
	if (!ft_strcmp(s, "##end"))
	{
		g->bd &= ~GET_START;
		g->bd |= GET_END;
		ft_printf("{green}{bold}IS END COMMAND\n{eoc}");/////////////////////////
		return (1);
	}
	if (*s && *s == '#' && *(s + 1) == '#')
	{
		g->bd &= ~CHECK_NODE;
		ft_printf("{yellow}{bold}BAD COMMAND -> start lem-in\n{eoc}");///////////
		return (1);
	}
	ft_printf("{red}{bold}NO COMMAND\n{eoc}");///////////////////////////////////
	return (0);
}

int				is_node(t_graph *g, char *s)
{
	char		**def;
	int			i;
	int			j;
	int			n_spaces;

	i = -1;
	def = NULL;
	n_spaces = 0;
	while (s[++i])
		s[i] == ' ' && s[i + 1] ? ++n_spaces : 0;
	if (n_spaces != 2 || *s == 'L')
	{
		n_spaces != 2 ? ft_printf("{red}{bold}NO ROOM DEF\n{eoc}") : 0;//////////
		*s == 'L' ? ft_printf("{yellow}{bold}BAD NAME -> start lem-in\n{eoc}") : 0;//
		return (0);
	}
	if (!(i = 0) && !(def = ft_strsplit(s, ' ')) && (g->bd = ERROR))
		return (0);
	while (++i < 3)
	{
		j = (def[i][0] == '+' || def[i][0] == '-' ? 0 : -1);
		while (def[i][++j])
			if (def[i][j] > '9' || def[i][j] < '0')
			{
				i = -1;
				g->bd &= ~CHECK_NODE;
				ft_printf("{yellow}{bold}BAD COOR -> start lem-in\n{eoc}");//////
				while (++i < 4)
					free(def[i]);
				free(def);
				return (0);
			}
	}
	ft_printf("{green}{bold}IS GOOD ROOM DEF\n{eoc}");///////////////////////////
	if (!add_node(g, def) && (g->bd = ERROR))
		return (0);
	ft_printf("{yellow}{bold}name = %s\t", g->node->name);///////////////////////
	ft_printf("x = %d\ty = %d\n{eoc}", g->node->x, g->node->y);//////////////////
	return (1);
}

static	int		in_grap(t_node *node, char *name, int ret)
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
	if (minus == 1)
	{
		if (!(name = ft_strsplit(s, '-')) && (g->bd = ERROR))
			return (0);
		if (ft_strcmp(*name, name[1]))
			if (in_grap(g->node, *name, 0) && in_grap(g->node, name[1], 0))
				link = add_link(g, name);
		free(name[0]);
		free(name[1]);
		free(name[2]);
		free(name);
		!link ? ft_printf("{green}{bold}FALSE NAME\n{eoc}") : 0;/////////////////
	}
	else/////////////////////////////////////////////////////////////////////////
		ft_printf("{red}NO LOCATION\n{eoc}");////////////////////////////////////
	return (link);
}
