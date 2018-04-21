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
//	ft_printf("in dijkstra\n");
	if (!end || !n || !n->links || !n->n_links)
		return (0);
	if (n == end)
		return (1);
//	ft_printf("node name = %s\tn->n_links = %d\n\n", n->name, n->n_links);
	while (n->links && n->links->prev)
		n->links = n->links->prev;
//	ft_printf("n->links->node->name = %s\n", n->links->node->name);
	n->bd |= VISITED;
	while (n->links)
	{
		if (n->links->node->bd & FREE)
			if (n->links->node->dis == -1 || n->dis + 1 < n->links->node->dis)
			{
//				ft_printf("{yellow}-----------------------------------------------------------{eoc}\n");//
//				ft_printf("n->links->node->name = %s\n\n", n->links->node->name);
//				ft_printf("before\nn->links->node->dis = %d\n", n->links->node->dis);//
//				if (n->links->node->from)////////////////////////////////////////
//					ft_printf("n->links->node->from->name = %s\n\n", n->links->node->from->name);//
//				else/////////////////////////////////////////////////////////////
//					ft_printf("no parent\n\n");////////////////////////////////////

				n->links->node->dis = n->dis + 1;

//				ft_printf("after\nn->links->node->dis = %d\n", n->links->node->dis);//

				n->links->node->from = n;

//				if (n->links->node->from)////////////////////////////////////////
//					ft_printf("n->links->node->from->name = %s\n", n->links->node->from->name);//
//				ft_printf("{yellow}-----------------------------------------------------------{eoc}\n\n\n\n");//
			}
		if (!n->links->next)
			break;
		n->links = n->links->next;
	}
	while (n->links && n->links->prev)
		n->links = n->links->prev;
	while (n->links)
	{
		if (n->links->node->bd & FREE)
			if (n->links->node->dis == -1 || n->dis + 1 <= n->links->node->dis)
			//	n->links->node->bd ^ VISITED && dijkstra(end, n->links->node, 0) ? ret = 1 : 0;
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
	int					test = 0;////////////////////////////////////////////////
	unsigned int		max_path;
	unsigned int		path;

	max_path = g->start->n_links < g->end->n_links ? g->start->n_links : g->end->n_links;
	path = 1;
	g->start->bd &= ~FREE;
	g->start->bd |= VISITED;
	g->start->dis = 0;
	while (test++ < 1 && path && g->n_path < g->pop && g->n_path < max_path)
	{
		first_step(g);
		path = dijkstra(g->end, g->start, 0);
		path ? ++g->n_path : 0;
	}
	t_node *n = g->end;
	while (n != g->start)
	{
		ft_printf("%s -> ", n->name);
		n = n->from;
		n == g->start ? ft_printf("%s -> ", n->name) : 0;
	}
	ft_printf("\n");
	if (!g->n_path)
	{
		ft_printf("{red}{underline}{bold}ERROR\n{runderline}");
		cleaner(g);
		ft_printf("{blue}\nEND\tPATH_FINDER{eoc}\n");////////////////////////////
		return (0);
	}
	ft_printf("{blue}{bold}\nEND\tPATH_FINDER{eoc}\n");//////////////////////////
	return (1);
}
