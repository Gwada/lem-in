/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:42:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 17:22:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

static	void	pop_parser(t_graph *g, int i)
{
	ft_printf("{black}{bold}{underline}IN\tPOP_PARSER\n{eoc}");//////////////////


	char		*s;

	while (g->bd & CHECK_POP)
	{
		if (!add_elem(g, &s, 0))
			break ;
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
	}
	g->bd & CHECK_POP ? g->bd = ERROR : 0;


	ft_printf("{green}pop = %d\n", g->pop);//////////////////////////////////////
	ft_printf("{black}{bold}{underline}END\tPOP_PARSER\n\n{eoc}");///////////////
}

int				parser(t_graph *g)
{
	pop_parser(g, -1);
	if (g->bd ^ ERROR && g->bd & CHECK_NODE)
		node_parser(g, -1);

	if (!(g->bd & ERROR) && g->bd & GOOD)
		print_arg(g->lst);
	else if (g->bd & ERROR)
		remove_arg(g->lst);
	return (g->bd == ERROR ? 0 : 1);
}
