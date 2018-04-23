/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:56:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/23 16:12:24 by dlavaury         ###   ########.fr       */
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
# define COLOR			(1 << 10)
# define DEBUG			(1 << 11)
# define GRAPH			(1 << 12)
# define PATH			(1 << 13)

# define VISITED		(1 << 0)
# define EMPTY			(1 << 1)
# define FREE			(1 << 2)
# define IN_PATH		(1 << 3)

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
	int					dis;
	int					path;
	unsigned int		ant_name;
	int					n_links;
	struct s_link		*links;
	struct s_node		*from;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_graph
{
	int					bd;
	int					line;
	unsigned int		pop;
	unsigned int		n_path;
	unsigned int		n_paths;
	unsigned int		n_nodes;
	unsigned int		n_links;
	t_arg				*l;
	t_node				*start;
	t_node				*end;
	t_node				*node;
}						t_graph;

/*
**		PROTOTYPES
*/

int						parse_file(t_graph *g, char *s);
int						parser(t_graph *g);

int						error_display(t_graph *g, int error, char *s, int line);
int						get_arg(t_graph *g, int ret);
void					print_arg(t_arg *lst);

char					**make_tab(t_graph *g, size_t size);
int						free_tab(char **tab, size_t size, int i);

void					cleaner(t_graph *g);
void					remove_arg(t_arg *l);
void					remove_nodes(t_node *r);
void					remove_links(t_link *l);

int						add_node(t_graph *g, char **data);
t_node					*new_node(t_graph *g, char **data);
t_node					*node_finder(t_node *node, char *name);

int						add_link(t_graph *g, char *name_1, char *name_2);
t_link					*link_finder(t_node *node, char *name);

int						is_com(char *s);
int						is_node(t_graph *g, char *s);
int						is_command(t_graph *g, char *s);
int						is_location(t_graph *g, char *s, int i);

int						path_finder(t_graph *g);

void					moov(t_graph *g);
void					go_first_link(t_node *node);

#endif
