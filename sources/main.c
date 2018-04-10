/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:51:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/10 19:44:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/get_next_line.h"

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


	char		*s_1;
	t_graph		g;

	s_1 = NULL;
	init_struct(&g, argv);
	if (argc == 1)
	{
		while (!(g.bd & ERROR) && get_next_line(0, &s_1) > 0)
			!parse_file(&g, s_1) ? g.bd |= ERROR : 0;
		ft_printf("\n");/////////////////////////////////////////////////////////
		if (!(g.bd & ERROR) && g.bd & GOOD)
		{
			free(s_1);
			print_arg(g.lst);
		}
		else if (g.bd & ERROR)
			remove_arg(g.lst);
	}


	ft_printf("\n\n\n");/////////////////////////////////////////////////////////
	return (0);
}
