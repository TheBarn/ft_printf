/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:45:52 by barnout           #+#    #+#             */
/*   Updated: 2017/02/22 16:02:15 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

int		print_char(t_value value)
{
	int		total;
	char	*str;
	
	str = char_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_int(t_value value)
{
	int		total;
	char	*str;

	str = int_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_long(t_value value)
{
	int		total;
	char	*str;

	str = long_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_llong(t_value value)
{
	int		total;
	char	*str;

	str = llong_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_size_t(t_value value)
{
	int		total;
	char	*str;

	str = size_t_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_imax(t_value value)
{
	int		total;
	char	*str;

	str = imax_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
		str = toupper_str(str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_str(t_value value)
{
	int		total;
	char	*str;

	str = value.val.str;
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}

int		print_wchar(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		c = str_to_hex(&str[i]);
		write(1, &c, 1);
		i += 2;
	}
	return (i / 2);
}

int		print_wstr(t_value value)
{
	char	*str;
	char 	*new;
	char	*big;
	int		i;
	int		toto;
	int		count_bytes;

	i = 0;
	toto = 0;
	str = NULL;
	new = conversion(value.val.wstr[i], 16);
	new = binary_conversion(new);
	new = utf8_conversion(new);
	count_bytes += ft_strlen(new);
	while (i < ft_wstrlen_t(value.val.wstr) && (value.precision == -1 || count_bytes < value.precision))
	{
		big = ft_strnew(ft_strlen(new) + ft_strlen(str));
		big = ft_strcat(big, str);
		big = ft_strcat(big, new);
		str = big;
		free(new);
		new = conversion(value.val.wstr[i], 16);
		new = binary_conversion(new);
		new = utf8_conversion(new);
		count_bytes += ft_strlen(new);
		i++;
	}
//	printf("str before precision %s\n", str);
//	str = apply_precision(value, str);
//	printf("str after precision %s\n", str);
	toto += print_wchar(str);
	return (toto);
}

int		print_ptr(t_value value)
{
	int		total;
	char	*str;
	char	*new;

	str = ptr_conversion(value);
	str = apply_precision(value, str);
	str = add_to_the_left(str, 'x');
	str = add_to_the_left(str, '0');
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}
