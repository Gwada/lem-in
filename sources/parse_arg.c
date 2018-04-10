/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:42:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/10 19:43:49 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	int		pop_parser(t_graph *g, void *str)
{
	int			i;
	char		*s;

	i = -1;
	s = (char*)str;
	while (s[++i])
		if ((!i && s[i] != '+' && (s[i] > '9' || s[i] < '0'))
		|| (i && (s[i] > '9' || s[i] < '0')))
		{
			ft_printf("ERROR");
			return (0);
		}
	g->pop = (unsigned int)ft_atoi(s);
	ft_printf("{green}{bold}{underline}pop = %d\n\n{eoc}", g->pop);//////////////
	g->bd &= ~CHECK_POP;
	g->bd |= CHECK_NODE;
	return (1);
}

static	int		node_parser(t_graph *g, char *s)
{
	int			n_arg;
//	char		**tab;

	n_arg = ft_countwords(s, ' ', 0);
	ft_printf("{cyan}{bold}test node{eoc}\n");///////////////////////////////////
	ft_printf("{yellow}%s{eoc}\nn_arg = {red}%d{eoc}\n", s, n_arg);//////////////
	if (n_arg == 1)
		ft_printf("{red}{bold}{underline}verif com ou fin node_parser{eoc}\n\n");//
	if (!n_arg || n_arg == 2 || n_arg > 3)
		ft_printf("{red}{bold}{underline}verif com ou erreur{eoc}\n\n");/////////
	if (n_arg == 3)
		ft_printf("{red}{green}{underline}verif name + coordonnes{eoc}\n\n");////
	(void)g;
	return (1);
}

int				parse_file(t_graph *g, char *s)
{
	t_list		*l;

	if (!(l = ft_lstnew(NULL, ft_strlen(s))))
		return (0);
	l->content = s;
	ft_lstadd(&g->lst, l);
	if (g->bd & CHECK_POP)
		return (pop_parser(g, l->content));
	if (g->bd & CHECK_NODE)
		return (node_parser(g, l->content));
	else if (g->bd & CHECK_LINKS)
	{
		ft_printf("{yellow}{bold}test links{eoc}\n");////////////////////////////
	}
	return (1);
}
