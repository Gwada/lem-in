/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_car.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:54:42 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/25 10:54:29 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b)
{
	char	wc[4];

	if (n_b <= size && (int)n_b <= (int)MB_CUR_MAX)
	{
		if (n_b == 1)
			wc[0] = (char)c;
		else
		{
			if (n_b == 2)
				wc[0] = ((c & (0x1F << 6)) >> 6) | 0xC0;
			else
			{
				if (n_b == 3)
					wc[0] = ((c >> 12) & 0x0F) | 0xE0;
				else
				{
					wc[0] = ((c >> 18) & 7) | 0xF0;
					wc[1] = ((c >> 12) & 0x3F) | 0x80;
				}
				wc[n_b - 2] = ((c >> 6) & 0x3F) | 0x80;
			}
			wc[n_b - 1] = (c & 0x3F) | 0x80;
		}
		ft_buffering(data, wc, n_b);
	}
}

void		ft_set_car(t_data *data, wchar_t c)
{
	data->c_len = (data->bd & LONG || data->bd & LONGX2) ? ft_wcharlen(c) : 1;
	if ((!data->c_len || c < 0) && data->bd & LONG)
		return (ft_error(data, data->i));
	if ((data->filler = data->min_s - data->c_len) < 0)
		data->filler = 0;
	ft_filler(data, 0);
	ft_putwchar_p(data, c, data->c_len, data->c_len);
	ft_filler(data, 1);
}
