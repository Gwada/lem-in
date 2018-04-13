/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:23 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/13 13:16:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		nbwords;
	int		nbletter;
	char	**words;

	if (!s)
		return (NULL);
	nbwords = ft_countwords(s, c, 0);
	if (!(words = (char**)malloc(sizeof(char*) * nbwords + 1)))
		return (NULL);
	words[nbwords] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		nbletter = 0;
		while (*s && *s != c)
		{
			nbletter++;
			s++;
		}
		if (nbletter)
			*words++ = ft_strsub(s - nbletter, 0, nbletter);
	}
	return (words - nbwords);
}
