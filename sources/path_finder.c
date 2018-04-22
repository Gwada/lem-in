#include "lem-in.h"
#include "../libft/includes/ft_printf.h"

static	void			first_step(t_graph *g)
{
	while (g->node->prev)
		g->node = g->node->prev;
	while (g->node)
	{
		if (g->node->bd & FREE)
		{
			g->node->bd = FREE;
			g->node->dis = -1;
			g->node->path = -1;
		}
		if (!g->node->next)
			return ;
		g->node = g->node->next;
	}
}

static	void			next_init(t_node *n)
{
	while (n->links && n->links->prev)
		n->links = n->links->prev;
	while (n->links)
	{
		if (n->links->node->bd & FREE
		&& (n->links->node->dis == -1 || n->dis + 1 < n->links->node->dis))
		{
			n->links->node->dis = n->dis + 1;
			n->links->node->from = n;
		}
		if (!n->links->next)
			break;
		n->links = n->links->next;
	}
	while (n->links && n->links->prev)
		n->links = n->links->prev;
}

static	int				dijkstra(t_node *end, t_node *start, t_node *n, int ret)
{
	if (!end || !n || !n->links || !n->n_links)
		return (0);
	if (n == end)
		return (1);
	n->bd |= VISITED;
	next_init(n);
	while (n->links)
	{
		if (n->links->node->bd & FREE
		&& (n->links->node->dis == -1 || n->dis + 1 <= n->links->node->dis) &&
		(!(n == start && n->links->node == end
		&& end->from == start && start->bd & IN_PATH)))
			dijkstra(end, start, n->links->node, 0) ? ret = 1 : 0;
		if (!n->links->next)
			break;
		n->links = n->links->next;
	}
	return (ret);
}

static	void			path_marker(t_node *end, t_node *start, int path)
{
	t_node *node;

	node = end;
	while (node != start)
	{
		ft_printf("%s -> ", node->name);/////////////////////////////////////////
		if (node->from != start)
		{
			node->from->bd = IN_PATH;
			node->from->bd |= EMPTY;
			node->from->path = path;
		}
		node = node->from;
		start->bd |= IN_PATH;
		node == start ? ft_printf("%s\n", node->name) : 0;///////////////////////
	}
	end->bd = FREE;
}

int						path_finder(t_graph *g)
{
	ft_printf("\n{blue}{bold}IN\tPATH_FINDER{eoc}\n\n");/////////////////////////
	unsigned int		max_path;
	unsigned int		path;

	max_path = g->start->n_links < g->end->n_links ? g->start->n_links : g->end->n_links;
	path = 1;
	g->start->bd &= ~FREE;
	g->start->bd |= VISITED;
	g->start->dis = 0;
	while (path && g->n_path < g->pop && g->n_path < max_path)
	{
		first_step(g);
		if ((path = dijkstra(g->end, g->start, g->start, 0)))
			path_marker(g->end, g->start, g->n_path++);
	}
	if (!g->n_path)
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("{red}{underline}{bold}ERROR\n{runderline}");//////////////////
		cleaner(g);
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("{blue}{bold}\nEND\tPATH_FINDER{eoc}\n");//////////////////////////
	return (g->n_path);
}
