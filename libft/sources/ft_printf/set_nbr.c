/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:59:44 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 13:23:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_set_signed(t_data *data)
{
	long long	nbr;

	if (data->bd & LONGX2 || data->bd & INTMAX)
		nbr = (long long)va_arg(data->ap, long long);
	else if (data->bd & LONG)
		nbr = (long long)va_arg(data->ap, long);
	else if (data->bd & SIZE_T)
		nbr = (long long)va_arg(data->ap, ssize_t);
	else if (data->bd & SHORT)
		nbr = (long long)((short)va_arg(data->ap, int));
	else if (data->bd & SHORTX2)
		nbr = (long long)((char)va_arg(data->ap, int));
	else
		nbr = (long long)va_arg(data->ap, int);
	ft_itoa_p(data, nbr);
}

void			ft_set_base(t_data *data)
{
	ULX2I		n;

	if ((data->bd & LONGX2) || (data->bd & INTMAX) || (*data->ft == 'B'))
		n = (ULX2I)va_arg(data->ap, ULX2I);
	else if (data->bd & LONG)
		n = (ULX2I)va_arg(data->ap, ULI);
	else if (data->bd & SIZE_T)
		n = (ULX2I)va_arg(data->ap, size_t);
	else if (data->bd & SHORT)
		n = (ULX2I)((USI)va_arg(data->ap, unsigned int));
	else if (data->bd & SHORTX2)
		n = (ULX2I)((unsigned char)va_arg(data->ap, unsigned int));
	else
		n = (ULX2I)va_arg(data->ap, unsigned int);
	if (ft_strchr("bB", *data->ft))
		ft_put_bin_p(data, n);
	else
		ft_itoa_base_p(data, n, (ft_strchri_up("ou..x", *data->ft) + 4) << 1);
}

void			ft_itoa_p(t_data *d, long long n)
{
	char		num;
	ULX2I		tmp;

	d->c_len = 0;
	tmp = n < 0 ? -n : n;
	while (tmp && ++d->c_len)
		tmp /= 10;
	d->bd & ZERO && !(d->bd & PREC) ? d->prec = d->min_s : 0;
	d->bd & ZERO && d->bd & PREC && d->bd & PREC ? (d->bd &= ~ZERO) : 0;
	((n < 0 || d->bd & POS || d->bd & SPACE) && d->bd & ZERO) ? --d->prec : 0;
	d->prec > d->c_len ? d->c_len = d->prec : 0;
	(n < 0 || d->bd & POS || d->bd & SPACE) ? --d->min_s : 0;
	if ((d->filler = d->min_s - d->c_len) < 0)
		d->filler = 0;
	ft_filler(d, 0);
	d->bd & SPACE ? num = ' ' : 0;
	n < 0 ? num = '-' : 0;
	d->bd & POS && n >= 0 ? num = '+' : 0;
	if ((d->bd & SPACE) || (n < 0) || (d->bd & POS && n >= 0))
		ft_buffering(d, &num, 1);
	ft_itoa_buf(d, (tmp = n < 0 ? -n : n), 10, d->c_len);
	ft_filler(d, 1);
}

void			ft_itoa_base_p(t_data *d, ULX2I n, int b)
{
	int			ext;
	ULX2I		tmp;

	d->c_len = 0;
	tmp = n;
	while (tmp && ++d->c_len)
		tmp /= b;
	(d->bd & ZERO && !(d->bd & PREC)) ? d->prec = d->min_s : 0;
	d->bd & ZERO && d->bd & PREC ? (d->bd &= ~ZERO) : 0;
	ext = d->c_len >= d->prec ? 0 : 1;
	d->prec > d->c_len ? d->c_len = d->prec : 0;
	d->bd & DIESE && b == 8 && !ext ? --d->min_s : 0;
	d->bd & DIESE && b == 8 && !n && d->bd & PREC && !d->c_len ? ++d->c_len : 0;
	d->bd & DIESE && b == 16 && !(d->bd & ZERO) ? d->min_s -= 2 : 0;
	d->filler = d->min_s - d->c_len > 0 ? d->min_s - d->c_len : 0;
	ft_filler(d, 0);
	BASE8 ? ft_buffering(d, "0", 1) : 0;
	if (BASE16)
		ft_buffering(d, d->bd & MAJ ? "0X" : "0x", 2);
	ft_itoa_buf(d, n, b, d->c_len);
	ft_filler(d, 1);
}

void			ft_itoa_buf(t_data *d, ULX2I n, int b, int len)
{
	char		c;
	char		nbr[len];

	if (n && !(d->bd & POINTEUR) && d->bd & ZERO && d->bd & DIESE
			&& b == 16 && !(d->bd & LONGX2) && d->c_len > 3)
		d->c_len -= 2;
	c = 'a' - 10 - ((d->bd & MAJ) >> 1);
	len = d->c_len;
	while (len--)
	{
		nbr[len] = n % b + ((n % b < 10) ? '0' : c);
		n /= b;
	}
	d->bd & PREC && d->bd & ZERO ? *nbr = ' ' : 0;
	ft_buffering(d, nbr, d->c_len);
}
