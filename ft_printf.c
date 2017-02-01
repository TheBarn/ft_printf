/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 22:33:45 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_arg(t_value value, t_arg arg)
{
	int		total;
	char	*str;
	int		i;

	total = 0;
	i = 0;
	str = apply_conversion(value, arg);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X' || value.conversion == 'S' || value.conversion == 'C')
		while (i < ft_strlen(str))
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	ft_putstr(str);
	return (total);
}

void	ft_putstr_special(char *str)
{
	int		i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		ft_putchar(str[i]);
		i++;
	}
}

void	print_part(const char *format, int start, int end)
{
	char	*str;

	str = ft_strsub(format, start, end - start);
	ft_putstr_special(str);
	free(str);
}

void	get_value(t_value value, va_list argp)
{
	t_arg arg;

	if (is_int_cv(value.conversion))
		arg.nb = va_arg(argp, int);
	if (value.conversion == 's' || value.conversion == 'S')
		arg.str = va_arg(argp, char*);
	if (value.conversion == 'c' || value.conversion == 'C')
	{
		arg.str = ft_strnew(2);
		arg.str[0] = (char) va_arg(argp, int);
	}
	print_arg(value, arg);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list argp;
	int		i;
	int		k;
	int		len;
	t_value value;

	i = 0;
	k = 0;
	len = ft_strlen(format);
	va_start(argp, format);
	i = next_arg(format, i);
	while (i < len)
	{
		print_part(format, k, i);
		i = analyze_arg(format, &value, i);
		k = i;
		get_value(value, argp);
		i = next_arg(format, i);
	}
	print_part(format, k, i);
	va_end(argp);
	return (i);
}

//TODO valeur de retour p modifiers

int		main()
{
	int	lol;
	char *format = "%+#20.10d\n";
	char *str = "hello world!";
	char c = '!';

	printf(format, 42);
	lol = ft_printf(format, 42);
	return (0);
}
