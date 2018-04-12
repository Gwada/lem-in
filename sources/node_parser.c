/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 17:21:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

int				add_elem(t_graph *g, char **s, int ret)
{
	t_list		*l;

	if (!(l = ft_lstnew(NULL, 0)) || (ret = GNL(0, (char**)&l->content) < 0))
	{
		g->bd = ERROR;
		return (0);
	}
	ft_lstadd(&g->lst, l);
	*s = (char*)l->content;
	return (1);
}

//int				is_com(char *s)
//{
//	return (*s && *s == '#' && *(s + 1) != '#');
//}

void			node_parser(t_graph *g, int i)
{
	ft_printf("{black}{bold}{underline}IN\tNODE_PARSER\n{eoc}");/////////////////


	char		*s;

	s = NULL;
	ft_printf("test\n", s);//////////////////////////////////////////////////////
	while (g->bd & CHECK_NODE)
	{
		ft_printf("test\n", s);//////////////////////////////////////////////////
		if (!add_elem(g, &s, 0))
			break ;
		ft_printf("%s\n", s);////////////////////////////////////////////////////
		if (!*s)
		{
			ft_printf("{magenta}{bold}EMPTY LINE{eoc}\n");///////////////////////
			break ;
		}
//		if (!is_com(s))
//		{
//			ft_printf("{red}{bold}NO COMS\n{eoc}");//////////////////////////////
//		}
		else
			ft_printf("{green}{bold}THIS IS COM{eoc}\n");////////////////////////
		g->bd &= ~CHECK_NODE;
		g->bd |= CHECK_LINKS;
	}
	(void)i;


	ft_printf("{black}{bold}{underline}END\tNODE_PARSER\n\n{eoc}");//////////////
}
