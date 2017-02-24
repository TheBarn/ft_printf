/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:44:11 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 13:09:14 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_to_the_right(char *str, char c)
{
	char	*new;
	int		lol;

	lol = ft_strlen(str) + 1;
	new = ft_strnew(ft_strlen(str) + 1);
	ft_strcat(new, str);
	new[ft_strlen(str)] = c;
	return (new);
}

char	*add_to_the_left(char *str, char c)
{
	char	*new;
	int		lol;

	lol = ft_strlen(str) + 1;
	new = ft_strnew(ft_strlen(str) + 1);
	new[0] = c;
	ft_strcat(new, str);
	return (new);
}

char	*add_0_to_the_left(char *str, t_value value)
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	nb = value.precision - len;
	while (i < nb)
	{
		str = add_to_the_left(str, '0');
		i++;
	}
	return (str);
}

char	*apply_precision(t_value value, char *str)
{
	char	*tmp;

	if (value.precision == 0 && !(IS_STR || IS_WSTR) && str && str[0] == '0')
		return (NULL);
	if (!is_str_cv(value.conversion))
		str = add_0_to_the_left(str, value);
	else if (value.precision >= 0 && (IS_S || IS_WS || IS_C) && \
								(size_t)value.precision < ft_strlen(str))
	{
		tmp = str;
		str = ft_strnew(value.precision + 1);
		str = ft_strncpy(str, tmp, value.precision);
	}
	return (str);
}
