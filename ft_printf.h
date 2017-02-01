/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:55:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 19:29:50 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef	struct 	s_value
{
	int		val;
	char	flags[5];
	int		width;
	int		precision;
	char	modifier;
	char	conversion;
}				t_value;

char	*add_to_the_left(char *str, char c);
char	*add_to_the_right(char *str, char c);
char	*add_0_to_the_left(char *str, t_value value);
char	*apply_precision(t_value value, char *str);
char	*conversion(int nb, int base);
char	*u_long_conversion(int nb);
char	*apply_conversion(t_value value);
int		analyze_arg(const char *format, t_value *value, int i);
int		next_arg(const char *format, int i);
int		put_flags(const char *format, t_value *value, int i);
int		put_width(const char *format, t_value *value, int i);
int		put_precision(const char *format, t_value *value, int i);
int		put_modifier(const char *format, t_value *value, int i);
int		is_flag(char c);
void	init_flags(t_value *value);
char	*add_padding(t_value value, char *str, char padding);
char	*apply_flags(t_value value, char *str);
char	*remove_sign(char *str);

#endif
