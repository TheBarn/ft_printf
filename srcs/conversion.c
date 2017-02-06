/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:47:56 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 21:06:56 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*conversion(unsigned int nb, int base)
{
	char	*str;
	int		rem;

	str = NULL;
	rem = -1;
	if (nb == 0)
		return ("0");
	while (nb != 0)
	{
		rem = nb % base;
		nb /= base;
		if (rem < 10)
			str = add_to_the_left(str, '0' + rem);
		if (rem > 9)
			str = add_to_the_left(str, 'a' + rem - 10);
	}
	return (str);
}

char	*u_long_conversion(int nb)
{
	char	*str;
	char 	*str1;
	char	*str2;
	unsigned int	num;
	int	rem;
	int	q;
	
	num = (unsigned int) nb + 4294967295 + 1;
	rem = num % 100000;
	q = (num - rem) / 100000;
	str1 = ft_itoa(q);
	str2 = ft_itoa(rem);
	str = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	str = ft_strcat(str, str1);
	str = ft_strcat(str, str2);
	free(str1);
	free(str2);
	printf("nb is %d   num is %u   rem is %d    q is %d   str is %s\n", nb, num, rem, q, str);
	return (str);
}

void	address_conversion(unsigned long long ptr, char **str)
{
	char digit;

	digit = ptr % 16;

	if (ptr > 0)
		address_conversion(ptr / 16, str);
	if (digit < 10)
		*str = add_to_the_right(*str, '0' + digit);
	else
		*str = add_to_the_right(*str, 'a' + digit - 10);
}

char	*apply_conversion(t_value value)
{
	char	*str;

	if (value.conversion == 'd' || value.conversion == 'D' || value.conversion == 'i')
		str = ft_itoa(value.val.nb);
	if (value.conversion == 'o' || value.conversion == 'O')
		str = conversion(value.val.nb, 8);
	if (value.conversion == 'x' || value.conversion == 'X')
		str = conversion(value.val.nb, 16);
	if (value.conversion == 'u' || value.conversion == 'U')
	{
		if (value.val.nb >= 0)
			str = ft_itoa(value.val.nb);
		if (value.val.nb < 0)
			str = u_long_conversion(value.val.nb);
	}
	if (value.conversion == 's' || value.conversion == 'c')
		str = value.val.str;
	if (value.conversion == 'p')
	{
		str = ft_strnew(2);
		if (value.val.nb == 0)
		{
			str[0] = '0';
			str[1] = '0';
		}
		else
			address_conversion((unsigned long long) value.val.nb, &str);
		str = add_x(str);
	}
	return (str);
}
