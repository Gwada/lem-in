/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:42:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/20 03:27:25 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

static	void		pop_parser(t_graph *g, int ret)
{
	char			*s;
	unsigned long	num;

	num = 0;
	s = NULL;
	while (g->bd & CHECK_POP)
	{
		if ((ret = get_arg(g, 0)) < 1 || is_command(g, g->l->s))
			return ;
		if (!is_com((s = g->l->s)))
		{
			if (!ft_str_is_numeric(*s == '+' ? ++s : s))
				return ;
			while (*s)
				if ((num = num * 10 + *s++ - '0') > IMAX)
				{
					g->bd = ERROR;
					return ;
				}
			g->bd &= ~CHECK_POP;
			g->bd |= CHECK_NODE;
			g->pop = (unsigned int)num;
		}
	}
}

static	void	node_parser(t_graph *g, int ret)
{
	char		*s;

	s = NULL;
	while (g->bd & CHECK_NODE)
	{
		if ((ret = get_arg(g, 0)) < 1)
			return ;
		if (!*(s = g->l->s) || *s == 'L')
			return ;
		if (!is_command(g, s) && !is_com(s) && !is_node(g, s))
		{
			g->bd &= ~CHECK_NODE;
			if (g->bd & GET_START || g->bd & GET_END || !g->start || !g->end)
				return ;
			if (!(g->bd & ERROR) && is_location(g, s))
			{
				g->bd |= CHECK_LINKS;
				return ;
			}
		}
	}
}

static	void	location_parser(t_graph *g, int ret)
{
	char		*s;

	s = NULL;
	while (g->bd & CHECK_LINKS)
	{
		if ((ret = get_arg(g, 0)) < 1)
			return ;
		if (!*(s = g->l->s))
			return ;
		if (is_command(g, s) || (!is_com(s) && !is_location(g, s)))
			g->bd &= ~CHECK_LINKS;
	}
}

static	void	print_graph(t_graph *g)//////////////////////////////////////////
{////////////////////////////////////////////////////////////////////////////////
	t_link		*link;///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
	link = NULL;/////////////////////////////////////////////////////////////////
	ft_printf("{yellow}{bold}\nant\t\t= %d\n", g->pop);//////////////////////////
	ft_printf("n_nodes\t\t= %d\n", g->n_nodes);//////////////////////////////////
	ft_printf("n_links\t\t= %d\n", g->n_links);//////////////////////////////////
	ft_printf("start\t\t= %s\n", g->start);//////////////////////////////////////
	ft_printf("end\t\t= %s\n\n{eoc}", g->end);///////////////////////////////////
	while (g->node && g->node->prev)/////////////////////////////////////////////
		g->node = g->node->prev;/////////////////////////////////////////////////
	while (g->node)//////////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("{red}node->name\t= {underline}%s\n{eoc}", g->node->name);/////
		ft_printf("node->x\t\t= %d\n", g->node->x);//////////////////////////////
		ft_printf("node->y\t\t= %d\n", g->node->y);//////////////////////////////
		ft_printf("node->n_links\t= %d\n", g->node->n_links);////////////////////
		if ((link = g->node->links))/////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			while (link->prev)///////////////////////////////////////////////////
				link = link->prev;///////////////////////////////////////////////
			while (link)/////////////////////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				ft_printf("{green}{underline}%s\t{eoc}", link->node->name);//////
				if (!link->next)/////////////////////////////////////////////////
					break ;//////////////////////////////////////////////////////
				link = link->next;///////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			ft_printf("\n");/////////////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////
		else/////////////////////////////////////////////////////////////////////
			ft_printf("{red}{underline}NO LINKS{eoc}\n");////////////////////////
		if (!g->node->next)//////////////////////////////////////////////////////
			break ;//////////////////////////////////////////////////////////////
		g->node = g->node->next;/////////////////////////////////////////////////
		ft_printf("\n");/////////////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
}////////////////////////////////////////////////////////////////////////////////

int				parser(t_graph *g)
{
	char		*s;

	s = NULL;
	pop_parser(g, 0);
	if (g->pop > 0 && g->bd ^ ERROR && g->bd & CHECK_NODE)
		node_parser(g, 0);
	if (g->n_nodes > 1 && g->bd ^ ERROR && g->bd & CHECK_LINKS)
		location_parser(g, 0);
	if (g->n_links > 0 && g->bd ^ ERROR && g->bd & GOOD)
		print_arg(g->l);
	print_graph(g);//////////////////////////////////////////////////////////////
	if(!g->pop || g->n_nodes < 2 || !g->n_links || !g->start || !g->end || g->bd & ERROR)
	{
		g->bd = ERROR;
		while (get_next_line(0, &s) > 0)
			free(s);
		free(s);
		cleaner(g);
		ft_printf("{red}{bold}{underline}ERROR{eoc}\n");
		exit(EXIT_SUCCESS);
	}
	else
		ft_printf("{green}{bold}{underline}OK{eoc}\n");
	return (1);
}
