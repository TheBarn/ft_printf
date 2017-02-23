/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:00:46 by barnout           #+#    #+#             */
/*   Updated: 2017/02/23 13:45:51 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*remove_sign(char *str)
{
	char	*new;

	new = ft_strnew(ft_strlen(str) - 1);
	new = ft_strcat(new, &str[1]);
	free(str);
	return (new);
}

char	*swap_minus(char *str)
{
	char	*new;
	int		i;
	char	toto;
	int		len;

	i = 0;
	toto = 0;
	len = ft_strlen(str);
	new = ft_strnew(len);
	while (i < len)
	{
		if (str[len - 1 - i] != '-' && str[len - 1 - i] != 'x')
			new[len - 1 - i] = str[len - 1 - i];
		else
		{
			if (len - 2 - i >= 0 && str[len - 2 - i] == '0')
			{
				new[len - 1 - i] = '0';
				toto = str[len - 1 - i];
			}
			else
				new[len - 1 - i] = str[len - 1 - i];
		}
		i++;
	}
	if (toto)
	{
		i = 0;
		while (new[i] != '0' && i < len)
			i++;
		if (toto == 'x')
			i++;
		new[i] = toto;
	}
	free (str);
	return (new);
}

char	*add_padding(t_value value, char *str, char padding)
{
	int		diff;
	int		i;
	int		len;

	i = 0;
	if (value.conversion == 'S' || value.conversion == 'C')
		len = ft_strlen(str) / 2;
	else
		len = ft_strlen(str);
	if (value.conversion == 'c')
		len = 1;
	diff = value.width - len;
	if ((value.flags)[0] == '.')
	{
		if (is_int_cv(value.conversion) && value.precision != -1)
		{
			while (i < value.precision - (int)ft_strlen(str))
			{	
				str = add_to_the_left(str, padding);
				i++;
			}
			padding = ' ';
		}
		if (value.flags[1] == '+' || value.flags[2] == ' ')
			i++;
		while (i < diff)
		{
			str = add_to_the_left(str, padding);
			i++;
		}
	}
	if ((value.flags)[0] == '-')
	{
		while (i < diff)
		{
			str = add_to_the_right(str, padding);
			i++;
		}
	}
	return (str);
}

char	*apply_flags(t_value value, char *str)
{
	char	padding;
	int		len;

	padding = ' ';
	if (value.flags[4] == '#' && (value.conversion == 'o' || value.conversion == 'O') && (str == NULL || str[0] != '0'))
		str = add_to_the_left(str, '0');
	if (value.flags[4] == '#' && (value.conversion == 'x' || value.conversion == 'X') && str && ft_strcmp(str, "0") != 0)
	{
		str = add_to_the_left(str, 'x');
		str = add_to_the_left(str, '0');
	}
	if ((value.flags)[3] == '0' && (value.flags)[0] != '-')
		padding = '0';
	if (value.conversion == 'S' || value.conversion == 'C')
		len = ft_strlen(str) / 2;
	else
		len = ft_strlen(str);
	if (value.conversion == 'c')
		len = 1;
	if ((size_t) value.width > len)
		str = add_padding(value, str, padding);
	if ((value.flags)[1] == '+' && str && str[0] != '-' && (value.conversion == 'd' || value.conversion == 'D' || value.conversion == 'i'))
		str = add_to_the_left(str, '+');
	if ((value.flags)[2] == ' ' && (value.flags)[1] == '.' && str && str[0] != '-' && is_int_cv(value.conversion) && value.conversion != 'u' && value.conversion != 'o' && value.conversion != 'O' && value.conversion != 'x' && value.conversion != 'X')
		str = add_to_the_left(str, ' ');
	if (((value.flags)[3] == '0' || value.precision > -1) && is_str_cv(value.conversion) == 0)
		str = swap_minus(str);
	return (str);
}
