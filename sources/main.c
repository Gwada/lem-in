/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:51:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 10:26:10 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	void	init_struct(t_graph *g, char **argv)
{
	(void)argv;
	ft_bzero(g, sizeof(*g));
	g->bd |= CHECK_POP;
	g->bd |= GOOD;
}

int				main(int argc, char **argv)
{
	ft_printf("\n\n\n");/////////////////////////////////////////////////////////


	t_graph		g;

	init_struct(&g, argv);
	if (argc == 1)
	{
		if (!(parser(&g)))
			return (0);
	}


	ft_printf("\n\n\n");/////////////////////////////////////////////////////////
	return (0);
}
