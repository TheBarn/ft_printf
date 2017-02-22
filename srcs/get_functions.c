/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:28:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/22 14:54:44 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		get_char(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'u' || value->conversion == 'o' || value->conversion == 'x'|| value->conversion == 'X')
		value->val.uc = (unsigned char) va_arg(argp, int);
	else
		value->val.c = (char) va_arg(argp, int);
	i += print_char(*value);
	return (i);
}

int		get_int(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'u' || value->conversion == 'o' || value->conversion == 'x' || value->conversion == 'U' || value->conversion == 'O' || value->conversion == 'X')
		value->val.u = va_arg(argp, unsigned int);
	else
		value->val.nb = va_arg(argp, int);
	i += print_int(*value);
	return (i);
}

int		get_long(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'u' || value->conversion == 'o' || value->conversion == 'x' || value->conversion == 'U' || value->conversion == 'O' || value->conversion == 'X')
		value->val.U = va_arg(argp, unsigned long);
	else
		value->val.lg = va_arg(argp, long);
	i += print_long(*value);
	return (i);
}

int		get_llong(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'u' || value->conversion == 'o' || value->conversion == 'x' || value->conversion == 'U' || value->conversion == 'O' || value->conversion == 'X')
		value->val.UL = va_arg(argp, unsigned long long);
	else
		value->val.llg = va_arg(argp, long long);
	i += print_llong(*value);
	return (i);
}

int		get_size_t(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.z = va_arg(argp, size_t);
	i += print_size_t(*value);
	return (i);
}

int		get_imax(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (value->conversion == 'u' || value->conversion == 'o' || value->conversion == 'x' || value->conversion == 'U' || value->conversion == 'O' || value->conversion == 'X')
		value->val.uj = va_arg(argp, uintmax_t);
	else
		value->val.j = va_arg(argp, intmax_t);
	i += print_imax(*value);
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
		value->val.str[0] = (char)va_arg(argp, int);
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
	if (value->conversion == 'S' || value->conversion == 's')
	{
		value->val.wstr = va_arg(argp, wchar_t *);
		if (value->val.wstr == NULL)
			value->val.wstr = L"(null)";
	}
	if (value->conversion == 'C' || value->conversion == 'c')
	{
				value->val.wstr = (int *)malloc(2 * sizeof(int));
		value->val.wstr[0] = (int)va_arg(argp, int);
		value->val.wstr[1] = 0;
		if (value->val.wstr[0] == 0)
			i++;
	}
	i += print_wstr(*value);
	return (i);
}

int		get_ptr(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.ptr = (unsigned long) va_arg(argp, void *);
	i += print_ptr(*value);
	return (i);
}

int		get_no(t_value *value)
{
	int		i;

	i = 0;
	value->val.str = ft_strnew(2);
	value->val.str[0] = value->conversion;
	i += print_str(*value);
	return (i);
}
