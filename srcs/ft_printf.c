/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/03 23:05:25 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_arg(t_value value, t_arg arg)
{
	int		total;
	char	*str;
	int		i;

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
	total = ft_strlen(str);
	return (total);
}

int		ft_putstr_special(char *str)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i++;
			if (str[i + 1] == ' ')
			{
				i++;
				while (str[i] == ' ')
				{
					d++;
					i++;
				}
			}
			d++;
		}
		ft_putchar(str[i]);
		i++;
	}
	return (d);
}

int		print_part(const char *format, int start, int end)
{
	char	*str;
	int		i;

	str = ft_strsub(format, start, end - start);
	i = ft_strlen(str);
	i -= ft_putstr_special(str);
	free(str);
	return (i);
}

int		get_value(t_value value, va_list argp)
{
	t_arg arg;
	int i;
	
	i = 0;
	if (is_int_cv(value.conversion))
		arg.nb = va_arg(argp, int);
	if (value.conversion == 's' || value.conversion == 'S')
	{
		arg.str = va_arg(argp, char*);
		if (arg.str == NULL)
			arg.str = "(null)";
	}
	if (value.conversion == 'c' || value.conversion == 'C')
	{
		arg.str = ft_strnew(2);
		arg.str[0] = (char) va_arg(argp, int);
	}
	if (value.conversion == 'p')
		arg.ptr = va_arg(argp, void *);
	i += print_arg(value, arg);
	return (i);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list argp;
	int		i;
	int		k;
	int		len;
	int		toto;
	t_value value;

	i = 0;
	k = 0;
	toto = 0;
	len = ft_strlen(format);
	va_start(argp, format);
	i = next_arg(format, i);
	while (i < len)
	{
		toto += print_part(format, k, i);
		i = analyze_arg(format, &value, i, argp);
		k = i;
		if (is_cv(value.conversion))
			toto += get_value(value, argp);
		i = next_arg(format, i);
	}
	toto += print_part(format, k, i);
	va_end(argp);
	return (toto);
}

//TODO valeur de retour p modifiers

/*
int		main()
{
	int	lol;
	char *format = "%%\n";
	char *str = NULL;
	char c = '!';
	int		tmp;
	int	i;

	tmp = printf("!!!printf is : {% %}\n");
	lol = ft_printf("ft_printf is : {% %}\n");
	printf("valeur de printf est %d\n", tmp);
	printf("valeur de ft_printf est %d\n", lol);
	return (0);
}*/
