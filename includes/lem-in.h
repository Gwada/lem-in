/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:56:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/12 21:25:29 by dlavaury         ###   ########.fr       */
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
# define ROOM_NAME		(1 << 7)
# define ROOM_COO_X		(1 << 8)
# define ROOM_COO_y		(1 << 9)

# define VISITED		(1 << 0)
# define EMPTY			(1 << 1)

# define GNL			get_next_line

/*
**		Structures
*/

typedef	struct			s_room
{
	char				*name;
	char				bd;
//	int					bd;
	int					x;
	int					y;
	int					n_links;
	struct s_room		*links;
}						t_room;

typedef	struct			s_graph
{
	int					bd;
	unsigned int		pop;
	t_list				*lst;
	char				*start;
	char				*end;
	t_room				*nodes;
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
