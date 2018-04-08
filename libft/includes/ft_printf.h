/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:49:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/30 18:19:25 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	*** LIBRARIES ***
*/

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

/*
**	*** MASK BINARY DATA ***
*/

# define DIESE		(1 << 0)
# define SPACE		(1 << 1)
# define POS		(1 << 2)
# define NEG		(1 << 3)
# define ZERO		(1 << 4)
# define STAR		(1 << 5)
# define MAJ		(1 << 6)
# define SHORT		(1 << 7)
# define SHORTX2	(1 << 8)
# define LONG		(1 << 9)
# define LONGX2		(1 << 10)
# define INTMAX		(1 << 11)
# define SIZE_T		(1 << 12)
# define MIN_LEN	(1 << 13)
# define PREC		(1 << 14)
# define POINTEUR	(1 << 15)

/*
** *** TO REDUCE CODE ***
*/

# define ULX2I		unsigned long long int
# define ULI		unsigned long int
# define USI		unsigned short int
# define UC			unsigned char
# define BASE8		(n || d->bd & POINTEUR) && d->bd & DIESE && b == 8 && !ext
# define BASE16		(n || d->bd & POINTEUR) && d->bd & DIESE && b == 16

/*
** *** COLORS ***
*/

# define EOC		"\033[0m"
# define BOLD		"\033[1m"
# define RBOLD		"\033[21m"
# define DIM		"\033[2m"
# define RDIM		"\033[22m"
# define UNDERLINE	"\033[4m"
# define RUNDERLINE	"\033[24m"
# define BLINK		"\033[5m"
# define RBLINK		"\033[25m"
# define INVERTED	"\033[7m"
# define RINVERTED	"\033[27m"
# define HIDDEN		"\033[8m"
# define RHIDDEN	"\033[28m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/*
**	*** STRUCTURES ***
*/

typedef struct		s_data
{
	int				i;
	int				fd;
	int				prec;
	int				min_s;
	int				filler;
	int				i_b;
	int				i_f;
	int				error;
	char			*str;
	char			*ft;
	char			buf[BUFF_SIZE + 1];
	short			bd;
	va_list			ap;
	unsigned		car;
	int				c_len;
	int				len;
}					t_data;

/*
**	*** PROTOTYPES ***
*/

int					ft_atoi_p(const char *nptr);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, unsigned c);
int					ft_strchri_up(const char *s, unsigned c);
size_t				ft_strlen(const char *s);
int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_attribuate(t_data *data);
void				ft_flags_parser(t_data *data);
void				ft_precision_parser(t_data *data);
void				ft_len_mod_parser(t_data *data);
void				ft_put_type(t_data *data);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(wchar_t *ws);
void				ft_putwstr_p(t_data *data, int len, int wlen);
void				ft_putstr_p(t_data *data);
void				ft_set_car(t_data *data, wchar_t c);
void				ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b);
void				ft_set_signed(t_data *data);
void				ft_itoa_p(t_data *data, long long n);
void				ft_itoa_buf(t_data *data, ULX2I n, int b, int len);
void				ft_itoa_base_p(t_data *data, ULX2I n, int b);
void				ft_set_float(t_data *data, double n);
void				ft_set_adress(t_data *data);
void				ft_set_base(t_data *data);
void				ft_put_bin_p(t_data *data, ULX2I n);
void				ft_set_len(t_data *data);
void				ft_no_types(t_data *data);
void				ft_filler(t_data *data, char opt);
int					ft_join_clr(t_data *data);
void				ft_set_color(t_data *data, int len);
void				ft_buffering(t_data *data, const void *s, int len);
void				ft_error(t_data *data, int to_remove);

#endif
