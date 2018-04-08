/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:24:37 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 15:26:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *ws)
{
	size_t	wstrlen;

	wstrlen = 0;
	while (*ws != L'\0')
		wstrlen += ft_wcharlen(*ws++);
	return (wstrlen);
}
