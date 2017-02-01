/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 19:29:47 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_value(t_value value)
{
	printf("value is %d\nflags are %c%c%c%c%c\nwidth is %d\nprecision is %d\nmodifier is %c\nconversion is %c\n", value.val, (value.flags)[0], (value.flags)[1], (value.flags)[2], (value.flags)[3], (value.flags)[4], value.width, value.precision, value.modifier, value.conversion);
}

int		print_arg(t_value value)
{
	int		total;
	char	*str;

	total = 0;
	str = apply_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	return (total);
}

void	print_part(const char *format, int start, int end)
{
	char	*str;

	str = ft_strsub(format, start, end - start);
	ft_putstr(str);
	free(str);
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
		if (value.conversion == 'd' || value.conversion == 'D' || value.conversion == 'i' || value.conversion == 'o' || value.conversion == 'O' || value.conversion == 'u' || value.conversion == 'U' || value.conversion == 'x' || value.conversion == 'X')
			value.val = va_arg(argp, int);
		print_arg(value);
		i = next_arg(format, i);
	}
	print_part(format, k, i);
	va_end(argp);
	return (i);
}

int		main()
{
	int	lol;
	char *format = "%d\n";

	printf(format, 42);
	lol = ft_printf(format, 42);
	return (0);
}
