/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:53:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 09:53:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_set_adress(t_data *d)
{
	void	*ptr;

	ptr = va_arg(d->ap, void *);
	d->bd &= ~DIESE;
	d->min_s -= d->bd & ZERO ? 2 : 0;
	d->filler = d->c_len > d->min_s - 3 ? 0 : d->min_s - d->c_len - 3;
	d->bd |= DIESE;
	d->bd |= POINTEUR;
	ft_itoa_base_p(d, (long long)ptr, 16);
}
