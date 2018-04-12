/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:12:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 11:20:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

void		node_parser(t_graph *g, int ret, int i)
{
	ft_printf("{black}{bold}{underline}IN\tNODE_PARSER\n{eoc}");/////////////////
	while (g->bd & CHECK_NODE)
	{
		g->bd &= ~CHECK_NODE;
		g->bd |= CHECK_LINKS;
	}
	(void)g;
	(void)i;
	(void)ret;
	ft_printf("{black}{bold}{underline}END\tNODE_PARSER\n\n{eoc}");//////////////
}
