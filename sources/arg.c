/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:45 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/13 17:55:05 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

int			add_elem(t_graph *g, char **s, int ret)
{
	t_list	*l;

	if (!(l = ft_lstnew(NULL, 0)) || (ret = GNL(0, (char**)&l->content) < 0))
	{
		g->bd = ERROR;
		return (0);
	}
	ft_lstadd(&g->lst, l);
	*s = (char*)l->content;
	return (1);
}

void		remove_arg(t_list *lst)
{
	if (!lst)
		return ;
	remove_arg(lst->next);
	if (lst->content)
		free(lst->content);
	if (lst)
		free(lst);
}

void		print_arg(t_list *lst)
{
	if (!lst)
		return ;
	print_arg(lst->next);
	ft_printf("%s\n", lst->content);
}

void		remove_nodes(t_node *node)
{
	t_node	*tmp;

//	ft_printf("{red}in remove nodes\t%s\n{eoc}", node->name);
	if (!node)
	{
//		ft_printf("{red}!node\n{eoc}");
		return ;
	}
	if (node->next)
		remove_nodes(node->next);
	if (node->name)
		free(node->name);
//	if (r->links)
//		remove_links(r->links);
	tmp = node->prev;
	free(node);
	remove_nodes(tmp);
}

void		cleaner(t_graph *g)
{
//	ft_printf("in cleaner\n");
	if (g->lst)
		remove_arg(g->lst);
//	ft_printf("after remove arg\n");
	if (g->s)
		free(g->s);
//	ft_printf("free g->s\n");
	if (g->e)
		free(g->e);
//	ft_printf("free g->e\n");
	if (g->node)
		remove_nodes(g->node);
//	ft_printf("after remove nodes\n");
}
