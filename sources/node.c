/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:15:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/14 19:24:43 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

/*int				is_node(t_graph *g, char *s)
{
	int			i;
	int			j;
	int			n_spaces;
	char		**def;

	i = -1;
	def = NULL;
	n_spaces = 0;
	while (s[++i])
		s[i] == ' ' ? ++n_spaces : 0;
	if (n_spaces != 2)
	{
		ft_printf("{red}{bold}NO ROOM DEF\n{eoc}");//////////////////////////////
		return (0);
	}
	if (*s == 'L')
	{
		g->bd &= ~CHECK_NODE;
		ft_printf("{yellow}{bold}BAD NAME -> start lem-in\n{eoc}");//////////////
		return (0);
	}
	if (!(def = ft_strsplit(s, ' ')) && (g->bd = ERROR))
		return (0);
	i = -1;
	i = 0;
	while (++i < 3)
	{
		j = (def[i][0] == '+' || def[i][0] == '-' ? 0 : -1);
		while (def[i][++j])
			if (def[i][j] > '9' || def[i][j] < '0')
			{
				i = -1;
				g->bd &= ~CHECK_NODE;
				ft_printf("{yellow}{bold}BAD COOR -> start lem-in\n{eoc}");//////
				while (++i < 4)
					free(def[i]);
				free(def);
				return (0);
			}
	}
	ft_printf("{green}{bold}IS GOOD ROOM DEF\n{eoc}");///////////////////////////
	if (!add_node(g, def) && (g->bd = ERROR))
		return (0);
	ft_printf("{green}test node\nname\t= %s\n", g->node->name);//////////////////
	ft_printf("x\t= %d\ny\t= %d\n{eoc}", g->node->x, g->node->y);////////////////
	return (1);
}*/
