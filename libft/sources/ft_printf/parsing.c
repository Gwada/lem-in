/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:53:05 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 13:17:40 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_star_gestion(t_data *data)
{
	data->bd &= ~STAR;
	if ((data->i_f = (int)va_arg(data->ap, int)) < 0)
	{
		data->bd |= NEG;
		data->i_f *= -1;
	}
	else
		data->bd &= ~NEG;
	if (!(data->bd & PREC))
		data->min_s = data->i_f;
	else
	{
		data->prec = data->bd & NEG ? 0 : data->i_f;
		data->bd = data->i_f ? data->bd & ~PREC : data->bd | PREC;
	}
}

void		ft_flags_parser(t_data *data)
{
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
		data->bd |= 1 << data->i_f;
	if (data->bd & NEG && !(data->bd & STAR))
		data->bd &= ~ZERO;
	if (data->bd & POS)
		data->bd &= ~SPACE;
	if (data->bd & STAR)
		ft_star_gestion(data);
}

void		ft_precision_parser(t_data *data)
{
	int		n1;
	int		n2;

	n1 = 1;
	n2 = 0;
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		n2 = ft_atoi_p(data->ft);
		data->min_s = n2 > n1 ? n2 : n1;
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
	}
	if (*data->ft == '.')
	{
		++data->ft;
		n2 = ft_atoi_p(data->ft);
		data->prec = n2 > 0 ? n2 : 0;
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->bd |= PREC;
	}
}

void		ft_len_mod_parser(t_data *data)
{
	while (42)
	{
		if (*data->ft == 'l')
			data->bd |= (data->ft[1] == 'l' && ++data->ft) ? LONGX2 : LONG;
		else if (*data->ft == 'h')
			data->bd |= (data->ft[1] == 'h' && ++data->ft) ? SHORTX2 : SHORT;
		else if (*data->ft == 'j')
			data->bd |= INTMAX;
		else if (*data->ft == 'z')
			data->bd |= SIZE_T;
		else if (*data->ft == 'q')
			data->bd |= LONGX2;
		else
			break ;
		++data->ft;
	}
}

void		ft_put_type(t_data *d)
{
	if (ft_strchr("sS", *d->ft))
		d->bd & LONG ? ft_putwstr_p(d, 0, 0) : ft_putstr_p(d);
	else if (ft_strchr("cC", *d->ft))
		ft_set_car(d, va_arg(d->ap, wchar_t));
	else if (*d->ft == 'n')
		ft_set_len(d);
	else if (ft_strchr("dDi", *d->ft))
		ft_set_signed(d);
	else if (*d->ft == 'p')
		ft_set_adress(d);
	else if (ft_strchr("fF", *d->ft))
		ft_set_float(d, (double)va_arg(d->ap, double));
	else if (ft_strchr("bBoOuUxX", *d->ft))
		ft_set_base(d);
	else
		ft_no_types(d);
}
