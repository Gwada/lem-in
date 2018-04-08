/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:02:51 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/15 12:12:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_p(t_data *data)
{
	int			len;
	char		*s;

	if (!(s = (char*)va_arg(data->ap, unsigned*)))
		s = "(null)";
	len = s ? ft_strlen(s) : 6;
	data->bd & PREC && data->prec < len ? len = data->prec : 0;
	data->filler = (data->min_s - len) > 0 ? data->min_s - len : 0;
	ft_filler(data, 0);
	ft_buffering(data, s, len);
	ft_filler(data, 1);
}

static void		filler_ws_calculate(t_data *d, wchar_t *ws, int *wlen)
{
	int			c_len;

	c_len = 0;
	while (*ws && (c_len = ft_wcharlen(*(ws++))))
	{
		if ((d->bd & PREC && *wlen + c_len <= d->prec) || !(d->bd & PREC))
			*wlen += c_len;
		else if (d->bd & PREC && *wlen + c_len > d->prec)
			break ;
	}
	d->bd & PREC && d->prec < *wlen ? *wlen = d->prec : 0;
	d->filler = (d->min_s - *wlen > 0) ? d->min_s - *wlen : 0;
}

void			ft_putwstr_p(t_data *d, int len, int wlen)
{
	int			c_len;
	wchar_t		*ws;

	c_len = 0;
	if (!(ws = va_arg(d->ap, wchar_t*)))
		ws = L"(null)";
	filler_ws_calculate(d, ws, &wlen);
	wlen = ft_wstrlen(ws);
	d->bd & PREC && d->prec < wlen ? wlen = d->prec : 0;
	d->bd = d->min_s > d->prec ? d->bd & ~PREC : d->bd | PREC;
	ft_filler(d, 0);
	while ((d->car = *ws++) && (wlen -= c_len) >= 0)
	{
		c_len = ft_wcharlen(d->car);
		c_len <= wlen ? ft_putwchar_p(d, d->car, wlen, c_len) : 0;
		len += c_len;
		if ((!c_len && wlen) || (!c_len && d->prec > len))
			return (ft_error(d, d->i_b + len));
	}
	ft_filler(d, 1);
}
