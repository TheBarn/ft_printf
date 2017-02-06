/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 22:45:42 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	int i;

	i = 0;
	if (is_int_cv(value.conversion))
		i += get_int(&value, argp);
	if (value.conversion == 's' || value.conversion == 'c')
		i += get_str(&value, argp);
	if (value.conversion == 'S' || value.conversion == 'C')
		i += get_wstr(&value, argp);
	if (value.conversion == 'p')
		i += get_ptr(&value, argp);
	return (i);
}

int		ft_printf(const char *restrict format, ...)
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
