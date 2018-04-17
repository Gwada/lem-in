/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:12:58 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 16:19:14 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_cmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n--)
	{
		++s1;
		++s2;
	}
	return (n ? 0 : 1);
}

static void	ft_set_color_part2(t_data *d, int *len)
{
	if (flag_cmp(d->ft, "{blink}", 7) && (*len = 7))
		ft_buffering(d, BLINK, 4);
	if (flag_cmp(d->ft, "{dim}", 5) && (*len = 5))
		ft_buffering(d, DIM, 4);
	if (flag_cmp(d->ft, "{inverted}", 10) && (*len = 10))
		ft_buffering(d, INVERTED, 4);
	if (flag_cmp(d->ft, "{hidden}", 8) && (*len = 8))
		ft_buffering(d, HIDDEN, 4);
	if (flag_cmp(d->ft, "{rbold}", 7) && (*len = 7))
		ft_buffering(d, RBOLD, 5);
	if (flag_cmp(d->ft, "{rdim}", 7) && (*len = 7))
		ft_buffering(d, RDIM, 5);
	if (flag_cmp(d->ft, "{runderline}", 12) && (*len = 12))
		ft_buffering(d, RUNDERLINE, 5);
	if (flag_cmp(d->ft, "{rblink}", 8) && (*len = 8))
		ft_buffering(d, RBLINK, 5);
	if (flag_cmp(d->ft, "{rinverted}", 11) && (*len = 11))
		ft_buffering(d, RINVERTED, 5);
	if (flag_cmp(d->ft, "{rhidden}", 9) && (*len = 11))
		ft_buffering(d, RHIDDEN, 5);
}

void		ft_set_color(t_data *d, int len)
{
	if (flag_cmp(d->ft, "{blue}", 6) && (len = 6))
		ft_buffering(d, BLUE, 5);
	else if (flag_cmp(d->ft, "{cyan}", 6) && (len = 6))
		ft_buffering(d, CYAN, 5);
	else if (flag_cmp(d->ft, "{eoc}", 5) && (len = 5))
		ft_buffering(d, EOC, 4);
	else if (flag_cmp(d->ft, "{green}", 7) && (len = 7))
		ft_buffering(d, GREEN, 5);
	else if (flag_cmp(d->ft, "{red}", 5) && (len = 5))
		ft_buffering(d, RED, 5);
	else if (flag_cmp(d->ft, "{yellow}", 8) && (len = 8))
		ft_buffering(d, YELLOW, 5);
	else if (flag_cmp(d->ft, "{black}", 7) && (len = 7))
		ft_buffering(d, BLACK, 5);
	else if (flag_cmp(d->ft, "{magenta}", 9) && (len = 9))
		ft_buffering(d, MAGENTA, 5);
	else if (flag_cmp(d->ft, "{white}", 7) && (len = 7))
		ft_buffering(d, WHITE, 5);
	else if (flag_cmp(d->ft, "{bold}", 6) && (len = 6))
		ft_buffering(d, BOLD, 4);
	else if (flag_cmp(d->ft, "{underline}", 11) && (len = 11))
		ft_buffering(d, UNDERLINE, 4);
	else
		ft_set_color_part2(d, &len);
	len ? (d->ft += len) : ft_buffering(d, d->ft++, 1);
}
