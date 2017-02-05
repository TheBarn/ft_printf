/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:55:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/05 18:46:48 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "../libft/libft.h"

typedef	struct 	s_value
{
	char	flags[5];
	int		width;
	int		precision;
	char	modifier;
	char	conversion;
}				t_value;

typedef struct	s_arg
{
	int		nb;
	char	*str;
	void	*ptr;
	wchar_t	*wstr;
}				t_arg;

char	*add_to_the_left(char *str, char c);
char	*add_to_the_right(char *str, char c);
char	*add_0_to_the_left(char *str, t_value value);
char	*apply_precision(t_value value, char *str);
char	*conversion(unsigned int nb, int base);
char	*apply_conversion(t_value value, t_arg arg);
int		analyze_arg(const char *format, t_value *value, int i, va_list argp);
int		next_arg(const char *format, int i);
int		put_flags(const char *format, t_value *value, int i);
int		put_width(const char *format, t_value *value, int i, va_list argp);
int		put_precision(const char *format, t_value *value, int i, va_list argp);
int		put_modifier(const char *format, t_value *value, int i);
int		is_flag(char c);
void	init_flags(t_value *value);
char	*add_padding(t_value value, char *str, char padding);
char	*apply_flags(t_value value, char *str);
char	*remove_sign(char *str);
int		is_int_cv(char c);
int		is_str_cv(char c);
char	*add_x(char *str);
int		is_cv(char c);
int		print_warg(t_value, wchar_t *wstr);
char	*toupper_str(char *str);

#endif
