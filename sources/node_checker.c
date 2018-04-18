/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:37:07 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/18 19:57:24 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

char				**make_tab(size_t size)
{
	char			**tab;
	size_t			i;

	i = -1;
	if (!(tab = malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++i < size + 1)
		tab[i] = NULL;
	return (tab);
}

int					free_tab(char **tab, size_t size, int i)
{
	if (!tab)
		return (0);
	while (++i < (int)size && tab[i])
	{
		tab[i] ? free(tab[i]) : 0;
		tab[i] = NULL;
	}
	tab  ? free(tab) : 0;
	tab = NULL;
	return (0);
}

static	int			cut_arg(char *s, char **def, int start, int end)
{
	int				i;

	i = -1;
	while (s[end] && s[end] == ' ')
		++end;
	while (++i < 3 && s[end])
	{
		while (s[end] && s[end] != ' ')
			++end;
		if (!(def[i] = ft_strsub(s, start, end - start)))
			return (free_tab(def, 4, -1) - 1);
		s[end] ? ++end : 0;
		start = end;
		if (s[end] == ' ')
			return (free_tab(def, 4, -1));
	}
	i = 0;
	while(def[i])
		++i;
	return (i != 3 || s[end] ? free_tab(def, 4, -1) : 1);
}

int					is_node(t_graph *g, char *s)
{
	char			**def;
	int				i;
	int				j;
	int				ret;
	int				n_spaces;

	i = 0;
	def = NULL;
	n_spaces = 0;
	if (!(def = make_tab(3)))
		return (0);
	if (((ret = cut_arg(s, def, 0, 0)) == -1 && (g->bd = ERROR)) || !ret)
		return (0);
	while (++i < 3)
	{
		j = (def[i][0] == '+' ? 1 : 0);
		if (!ft_str_is_numeric(&def[i][j]))
		{
			g->bd &= ~CHECK_NODE;
			return (free_tab(def, 4, -1));
		}
	}
	return ((!add_node(g, def) && (g->bd = ERROR)) ? 0 : 1);
}
