/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:37:07 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 21:28:57 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	int			free_tab(char **def, int size, int i)
{
	if (!def)
		return (0);
	while (++i < size && def[i])
	{
		def[i] ? free(def[i]) : 0;
		def[i] = NULL;
	}
	def  ? free(def) : 0;
	def = NULL;
	return (0);
}

static	int			cut_arg(char *s, char **def, int start, int end)
{
	int				i;

	i = -1;
	while (s[end] && s[end] == ' ')
		++end;
	def[3] = NULL ;
	while (++i < 3)
	{
		def[i] = NULL;
		while (s[end] && s[end] != ' ')
			++end;
		if (!(def[i] = ft_strsub(s, start, end - start)))
			return (free_tab(def, 4, -1));
		start = s[end] ? ++end : end;
//		start = ++end;
		if (s[end] == ' ')
			return (free_tab(def, 4, -1));
	}
	i = 0;
	while(def[i])
		++i;
	return (i != 3 || s[start] ? free_tab(def, 4, -1) : 1);
}

int					is_node(t_graph *g, char *s)
{
	char			**def;
	int				i;
	int				j;
	int				n_spaces;

	i = 0;
	def = NULL;
	n_spaces = 0;
	if (!(def = malloc(sizeof(char*) * 4)))
		return (0);
	if (!cut_arg(s, def, 0, 0) && (!def ? (g->bd = ERROR) : 1))
		return (0);
	while (++i < 3)
	{
		ft_printf("i = %d\ndef[%d][%d] = %c\n", i, i, 0, def[i][0]);
		j = (def[i][0] == '+' ? 1 : 0);
		ft_printf("i = %d\ndef[%d][%d] = %c\n\n", i, i, j, def[i][j]);
		if (!ft_str_is_numeric(&def[i][j]))
		{
			ft_printf("{red}%s\n{eoc}", &def[i][j]);
			g->bd &= ~CHECK_NODE;
			return (free_tab(def, 3, -1));
		}
	}
	if (!add_node(g, def) && (g->bd = ERROR))
	{
		ft_printf("ERROR add_node\n");
		return (0);
	}
	return (1);
}
