/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:52:02 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 21:42:28 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_flags(const char *format, t_value *value, int i)
{
	init_flags(value);
	while (is_flag(format[i]))
	{
		if (format[i] == '-')
			(value->flags)[0] = '-';
		if (format[i] == '+')
			(value->flags)[1] = '+';
		if (format[i] == ' ')
			(value->flags)[2] = ' ';
		if (format[i] == '0')
			(value->flags)[3] = '0';
		if (format[i] == '#')
			(value->flags)[4] = '#';
		i++;
	}
	return (i);
}

int		put_width(const char *format, t_value *value, int i)
{
	value->width = 0;
	if (format[i] > '0' && format[i] <= '9')
		value->width = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

int		put_precision(const char *format, t_value *value, int i)
{
	value->precision = -1;
	if (format[i] == '.')
	{
		i++;
		value->precision = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

int		put_modifier(const char *format, t_value *value, int i)
{
	value->modifier = '.';
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j' || format[i] == 'z')
	{
		value->modifier = format[i];
		i++;
		if (format[i] == 'h')
			value->modifier = 'H';
		if (format[i] == 'l')
			value->modifier = 'L';
	}
	return (i);
}
