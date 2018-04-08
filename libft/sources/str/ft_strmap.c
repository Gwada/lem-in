/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:41:12 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 15:21:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strdup(s)))
		return (NULL);
	while (s[++i])
		newstr[i] = f(s[i]);
	return (newstr);
}
