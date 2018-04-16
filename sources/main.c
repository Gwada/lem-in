/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:51:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/16 20:16:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

static	void	init_struct(t_graph *g, char **argv)
{
	(void)argv;
	ft_bzero(g, sizeof(*g));
	g->bd |= CHECK_POP;
	g->bd |= GOOD;
}

int				get_arg(t_graph *g, int ret)
{
	t_arg		*a;

	a = NULL;
	if (!(a = malloc(sizeof(t_arg))))
		return (-1);
	if ((ret = GNL(0, &a->s)) < 1)
	{
		if (!ret)
			free(a->s);
		if (g->l)
			while (g->l->prev)
				g->l = g->l->prev;
		free(a);
		return (ret);
	}
	a->next = NULL;
	a->prev = g->l ? g->l : NULL;
	g->l ? g->l->next = a : 0;
	g->l = a;
	return (1);
}

int				main(int argc, char **argv)
{
//	ft_printf("\n\n");///////////////////////////////////////////////////////////
	t_graph		g;

	init_struct(&g, argv);
	if (argc == 1/* && get_arg(&g, 0) >= 0*/)
	{
		if (!(parser(&g)))
		{
			cleaner(&g);
			return (0);
		}
	}
	cleaner(&g);
//	ft_printf(".......................................................\n\n");////
	return (0);
}
