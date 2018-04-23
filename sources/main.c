/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:51:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/23 17:59:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

int				error_display(t_graph *g, int error, char *s, int line)
{
	if (!(g->bd & DEBUG))
		return (line);
	!error ? ft_printf("Line %d: %s (Bad Caracter)\n", line, s) : 0;
	error == 1 ? ft_printf("Line %d: %s (Value > INT_MAX)\n", line, s) : 0;
	error == 2 ? ft_printf("Line %d: %s ", line, s) : 0;
	error == 2 ? ft_printf("(Empty line or starting by 'L')\n") : 0;
	error == 3 ? ft_printf("Line %d: %s (Command not accepted)\n", line, s) : 0;
	error == 4 ? ft_printf("Line %d: %s (Incorrect Line)\n", line, s) : 0;
	error == 5 ? ft_printf("Line %d: %s (Empty line)\n", line, s) : 0;
	error == 6 ? ft_printf("Line %d: %s (Space after name)\n", line, s) : 0;
	error == 7 ? ft_printf("(Start room or end room missing)\n") : 0;
	error == 8 ? ft_printf("Line %d: %s (Invalid caracter)\n", line, s) : 0;
	error == 9 ? ft_printf("Line %d: %s (Invalid name)\n", line, s) : 0;
	error == 22 && !g->pop ? ft_printf("(Ants number is null)\n") : 0;
	error == 22 && g->n_nodes < 2 ? ft_printf("(Too few rooms)\n") : 0;
	error == 22 && !g->n_links ? ft_printf("(Too few links)\n") : 0;
	error == 22 && !g->start ? ft_printf("(No start room)\n") : 0;
	error == 22 && !g->end ? ft_printf("(No end room)\n") : 0;
	error == 23 ? ft_printf("(ERROR MALLOC)\n") : 0;
	return (line);
}

static	void	init_struct(t_graph *g)
{
	ft_bzero(g, sizeof(*g));
	g->bd |= CHECK_POP;
	g->bd |= GOOD;
	g->line = 0;
}

int				get_arg(t_graph *g, int ret)
{
	t_arg		*a;

	a = NULL;
	if (!(a = malloc(sizeof(t_arg))))
	{
		g->bd = ERROR;
		cleaner(g);
		return (error_display(g, 23, NULL, -1));
	}
	if ((ret = GNL(0, &a->s)) < 1)
	{
		free(a->s);
		free(a);
		while (g->l && g->l->prev)
			g->l = g->l->prev;
		ret < 0 ? g->bd = ERROR : 0;
		ret < 0 ? cleaner(g) : 0;
		return (ret < 0 ? error_display(g, 23, NULL, -1) : 0);
	}
	++g->line;
	a->next = NULL;
	a->prev = g->l ? g->l : NULL;
	g->l ? g->l->next = a : 0;
	g->l = a;
	return (1);
}

static	int		get_options(char **argv, int *bd, int i, int j)
{
	int			id;

	id = 0;
	while (argv[++i])
		while (argv[i][++j])
		{
			if (argv[i][0] == '-' && j > 0)
			{
				if ((id = ft_strchri("cDgp", argv[i][j])) >= 0)
					*bd |= ((1 << (id + 10)));
				else
				{
					ft_printf("usage: lem-in [-cDgp]\n");
					ft_printf("Use: -c to see ants mooves with colors\n");
					ft_printf("Use: -D for DEBUG mode\n");
					ft_printf("Use: -g to see graph informations\n");
					ft_printf("Use: -p to see max possible paths\n");
					return (0);
				}
			}
		}
	return (1);
}

int				main(int argc, char **argv)
{
	t_graph		g;

	init_struct(&g);
	if (argc > 1)
		if (!get_options(argv, &g.bd, 0, -1))
			return (0);
	if ((parser(&g)))
	{
		if (path_finder(&g))
		{
			print_arg(g.l);
			ft_printf("\n");
			moov(&g);
		}
		else
			ft_printf("ERROR\n");
	}
	cleaner(&g);
	return (0);
}
