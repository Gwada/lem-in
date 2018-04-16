/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:56:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/16 15:31:48 by dlavaury         ###   ########.fr       */
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

typedef	struct			s_arg
{
	char				*s;
	struct	s_arg		*prev;
	struct	s_arg		*next;
}						t_arg;

typedef	struct			s_link
{
	struct	s_node		*node;
	struct	s_link		*prev;
	struct	s_link		*next;
}						t_link;

typedef	struct			s_node
{
	char				*name;
	char				bd;
	int					x;
	int					y;
	int					n_links;
	struct s_link		*links;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_graph
{
	int					bd;
	unsigned	int		pop;
	unsigned	int		n_nodes;
	unsigned	int		n_links;
	t_arg				*l;
	char				*start;
	char				*end;
	t_node				*node;
}						t_graph;

/*
**		PROTOTYPES
*/

int						parse_file(t_graph *g, char *s);
int						parser(t_graph *g);

void					print_arg(t_arg *lst);

void					cleaner(t_graph *g);
void					remove_arg(t_arg *l);
void					remove_nodes(t_node *r);
void					remove_links(t_link *l);

int						add_node(t_graph *g, char **data);
t_node					*new_node(char **data);
t_node					*node_finder(t_node *node, char *name);

int						add_link(t_graph *g, char **location);
t_link					*link_finder(t_node *node, char *name);

int						is_com(char *s);
int						is_node(t_graph *g, char *s);
int						is_command(t_graph *g, char *s);
int						is_location(t_graph *g, char *s);

#endif
