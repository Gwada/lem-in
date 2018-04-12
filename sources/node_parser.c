/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 21:25:37 by dlavaury         ###   ########.fr       */
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

int				is_com(char *s)
{
	if (*s && *s == '#' && *(s + 1) != '#')
		ft_printf("{green}{bold}IS COM\n{eoc}");
	else
		ft_printf("{red}{bold}NO COM\n{eoc}");
	return (*s && *s == '#' && *(s + 1) != '#');
}

static int		is_command(t_graph *g, char *s)
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
	ft_printf("{red}{bold}NO COMMAND\n{eoc}");///////////////////////////////////
	return (0);
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
		*s? ft_printf("%s\n", s) : 0;////////////////////////////////////////////
		if (!*s)
		{
			ft_printf("{magenta}{bold}EMPTY LINE{eoc}\n");///////////////////////
			break ;
		}
		if (!is_com(s) && !is_command(g, s))
		{
				;
		}
		g->bd &= ~CHECK_NODE;
		g->bd |= CHECK_LINKS;
	}
	(void)i;


	ft_printf("{black}{bold}{underline}END\tNODE_PARSER\n\n{eoc}");//////////////
}
