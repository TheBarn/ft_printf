/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:54:12 by barnout           #+#    #+#             */
/*   Updated: 2017/02/22 15:40:53 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*toupper_str(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	while ((size_t) i < ft_strlen(str))
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = ft_toupper(str[i]);
		else
			new[i] = str[i];
		i++;
	}
	return (new);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		is_int_cv(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'o')
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
