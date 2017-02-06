/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:28:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 21:57:09 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_int(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.nb = va_arg(argp, int);
	i += print_int(*value);
	return (i);
}

int		get_str(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 's')
	{
		value->val.str = va_arg(argp, char *);
		if (value->val.str == NULL)
			value->val.str = "(null)";
	}
	if (value->conversion == 'c')
	{
		value->val.str = ft_strnew(2);
		value->val.str[0] = (char) va_arg(argp, int);
		if (value->val.str[0] == 0)
			i++;
	}
	i += print_str(*value);
	return (i);
}

int		get_wstr(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'S')
	{
		value->val.wstr = va_arg(argp, wchar_t *);
		if (value->val.wstr == NULL)
			value->val.wstr = L"(null)";
	}
	if (value->conversion == 'C')
	{
		value->val.wstr = (int *)malloc(2 * sizeof(int));
		value->val.wstr[0] = (int) va_arg(argp, int);
		value->val.wstr[1] = 0;
	}
	i += print_wstr(*value);
	return (i);
}

int		get_ptr(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.ptr = va_arg(argp, void *);
	i += print_ptr(*value);
	return (i);
}
