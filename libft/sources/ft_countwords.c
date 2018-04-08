/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:10:13 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 14:38:32 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *s, const char c, size_t state)
{
	if (!s || !*s)
		return (0);
	if (*s != c)
	{
		if (!state)
			return (ft_countwords(s + 1, c, 1) + 1);
		return (ft_countwords(s + 1, c, 1));
	}
	return (ft_countwords(s + 1, c, 0));
}
