/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:51:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/14 18:43:21 by dlavaury         ###   ########.fr       */
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

static	int		get_arg(t_graph *g)
{
	int			ret;
	t_arg		*a;

	if (!(a = malloc(sizeof(t_arg))) || (ret = GNL(0, &a->s)) < 0)
	{
		free(a->s);
		free(a);
		return (-1);
	}
	if (!ret)
	{
		free(a->s);
		free(a);
		if (!g->l)
			return (-1);
		while (g->l && g->l->prev)
			g->l = g->l->prev;
		return (1);
	}
	a->next = NULL;
	a->prev = g->l ? g->l : NULL;
	g->l ? g->l->next = a : 0;
	g->l = a;
	return (get_arg(g));
}

int				main(int argc, char **argv)
{
	ft_printf("\n\n\n");/////////////////////////////////////////////////////////

	t_graph		g;

	init_struct(&g, argv);
	if (argc == 1 && get_arg(&g) > 0)
	{
		if (!(parser(&g)))
			return (0);
		cleaner(&g);
	}
	cleaner(&g);

	ft_printf(".......................................................\n\n\n");//
	return (0);
}
