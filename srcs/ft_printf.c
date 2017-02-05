/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/05 19:39:00 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_arg(t_value value, t_arg arg)
{
	int		total;
	char	*str;
	int		i;

	i = 0;
	total = 0;
	if (value.conversion == 'S' || value.conversion == 'C')
		total = print_warg(value, arg.wstr);
	else
	{
		str = apply_conversion(value, arg);
		str = apply_precision(value, str);
		str = apply_flags(value, str);
		if (value.conversion == 'X')
			str = toupper_str(str);
		ft_putstr(str);
		total = ft_strlen(str);
	}
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
	if (value.conversion == 's')
	{
		arg.str = va_arg(argp, char*);
		if (arg.str == NULL)
			arg.str = "(null)";
	}
	if (value.conversion == 'S')
	{
		arg.wstr = va_arg(argp, wchar_t *);
		if (arg.wstr == NULL)
			arg.wstr = L"(null)";
	}
	if (value.conversion == 'C')
	{
		arg.wstr = (int *)malloc(2 * sizeof(int));
		arg.wstr[0] = (int) va_arg(argp, int);
		arg.wstr[1] = 0;
	}
	if (value.conversion == 'c')
	{
		arg.str = ft_strnew(2);
		arg.str[0] = (char) va_arg(argp, int);
		if (arg.str[0] == 0)
			i++;
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

//TODO modifiers

/*
int		main()
{
	int	lol;
	char *format = "a%Xb%Xc%Xd\n";
	char *str = NULL;
	char c = '!';
	int		tmp;
	int	i;

	lol = ft_printf("%c\n", 0);
	printf("value of ft_printf is %d\n", lol);
	lol = printf("%c\n", 0);
	printf("value of printf is %d\n", lol);
	return (0);
}*/
