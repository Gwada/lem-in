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
		}
		if (!g->node->next)
			return ;
		g->node = g->node->next;
	}
}

static	int				dijkstra(t_node *end, t_node *n, int ret)
{
	if (!end || !n || !n->links || !n->n_links)
		return (0);
	if (n == end)
		return (1);
	while (n->links && n->links->prev)
		n->links = n->links->prev;
	n->bd |= VISITED;
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
	while (n->links)
	{
		if (n->links->node->bd & FREE
		&& (n->links->node->dis == -1 || n->dis + 1 <= n->links->node->dis))
			dijkstra(end, n->links->node, 0) ? ret = 1 : 0;
		if (!n->links->next)
			break;
		n->links = n->links->next;
	}
	return (ret);
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
		path = dijkstra(g->end, g->start, 0);
		path ? ++g->n_path : 0;
	}
	t_node *n = g->end;//////////////////////////////////////////////////////////
	while (n != g->start)////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("%s -> ", n->name);////////////////////////////////////////////
		n = n->from;/////////////////////////////////////////////////////////////
		n == g->start ? ft_printf("%s -> ", n->name) : 0;////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("\n");/////////////////////////////////////////////////////////////
	if (!g->n_path)
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("{red}{underline}{bold}ERROR\n{runderline}");//////////////////
		cleaner(g);
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("{blue}{bold}\nEND\tPATH_FINDER{eoc}\n");//////////////////////////
	return (!g->n_path);
}
