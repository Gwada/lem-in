/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/13 17:55:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

int				is_com(char *s)
{
//	if (*s && *s == '#' && *(s + 1) != '#')
//		ft_printf("{green}{bold}IS COM\n{eoc}");/////////////////////////////////
//	else
//		ft_printf("{red}{bold}NO COM\n{eoc}");///////////////////////////////////
	return (*s && *s == '#' && *(s + 1) != '#');
}

static int		is_command(t_graph *g, char *s)
{
	if (!ft_strcmp(s, "##start"))
	{
		g->bd &= ~GET_END;
		g->bd |= GET_START;
//		ft_printf("{green}{bold}IS START COMMAND\n{eoc}");///////////////////////
		return (1);
	}
	if (!ft_strcmp(s, "##end"))
	{
		g->bd &= ~GET_START;
		g->bd |= GET_END;
//		ft_printf("{green}{bold}IS END COMMAND\n{eoc}");/////////////////////////
		return (1);
	}
	if (*s && *s == '#' && *(s + 1) == '#')
	{
		g->bd &= ~CHECK_NODE;
		g->bd |= CHECK_LINKS;
//		ft_printf("{yellow}{bold}BAD COMMAND -> start lem-in\n{eoc}");///////////
		return (1);
	}
//	ft_printf("{red}{bold}NO COMMAND\n{eoc}");///////////////////////////////////
	return (0);
}

static	int		is_room_def(t_graph *g, char *s)
{
	int			i;
	int			j;
	int			n_spaces;
	char		**def;

	i = -1;
	def = NULL;
	n_spaces = 0;
	while (s[++i])
		s[i] == ' ' ? ++n_spaces : 0;
	if (n_spaces != 2)
	{
//		ft_printf("{red}{bold}NO ROOM DEF\n{eoc}");//////////////////////////////
		return (0);
	}
	if (!(def = ft_strsplit(s, ' ')))
	{
		g->bd = ERROR;
		return (0);
	}
	i = -1;
	if (def[0][0] == 'L')
	{
		g->bd &= ~CHECK_NODE;
		g->bd |= CHECK_LINKS;
//		ft_printf("{yellow}{bold}BAD NAME -> start lem-in\n{eoc}");//////////////
		while (++i < 4)
			free(def[i]);
		free(def);
		return (0);
	}
	i = 0;
	while (++i < 3)
	{
		j = (def[i][0] == '+' || def[i][0] == '-' ? 0 : -1);
		while (def[i][++j])
			if (def[i][j] > '9' || def[i][j] < '0')
			{
				i = -1;
				g->bd &= ~CHECK_NODE;
				g->bd |= CHECK_LINKS;
//				ft_printf("{yellow}{bold}BAD COOR -> start lem-in\n{eoc}");//////
				while (++i < 4)
					free(def[i]);
				free(def);
				return (0);
			}
	}
//	ft_printf("{green}{bold}IS GOOD ROOM DEF\n{eoc}");///////////////////////////
	if (!add_node(g, def) && (g->bd = ERROR))
		return (0);
//	ft_printf("{green}test node\nname\t= %s\n", g->node->name);
//	ft_printf("x\t= %d\ny\t= %d\n{eoc}", g->node->x, g->node->y);
	return (1);
}

void			node_parser(t_graph *g, int i)
{
	ft_printf("{black}{bold}{underline}IN\tNODE_PARSER\n{eoc}");/////////////////


	char		*s;

	s = NULL;
	while (g->bd & CHECK_NODE)
	{
		if (!add_elem(g, &s, 0))
			break ;
//		*s? ft_printf("{underline}%s\n{eoc}", s) : 0;////////////////////////////
		if (!*s || *s == ' ')
		{
//			ft_printf("{magenta}{bold}EMPTY LINE OR START BY SPACE OR EOF{eoc}\n");//
			break ;
		}
		if (!is_com(s) && !is_command(g, s) && !is_room_def(g, s))
		{
			g->bd &= ~CHECK_NODE;
			g->bd |= CHECK_LINKS;
		}
		ft_printf("\n");//
//		g->bd &= ~CHECK_NODE;////////////////////////////////////////////////////
//		g->bd |= CHECK_LINKS;////////////////////////////////////////////////////
	}
	(void)i;
	t_node *tmp;
	tmp = g->node;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		ft_printf("{cyan}%s{eoc}\n", tmp->name);
		tmp = tmp->next;
	}

	ft_printf("{black}{bold}{underline}END\tNODE_PARSER\n\n{eoc}");//////////////
}
