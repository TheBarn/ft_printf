/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:14:09 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 22:43:50 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_conversion(t_value value)
{
	char	*str;

	if (value.conversion == 'd' || value.conversion == 'i')
		str = ft_itoa(value.val.nb);
	if (value.conversion == 'o')
		str = conversion(value.val.nb, 8);
	if (value.conversion == 'x' || value.conversion == 'X')
		str = conversion(value.val.nb, 16);
	if (value.conversion == 'u')
	{
		if (value.val.nb >= 0)
			str = ft_itoa(value.val.nb);
		if (value.val.nb < 0)
			str = u_neg_conversion(value.val.nb);
	}
	return (str);
}

char	*long_conversion(t_value value)
{
	char	*str;
	
	str = NULL;	
	if (value.conversion == 'D' || value.conversion == 'd' || value.conversion == 'i')
		str = ft_ltoa(value.val.lg);
	else if (value.conversion == 'O' || value.conversion == 'o')
		str = lconversion(value.val.lg, 8);
	else if (value.conversion == 'U' || value.conversion == 'u')
	{
		if (value.val.lg >= 0)
			str = ft_ltoa(value.val.lg);
		if (value.val.lg < 0)
			str = U_neg_conversion(value.val.lg);
	}
	else if (value.conversion == 'x' || value.conversion == 'X')
		str = lconversion(value.val.lg, 16);
	return (str);
}

char	*ptr_conversion(t_value value)
{
	char	*str;

	str = ft_strnew(2);
	if (value.val.ptr == 0)
	{
		str[0] = '0';
		str[1] = '0';
	}
	else
		address_conversion(value.val.ptr, &str);
	str = add_x(str);
	return (str);
}
