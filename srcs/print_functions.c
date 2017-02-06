/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:45:52 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 21:57:57 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

int		print_int(t_value value)
{
	int		total;
	char	*str;

	str = apply_conversion(value);
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

	str = apply_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
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

	str = apply_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	return (total);
}
