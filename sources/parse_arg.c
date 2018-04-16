/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:42:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/16 14:38:16 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	void	pop_parser(t_graph *g, int i)
{
	ft_printf("{black}{bold}{underline}IN\tPOP_PARSER\n{eoc}");//////////////////


	char		*s;

	while (g->bd & CHECK_POP)
	{
		s = g->l->s;
		if ((*s == '#' && s[1] == '#')
		|| (*s != '+' && *s != '#' && (*s > '9' || *s < '0')))
			break ;
		i = *s == '+' ? 0 : -1;
		while (s[0] != '#' && s[++i])
			if (s[i] > '9' || s[i] < '0')
				break ;
		if (s[0] != '#' && s[i] && (s[i] > '9' || s[i] < '0'))
			break ;
		s[0] != '#' && !s[i] ? g->bd &= ~CHECK_POP : 0;
		s[0] != '#' && !s[i] ? g->bd |= CHECK_NODE : 0;
		s[0] != '#' && !s[i] ? g->pop = (unsigned int)ft_atoi(s) : 0;
		if (!g->l->next)
			break ;
		g->l = g->l->next;
	}


	ft_printf("{green}pop = %d\n", g->pop);//////////////////////////////////////
	ft_printf("{black}{bold}{underline}END\tPOP_PARSER\n\n{eoc}");///////////////
}

static	void	node_parser(t_graph *g)
{
	ft_printf("{black}{bold}{underline}IN\tNODE_PARSER\n{eoc}");/////////////////
	char		*s;

	s = NULL;
	while (g->bd & CHECK_NODE)
	{
		s = g->l->s;
		*s? ft_printf("%s\n{eoc}", s) : 0;///////////////////////////////////////
		if (!*s || *s == ' ')
		{
			ft_printf("{magenta}{bold}EMPTY LINE OR START BY SPACE OR EOF{eoc}\n");//
			break ;
		}
		if (!is_com(s) && !is_command(g, s) && !is_node(g, s))
		{
			g->bd &= ~CHECK_NODE;
			is_location(g, s) && !(g->bd & ERROR) ? g->bd |= CHECK_LINKS : 0;
		}
		if (!g->l->next)
			break ;
		g->l = g->l->next;
		g->bd & CHECK_NODE ? ft_printf("\n") : 0;////////////////////////////////
	}
	ft_printf("{black}{bold}{underline}END\tNODE_PARSER\n\n{eoc}");//////////////
}

static	void	location_parser(t_graph *g)
{
	ft_printf("{black}{bold}{underline}IN\tLOCATION_PARSER\n{eoc}");/////////////
	char		*s;

	s = NULL;
	while (g->bd & CHECK_LINKS)
	{
		s = g->l->s;
		*s? ft_printf("%s\n{eoc}", s) : 0;///////////////////////////////////////
		if (!*s || *s == ' ')
		{
			ft_printf("{magenta}{bold}EMPTY LINE OR START BY SPACE OR EOF{eoc}\n");//
			break ;
		}
		!is_com(s) && !is_location(g, s) ? g->bd &= ~CHECK_LINKS : 0;
		if (!g->l->next)
			break ;
		g->l = g->l->next;
		ft_printf("\n");/////////////////////////////////////////////////////////
	}
	!*s ? g->bd |= GOOD : 0;
	ft_printf("{black}{bold}{underline}END\tLOCATION_PARSER\n\n{eoc}");//////////
}

static	void	print_graph(t_graph *g)//////////////////////////////////////////
{////////////////////////////////////////////////////////////////////////////////
	t_link		*link;///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
	link = NULL;/////////////////////////////////////////////////////////////////
	ft_printf("{yellow}{bold}ant\t\t= %d\n", g->pop);////////////////////////////
	ft_printf("n_nodes\t\t= %d\n", g->n_nodes);//////////////////////////////////
	ft_printf("n_links\t\t= %d\n", g->n_links);//////////////////////////////////
	ft_printf("start\t\t= %s\n", g->start);//////////////////////////////////////
	ft_printf("end\t\t= %s\n\n{eoc}", g->end);///////////////////////////////////
	while (g->node && g->node->prev)/////////////////////////////////////////////
		g->node = g->node->prev;/////////////////////////////////////////////////
	if (g->node)/////////////////////////////////////////////////////////////////
		while (g->node)//////////////////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			ft_printf("{red}node->name\t= {underline}%s\n{eoc}", g->node->name);//
			ft_printf("node->x\t\t= %d\n", g->node->x);//////////////////////////
			ft_printf("node->y\t\t= %d\n", g->node->y);//////////////////////////
			ft_printf("node->n_links\t= %d\n", g->node->n_links);////////////////
			if ((link = g->node->links))/////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				while (link->prev)///////////////////////////////////////////////
					link = link->prev;///////////////////////////////////////////
				while (link)/////////////////////////////////////////////////////
				{////////////////////////////////////////////////////////////////
					ft_printf("{green}{underline}%s\t{eoc}", link->node->name);//
					if (!link->next)/////////////////////////////////////////////
						break ;//////////////////////////////////////////////////
					link = link->next;///////////////////////////////////////////
				}////////////////////////////////////////////////////////////////
				ft_printf("\n");/////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			else/////////////////////////////////////////////////////////////////
				ft_printf("{red}{underline}NO LINKS{eoc}\n");////////////////////
			if (!g->node->next)//////////////////////////////////////////////////
				break ;//////////////////////////////////////////////////////////
			g->node = g->node->next;/////////////////////////////////////////////
			ft_printf("\n\n");///////////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////
}////////////////////////////////////////////////////////////////////////////////

int				parser(t_graph *g)
{
	pop_parser(g, -1);
	if (g->pop > 0 && g->bd ^ ERROR && g->bd & CHECK_NODE)
		node_parser(g);
	ft_printf("test |%s|\n", g->l->s);
	if (g->n_nodes > 1 && g->bd ^ ERROR && g->bd & CHECK_LINKS)
		location_parser(g);
	print_graph(g);//////////////////////////////////////////////////////////////;
	g->bd != ERROR && g->bd & GOOD ? print_arg(g->l) : 0;
	ft_printf("test |%s|\n", g->l->s);
	return (1);
}
