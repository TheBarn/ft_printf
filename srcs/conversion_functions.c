/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:14:09 by barnout           #+#    #+#             */
/*   Updated: 2017/02/22 14:30:48 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*char_conversion(t_value value)
{
	char	*str;

	if (value.conversion == 'd' || value.conversion == 'i')
		str = ft_itoa((int) value.val.c);
	if (value.conversion == 'o')
		str = conversion((unsigned int) value.val.uc, 8);
	if (value.conversion == 'x' || value.conversion == 'X')
		str = conversion((int) value.val.uc, 16);
	if (value.conversion == 'u')
		str = ft_utoa((unsigned int) value.val.uc);
	return (str);
}

char	*int_conversion(t_value value)
{
	char	*str;

	if (value.conversion == 'd' || value.conversion == 'i')
		str = ft_itoa(value.val.nb);
	if (value.conversion == 'o')
		str = conversion(value.val.u, 8);
	if (value.conversion == 'x' || value.conversion == 'X')
		str = conversion(value.val.u, 16);
	if (value.conversion == 'u')
		str = ft_utoa(value.val.u);
	return (str);
}

char	*long_conversion(t_value value)
{
	char	*str;
	
	str = NULL;	
	if (value.conversion == 'D' || value.conversion == 'd' || value.conversion == 'i')
		str = ft_imaxtoa(value.val.lg);
	else if (value.conversion == 'O' || value.conversion == 'o')
		str = jconversion(value.val.U, 8);
	else if (value.conversion == 'U' || value.conversion == 'u')
		str = ft_uimaxtoa(value.val.U);
	else if (value.conversion == 'x' || value.conversion == 'X')
		str = jconversion(value.val.U, 16);
	return (str);
}

char	*llong_conversion(t_value value)
{
	char	*str;
	
	str = NULL;	
	if (value.conversion == 'D' || value.conversion == 'd' || value.conversion == 'i')
		str = ft_imaxtoa(value.val.llg);
	else if (value.conversion == 'O' || value.conversion == 'o')
		str = jconversion(value.val.UL, 8);
	else if (value.conversion == 'U' || value.conversion == 'u')
		str = ft_uimaxtoa(value.val.UL);
	else if (value.conversion == 'x' || value.conversion == 'X')
		str = jconversion(value.val.UL, 16);
	return (str);
}

char	*size_t_conversion(t_value value)
{
	char	*str;
	
	str = NULL;	
	if (value.conversion == 'D' || value.conversion == 'd' || value.conversion == 'i')
		str = ft_uimaxtoa(value.val.z);
	else if (value.conversion == 'O' || value.conversion == 'o')
		str = jconversion(value.val.z, 8);
	else if (value.conversion == 'U' || value.conversion == 'u')
		str = ft_uimaxtoa(value.val.z);
	else if (value.conversion == 'x' || value.conversion == 'X')
		str = jconversion(value.val.z, 16);
	return (str);
}

char	*imax_conversion(t_value value)
{
	char	*str;
	
	str = NULL;	
	if (value.conversion == 'D' || value.conversion == 'd' || value.conversion == 'i')
		str = ft_imaxtoa(value.val.j);
	else if (value.conversion == 'O' || value.conversion == 'o')
		str = jconversion(value.val.uj, 8);
	else if (value.conversion == 'U' || value.conversion == 'u')
		str = ft_uimaxtoa(value.val.uj);
	else if (value.conversion == 'x' || value.conversion == 'X')
		str = jconversion(value.val.uj, 16);
	return (str);
}

char	*ptr_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (value.val.ptr == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
		address_conversion(value.val.ptr, &str);
	return (str);
}
