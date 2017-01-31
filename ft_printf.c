/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/01/31 22:56:41 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	init_flags(t_value *value)
{
	(value->flags)[0] = '.';
	(value->flags)[1] = '.';
	(value->flags)[2] = '.';
	(value->flags)[3] = '.';
	(value->flags)[4] = '.';
}

int		put_flags(const char *format, t_value *value, int i)
{
	i++;
	init_flags(value);
	while (is_flag(format[i]))
	{
		if (format[i] == '-')
			(value->flags)[0] = '-';
		if (format[i] == '+')
			(value->flags)[1] = '+';
		if (format[i] == ' ')
			(value->flags)[2] = ' ';
		if (format[i] == '0')
			(value->flags)[3] = '0';
		if (format[i] == '#')
			(value->flags)[4] = '#';
		i++;
	}
	return (i);
}

int		put_width(const char *format, t_value *value, int i)
{
	value->width = 0;
	if (format[i] > '0' && format[i] <= '9')
		value->width = ft_atoi(&format[i]);
	while (format[i] > '0' && format[i] <= '9')
		i++;
	return (i);
}

int		put_precision(const char *format, t_value *value, int i)
{
	value->precision = -1;
	if (format[i] == '.')
	{
		i++;
		value->precision = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

int		put_modifier(const char *format, t_value *value, int i)
{
	value->modifier = '.';
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j' || format[i] == 'z')
	{
		value->modifier = format[i];
		i++;
		if (format[i] == 'h')
			value->modifier = 'H';
		if (format[i] == 'l')
			value->modifier = 'L';
	}
	return (i);
}

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

char	*add_to_the_left(char *str, char c)
{
	char *new;
	int lol;

	lol = ft_strlen(str) + 1;
	new = ft_strnew(ft_strlen(str) + 1);
	new[0] = c;
	ft_strcat(new, str);
	free(str);
	return (new);
}

char	*conversion(int nb, int base)
{
	char	*str;
	int		rem;

	str = NULL;
	rem = -1;
	if (nb == 0)
		return ("0");
	while (rem != 0)
	{
		rem = nb % base;
		nb /= base;
		if (rem < 10 && rem != 0)
			str = add_to_the_left(str, '0' + rem);
		if (rem > 9)
			str = add_to_the_left(str, 'a' + rem - 10);
	}
	return (str);
}

char	*apply_conversion(t_value *value)
{
	char	*str;

	if (value->conversion == 'd' || value->conversion == 'D' || value->conversion == 'i')
		str = ft_itoa(value->val);
	if (value->conversion == 'o' || value->conversion == 'O')
		str = conversion(value->val, 8);
	if (value->conversion == 'x' || value->conversion == 'X')
		str = conversion(value->val, 16);
	if (value->conversion == 'u' || value->conversion == 'U')
	{
		if (value->val >= 0)
			str = ft_itoa(value->val);
		if (value->val < 0)
		{
			str = ft_long_itoa(value->val + 4294967295 + 1);
			printf("youhou %s\n", str);
			//TODO couper en deux et puis zou
		}
	}
	return (str);
}

char	*add_0_to_the_left(char *str, t_value *value)
{
	int		i;
	int		nb;

	i = 0;
	nb = value->precision - ft_strlen(str);
	while (i < nb)
	{
		str = add_to_the_left(str, '0');
		i++;
	}
	return (str);
}

char	*apply_precision(t_value *value, char *str)
{
	if (value->precision >= 0 && (value->conversion == 'd' || value->conversion == 'D' || value->conversion == 'i' || value->conversion == 'o' || value->conversion == 'O' || value->conversion == 'u' || value->conversion == 'U' || value->conversion == 'x' || value->conversion == 'X'))
		str = add_0_to_the_left(str, value);
	return (str);
}

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
	return (total);
}

int		main()
{
	int	lol;

	lol = ft_printf("%u", -42);
	return (0);
}
