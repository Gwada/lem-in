/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:04:33 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 15:16:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri(const char *s, unsigned c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (*s && *s != (char)c)
	{
		s++;
		i++;
	}
	return (*s == (char)c ? i : -1);
}
