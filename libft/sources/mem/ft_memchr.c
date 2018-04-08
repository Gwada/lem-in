/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:59:24 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 15:58:13 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	s1;
	char	*str;

	i = -1;
	s1 = (char)c;
	str = (char*)s;
	while (++i < n)
		if (str[i] == s1)
			return (str + i);
	return (NULL);
}
