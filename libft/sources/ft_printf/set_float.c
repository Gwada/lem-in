/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:55:52 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 18:29:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_dtoa_buf(t_data *d, double n, long n2, int len)
{
	int			c_n;
	char		nb[len + 1];

	len = d->c_len - d->prec - 1;
	c_n = d->c_len - len - 1;
	while (c_n)
	{
		nb[len + c_n--] = n2 % 10 + '0';
		n2 /= 10;
	}
	d->prec > 0 ? nb[len] = '.' : 0;
	n2 = (long)(n < 0 ? -n : n);
	while (c_n < len)
	{
		nb[len - ++c_n] = n2 % 10 + '0';
		n2 /= 10;
	}
	((d->bd & PREC && d->bd & ZERO) || (d->bd & SPACE)) ? *nb = ' ' : 0;
	n < 0 ? *nb = '-' : 0;
	(d->bd & POS && n >= 0) ? *nb = '+' : 0;
	ft_buffering(d, nb, d->c_len);
}

void			ft_set_float(t_data *data, double n)
{
	int			len;
	long		n2;
	long		tmp;
	double		dcl;

	data->bd & ZERO ? data->prec = data->min_s : 0;
	!(data->bd & PREC) ? data->prec = 6 : 0;
	len = data->prec > 0 ? 1 : 0;
	tmp = n < 0 ? -n : n;
	while (tmp && ++len)
		tmp /= 10;
	data->bd & ZERO ? data->prec = data->min_s : 0;
	data->c_len = data->prec + len + (n < 0 ? 1 : 0);
	data->filler = data->c_len > data->min_s ? 0 : data->min_s - data->c_len;
	dcl = (n < 0.0f) ? (-n - (long)-n) : (n - (long)n);
	tmp = (long)data->prec;
	while (tmp-- + 1)
		dcl *= 10;
	dcl = ((long)dcl % 10 > 4) ? (dcl / 10 + 1) : dcl / 10;
	n2 = (int)dcl;
	ft_filler(data, 0);
	ft_dtoa_buf(data, n, n2, data->c_len);
	ft_filler(data, 1);
}
