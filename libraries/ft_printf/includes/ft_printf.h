/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:27:25 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/29 02:38:58 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"

# define PF_BUFF_SIZE 64

/*
**	Unix color codes
*/

# define BOLD "\033[1m\033[30m"
# define ULINE "\033[4m"
# define RESET "\033[0m"

/*
**	Bit operations
*/

# define BIT_ON(x, y) x |= y
# define BIT_OFF(x, y) x &= (~y)
# define BIT_TOGGLE(x, y) x ^= y

/*
**	Bit masks
*/

# define F_H			(1 << 0)
# define F_HH			(1 << 1)
# define F_L			(1 << 2)
# define F_LL			(1 << 3)
# define F_Z			(1 << 4)
# define F_J			(1 << 5)
# define F_REV			(1 << 6)
# define F_PREFIX		(1 << 7)
# define F_PLUS			(1 << 8)
# define F_MINUS		(1 << 9)
# define F_PAD_ZEROS	(1 << 10)
# define F_SPACE		(1 << 11)

typedef struct		s_pf
{
	va_list			arg;
	int				total_bytes;
	char			*master;
	char			buffer[PF_BUFF_SIZE];
	int				buffer_index;
	int				specifier;
	int				padding;
	int				precision;
	int				count_spaces;
	int				flags;
}					t_pf;

/*
**	-------------------------- ft_printf.c --------------------------
*/

int					ft_printf(const char *format, ...);

/*
**	--------------------------- buffer.c ----------------------------
*/

void				write_to_buffer(t_pf *pf, char *str, int bytes);
void				print_buffer(t_pf *pf, int bytes);

/*
**	--------------------------- parsing.c ---------------------------
*/

int					get_info(t_pf *pf);
int					get_mods(char *str, t_pf *pf, int i);
int					get_flags(t_pf *pf, int i);
int					get_padding(t_pf *pf, int i);
int					get_precision(t_pf *pf, int i);

/*
**	----------------- padding.c / padding_helpers.c -----------------
*/

void				null_padding(t_pf *pf);
void				handle_padding(t_pf *pf, char **str);
void				get_prefix(t_pf *pf);
void				handle_precision(char **str, t_pf *pf);
void				padding(t_pf *pf, int arglen);
void				get_space(t_pf *pf);

/*
**	------------------------ handle_ascii.c -------------------------
*/

void				handle_str(t_pf *pf);
void				handle_char(t_pf *pf);
void				handle_percent(t_pf *pf);
void				handle_ascii(t_pf *pf);

/*
**	------------------------ handle_wascii.c ------------------------
*/

size_t				wchar_size(unsigned int wide_char);
size_t				wstr_size(unsigned *s);
void				wide_char(t_pf *pf, unsigned int wide, int num_bytes);
void				handle_wide_char(t_pf *pf);
void				handle_wide_str(t_pf *pf);

/*
**	-------------- handle_signed.c / signed_helpers.c ---------------
*/

void				handle_signed(t_pf *pf);
char				*get_signed_data_type(t_pf *pf, int base, int upper);
void				signed_get_sign(t_pf *pf);
char				*signed_get_fill(char *str, t_pf *pf);
void				signed_get_precision(char *str, t_pf *pf);

/*
**	----------------------- handle_unsigned.c -----------------------
*/

char				*get_unsigned_data_type(t_pf *pf, int base, int upper);
void				handle_unsigned(t_pf *pf);

/*
**	---------------------------- utils.c ----------------------------
*/

int					flag_check(char c);
int					signed_specifier_check(char c);
int					unsigned_specifier_check(char c);
int					ascii_specifier_check(char c);
int					specifier_check(char c);

#endif
