/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:42:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/14 19:47:30 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	void	pop_parser(t_graph *g, int i)
{
	ft_printf("{black}{bold}{underline}IN\tPOP_PARSER\n{eoc}");//////////////////


	char		*s;

	while (g->bd & CHECK_POP && g->l)
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
		g->l->next ? g->l = g->l->next : 0;
	}
	g->bd & CHECK_POP ? g->bd = ERROR : 0;


	ft_printf("{green}pop = %d\n", g->pop);//////////////////////////////////////
	ft_printf("{black}{bold}{underline}END\tPOP_PARSER\n\n{eoc}");///////////////
}

static	void	node_parser(t_graph *g)
{
	ft_printf("{black}{bold}{underline}IN\tNODE_PARSER\n{eoc}");/////////////////


	char		*s;

	s = NULL;
	while (g->bd & CHECK_NODE && g->l->next)
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
			is_location(g, s) ? g->bd |= CHECK_LINKS : 0;
		}
		g->l->next ? g->l = g->l->next : 0;
		ft_printf("\n");/////////////////////////////////////////////////////////
	}
	while (g->node->prev)////////////////////////////////////////////////////////
		g->node = g->node->prev;/////////////////////////////////////////////////
	while (g->node)//////////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("{cyan}%s\n{eoc}", g->node->name);/////////////////////////////
		if (!g->node->next)//////////////////////////////////////////////////////
			break ;//////////////////////////////////////////////////////////////
		g->node = g->node->next;/////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("{black}{bold}{underline}\nEND\tNODE_PARSER\n\n{eoc}");////////////
}

int				parser(t_graph *g)
{
	pop_parser(g, -1);
	if (g->bd ^ ERROR && g->bd & CHECK_NODE)
		node_parser(g);
	ft_printf("{yellow}g->start = %s\ng->end = %s\n\n{eoc}", g->start, g->end);//

	!(g->bd & ERROR) && g->bd & GOOD ? print_arg(g->l) : 0;
	return (g->bd == ERROR ? 0 : 1);
}
