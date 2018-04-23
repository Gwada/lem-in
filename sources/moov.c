/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 08:44:03 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/23 18:47:50 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

void			go_first_link(t_node *node)
{
	while (node->links && node->links->prev)
		node->links = node->links->prev;
}

static	void	moov_ant(t_graph *g, t_node *from, t_node *to)
{
	if (!from || !to || !g)
		return ;
	if (from->ant_name > 0)
	{
		if (from == g->start)
		{
			if (to == g->end)
				++g->end->ant_name;
			else
				to->ant_name = g->pop - --from->ant_name;
		}
		if (from != g->start)
			to == g->end ? ++to->ant_name : (to->ant_name = from->ant_name);
		if (g->bd & COLOR)
			ft_printf("L{green}%d{eoc}-{red}%s {eoc}", to->ant_name, to->name);
		else
			ft_printf("L%d-%s ", to->ant_name, to->name);
	}
	else if (to != g->end)
		to->ant_name = 0;
	return (moov_ant(g, from->from, from));
}

void			moov(t_graph *g)
{
	g->start->ant_name = g->pop;
	g->end->ant_name = 0;
	while (g->end->ant_name < g->pop)
	{
		go_first_link(g->end);
		while (g->end->links)
		{
			if (g->end->links->node->bd & IN_PATH)
				moov_ant(g, g->end->links->node, g->end);
			if (!g->end->links->next)
				break ;
			g->end->links = g->end->links->next;
		}
		ft_printf("\n");
	}
}
