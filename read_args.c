/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:54 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 16:34:46 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	analyze_arg(const char *format, t_value *value, int i)
{
	i = put_flags(format, value, i);
	i = put_width(format, value, i);
	i = put_precision(format, value, i);
	i = put_modifier(format, value, i);
	value->conversion = format[i];
}

int		read_arg(const char *format, t_value *value)
{
	int		i;
	int		toto;
	
	i = 0;
	toto = 0;
	while (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
	{
		if (format[i + 1] == '\0')
			break;
		if (format [i] == '%' && format[i + 1] == '%')
		{
			toto++;
			ft_putchar('%');
			i++;
		}
		i++;
	}
	analyze_arg(format, value, i);
	return (toto);
}
