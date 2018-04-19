/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/19 17:25:37 by dlavaury         ###   ########.fr       */
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
		return (1);
	}
	if (!ft_strcmp(s, "##end"))
	{
		g->bd & CHECK_NODE ? g->bd &= ~GET_START : 0;
		g->bd & CHECK_NODE ? g->bd |= GET_END : 0;
		return (1);
	}
	return (0);
}

static	int		in_graph(t_graph *g, char *s, size_t len, int ret, int test)
{
//	if (test > 10)
//		return (0);
	test = 0;
	ret = ft_strncmp(g->node->name, s, len);
	ft_printf("{yellow}IN IN GRAPH{eoc}\nname = ");
	write(1, s, len);
	ft_printf("\nnode->name = %s\n", g->node->name);
	if (ret < 0)
	{
		ft_printf("test 1\n");
		if (!g->node->next || ft_strncmp(g->node->next->name, s, len) > 0)
		{
			ft_printf("1.1 node->next->name = %s\n\n", g->node->next->name);
			return (0);
		}
		g->node = g->node->next;
		ft_printf("1.2 node->next->name = %s\n\n", g->node->name);
		return (in_graph(g, s, len, 0, ++test));
	}
	if (ret > 0)
	{
		ft_printf("test 2\n\n");
		if (!g->node->prev || ft_strncmp(g->node->prev->name, s, len) < 0)
			return (0);
		g->node = g->node->prev;
		return (in_graph(g, s, len, 0, ++test));
	}
	if (!ret && ft_strlen(g->node->name) > len && g->node->prev)
	{
		ft_printf("test 3\n");
		ft_printf("3.1 node->prev->name = %s\n", g->node->prev->name);
		if (ft_strncmp(g->node->prev->name, s, len) >= 0)
		{
			ft_printf("3.2\n\n");
			g->node = g->node->prev;
			return (in_graph(g, s, len, 0, ++test));
		}
		ft_printf("3.3\n\n");
	}
	if (!ret && ft_strlen(g->node->name) < len && g->node->next)
	{
		ft_printf("test 4\n\n");
		ft_printf("4.1 node->next->name = %s\n\n", g->node->next->name);
		if (ft_strncmp(g->node->next->name, s, len) <= 0)
		{
			g->node = g->node->next;
			return (in_graph(g, s, len, 0, ++test));
		}
	}
	ft_printf("test 5\n\n");
	return (!ret && ft_strlen(g->node->name) == len ? 1 : 0);
}

int				is_location(t_graph *g, char *s)
{
	char		*name;
	int			i;

	i = 0;
	if (!g || !s || !*s || g->n_nodes < 2)
		return (0);
	while (s[i] && s[i] != '-')
		++i;
	ft_printf("{green}s = %s\ni = %d\ns[%d] = %c\n", s, i, i, s[i]);

//	ft_printf("node->name = %s\n\n{eoc}", g->node->name);

	while (s[i] && s[i] == '-')
	{
		if (in_graph(g, s, i, 0, 0) && (name = g->node->name))
		{
			ft_printf("{green}may be{eoc}\n");
//			len = ft_strlen(g->node->name);
//			ft_printf("name = %s\nlen = %d\n", g->node->name, i);
			if (s[i] == '-' && in_graph(g, &s[i + 1], ft_strlen(&s[i + 1]), 0, 0))
			{
				ft_printf("{green}re good way{eoc}\n");
//				ft_printf("name_2 = %s len = %d\n", &s[i + 1], ft_strlen(&s[i + 1]));
//				ft_printf("{green}OK{eoc}\n");
				if (ft_strcmp(name, &s[i + 1]))
				{
					if (add_link(g, name, &s[i + 1]))
						return (1);
					else
					{
						g->bd = ERROR;
						return (0);
					}
				}
			}
			else
				ft_printf("{red}KO{eoc}\n\n\n");
		}
		else
		{
			write(1, s, i);
			ft_printf("\n%s\n", &s[i + 1]);
			ft_printf("{red}\nbig shit{eoc}\n\n\n");
		}
		++i;
//		ft_printf("{red}-----------------------------------------------------------------{eoc}\n\n");
	}
//	ft_printf("\n");
	return (0);
}
