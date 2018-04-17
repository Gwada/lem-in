/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:01:22 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 21:29:06 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		newstr[i] = (char)s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
