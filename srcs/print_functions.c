/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:45:52 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 22:48:04 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

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

void	print_wchar(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		c = str_to_hex(&str[i]);
		write(1, &c, 1);
		i += 2;
	}
}

int		print_wstr(t_value value)
{
	char	*str;
	int		i;

	i = 0;
	while (i < ft_wstrlen_t(value.val.wstr))
	{
		str = conversion(value.val.wstr[i], 16);
		str = binary_conversion(str);
		str = utf8_conversion(str);
		print_wchar(str);
		i++;
	}
	return (i);
}

int		print_ptr(t_value value)
{
	int		total;
	char	*str;

	str = ptr_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}
