/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:53:47 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/16 18:21:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char			ft_nb_bit(t_data *data)
{
	if (data->bd & LONGX2 || data->bd & INTMAX)
		return ((char)sizeof(long long));
	if (data->bd & LONG || *data->ft == 'B')
		return ((char)sizeof(long));
	else if (data->bd & SIZE_T)
		return ((char)sizeof(size_t));
	else if (data->bd & SHORT)
		return ((char)sizeof(short));
	else if (data->bd & SHORTX2)
		return ((char)sizeof(char));
	return ((char)sizeof(int));
}

void					ft_put_bin_p(t_data *data, ULX2I n)
{
	char				i;
	long long unsigned	mask;

	i = -1;
	mask = ~(~0LLU >> 1) >> (-(ft_nb_bit(data) * 8));
	while (mask)
	{
		++i && !(i % 8) ? ft_buffering(data, " ", 1) : 0;
		ft_buffering(data, n & mask ? "1" : "0", 1);
		mask >>= 1;
	}
}
