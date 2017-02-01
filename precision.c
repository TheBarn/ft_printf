/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:44:11 by barnout           #+#    #+#             */
/*   Updated: 2017/02/01 18:14:45 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_to_the_right(char *str, char c)
{
	char *new;
	int lol;

	lol = ft_strlen(str) + 1;
	new = ft_strnew(ft_strlen(str) + 1);
	ft_strcat(new, str);
	new[ft_strlen(str)] = c;
	free(str);
	return (new);
}

char	*add_to_the_left(char *str, char c)
{
	char *new;
	int lol;

	lol = ft_strlen(str) + 1;
	new = ft_strnew(ft_strlen(str) + 1);
	new[0] = c;
	ft_strcat(new, str);
	free(str);
	return (new);
}

char	*add_0_to_the_left(char *str, t_value value)
{
	int		i;
	int		nb;

	i = 0;
	nb = value.precision - ft_strlen(str);
	while (i < nb)
	{
		str = add_to_the_left(str, '0');
		i++;
	}
	return (str);
}


char	*apply_precision(t_value value, char *str)
{
	if (value.precision >= 0 && (value.conversion == 'd' || value.conversion == 'D' || value.conversion == 'i' || value.conversion == 'o' || value.conversion == 'O' || value.conversion == 'u' || value.conversion == 'U' || value.conversion == 'x' || value.conversion == 'X'))
		str = add_0_to_the_left(str, value);
	return (str);
}
