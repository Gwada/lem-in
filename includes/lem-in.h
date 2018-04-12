/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:56:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 17:22:03 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**		LIBRARIES
*/

# include "libft.h"

/*
**		MACCROS
*/

# define ERROR			(1 << 0)
# define GOOD			(1 << 1)
# define CHECK_POP		(1 << 2)
# define CHECK_NODE		(1 << 3)
# define CHECK_LINKS	(1 << 4)
# define GET_START		(1 << 5)
# define GET_END		(1 << 6)

# define GNL			get_next_line

/*
**		Structures
*/

typedef	struct			s_graph
{
	int					bd;
	unsigned int		pop;
	t_list				*lst;
}						t_graph;

/*
**		PROTOTYPES
*/

int						parse_file(t_graph *g, char *s);
int						parser(t_graph *g);
int						add_elem(t_graph *g, char **s, int ret);
int						is_com(char *s);
void					node_parser(t_graph *g, int i);
void					print_arg(t_list *lst);
void					remove_arg(t_list *lst);

#endif
