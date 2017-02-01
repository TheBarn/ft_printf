/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:54 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 20:34:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		analyze_arg(const char *format, t_value *value, int i)
{
	i++;
	i = put_flags(format, value, i);
	i = put_width(format, value, i);
	i = put_precision(format, value, i);
	i = put_modifier(format, value, i);
	value->conversion = format[i];
	return (i + 1);
}

int		next_arg(const char *format, int i)
{
	if (format == NULL || format[0] == '\0')
		return (0);
	while (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
	{
		if (format[i] == '\0')
			return (i);
		if (format[i + 1] == '\0')
			return (i + 1);
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		i++;
	}
	return (i);
}
