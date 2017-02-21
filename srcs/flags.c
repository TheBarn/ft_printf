/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:00:46 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 22:44:50 by barnout          ###   ########.fr       */
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

char	*add_padding(t_value value, char *str, char padding)
{
	int		diff;
	int		i;

	i = 0;
	diff = value.width - ft_strlen(str);
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

	padding = ' ';
	if (value.flags[4] == '#' && (value.conversion == 'o' || value.conversion == 'O'))
		str = add_to_the_left(str, '0');
	if (value.flags[4] == '#' && (value.conversion == 'x' || value.conversion == 'X'))
	{
		str = add_to_the_left(str, 'x');
		str = add_to_the_left(str, '0');
	}
	if ((value.flags)[3] == '0' && (value.flags)[0] != '-')
		padding = '0';
	if ((size_t) value.width > ft_strlen(str))
		str = add_padding(value, str, padding);
	if ((value.flags)[1] == '+' && str[0] != '-' && (value.conversion == 'd' || value.conversion == 'D' || value.conversion == 'i'))
		str = add_to_the_left(str, '+');
	if ((value.flags)[2] == ' ' && (value.flags)[1] == '.' && str[0] != '-' && is_int_cv(value.conversion) && value.conversion != 'u')
		str = add_to_the_left(str, ' ');
	return (str);
}
