/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:40:05 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 15:23:27 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strdup(s)))
		return (NULL);
	while (s[++i])
		newstr[i] = f(i, s[i]);
	return (newstr);
}
