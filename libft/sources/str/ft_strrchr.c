/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:49 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 12:59:42 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!c)
		return ((char*)(s + ft_strlen(s)));
	i = ft_strlen(s);
	while (i && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char*)(s + i));
	return (NULL);
}
