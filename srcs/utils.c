/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:54:12 by barnout           #+#    #+#             */
/*   Updated: 2017/02/03 23:05:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_x(char *str)
{
	char 	*new;
	int		len;
	int		i;

	new = ft_strnew(ft_strlen(str) + 1);
	new[0] = '0';
	new[1] = 'x';
	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		new[2 + i] = str[1 + i];
		i++;
	}
	return (new);
}

int		is_int_cv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'o' || c == 'O')
		return (1);
	return (0);
}

int		is_str_cv(char c)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_cv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 's' || c == 'S' || c == 'c' || c == 'C' || c == 'p')
		return (1);
	return (0);
}

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
