/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 16:52:13 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_value(t_value value)
{
	printf("value is %d\nflags are %c%c%c%c%c\nwidth is %d\nprecision is %d\nmodifier is %c\nconversion is %c\n", value.val, (value.flags)[0], (value.flags)[1], (value.flags)[2], (value.flags)[3], (value.flags)[4], value.width, value.precision, value.modifier, value.conversion);
}

int		ft_printf(const char *format, int nb)
{
	int		total;
	t_value	value;
	char	*str;

	total = 0;
	value.val = nb;
	total += read_arg(format, &value);
	print_value(value);
	str = apply_conversion(&value);
	printf("value after conversion is %s\n", str);
	str = apply_precision(&value, str);
	printf("value after precision is %s\n", str);
	str = apply_flags(&value, str);
	printf("value after flags is %s\n", str);
	return (total);
}

int		main()
{
	int	lol;

	printf("la valeur de printf est : %+-10d\n\n", 42);
	lol = ft_printf("%+-10d", 42);
	return (0);
}
