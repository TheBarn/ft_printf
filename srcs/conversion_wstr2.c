/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wstr2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:09:32 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 11:11:30 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*binary_conversion(char *hex)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	i = 0;
	while (hex != NULL && hex[i] != '\0')
	{
		tmp = str;
		str = ft_strnew(ft_strlen(str) + 4);
		str = ft_strcat(str, tmp);
		free(tmp);
		str = ft_strcat(str, hex_to_binary(hex[i]));
		i++;
	}
	return (str);
}

char			*utf8_conversion(char *small)
{
	char	*big;
	char	*new;
	int		bits;
	int		i;

	small = justify_zeros(small);
	bits = ft_strlen(small);
	if (bits > 0 && bits < 8)
		big = "0xxxxxxx";
	if (bits > 7 && bits < 12)
		big = "110xxxxx10xxxxxx";
	if (bits > 11 && bits < 17)
		big = "1110xxxx10xxxxxx10xxxxxx";
	if (bits > 16 && bits < 22)
		big = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	big = fill_bits(big, small);
	new = NULL;
	i = 0;
	while (big[i] != '\0')
	{
		new = add_to_the_right(new, binary_to_hex(&big[i]));
		i += 4;
	}
	free(big);
	return (new);
}

static void		str_to_hex2(char *str, unsigned char *c)
{
	if (str[1] == 'a')
		*c += 10;
	else if (str[1] == 'b')
		*c += 11;
	else if (str[1] == 'c')
		*c += 12;
	else if (str[1] == 'd')
		*c += 13;
	else if (str[1] == 'e')
		*c += 14;
	else if (str[1] == 'f')
		*c += 15;
	else
		*c += (str[1] - '0');
}

unsigned char	str_to_hex(char *str)
{
	unsigned char	c;

	c = 0;
	if (str[0] == 'a')
		c += 16 * 10;
	else if (str[0] == 'b')
		c += 16 * 11;
	else if (str[0] == 'c')
		c += 16 * 12;
	else if (str[0] == 'd')
		c += 16 * 13;
	else if (str[0] == 'e')
		c += 16 * 14;
	else if (str[0] == 'f')
		c += 16 * 15;
	else
		c += 16 * (str[0] - '0');
	str_to_hex2(str, &c);
	return (c);
}

int				wchar_to_bytes(t_value value, int i, \
								int count_bytes, char **str)
{
	char	*new;
	char	*big;

	new = conversion(value.val.wstr[i], 16);
	new = binary_conversion(new);
	new = utf8_conversion(new);
	count_bytes += ft_strlen(new) / 2;
	if (value.precision == -1 || count_bytes <= value.precision)
	{
		big = ft_strnew(ft_strlen(new) + ft_strlen(*str));
		big = ft_strcat(big, *str);
		big = ft_strcat(big, new);
		*str = big;
	}
	free(new);
	return (count_bytes);
}
