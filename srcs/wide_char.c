/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:09:25 by barnout           #+#    #+#             */
/*   Updated: 2017/02/06 21:15:19 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char 	*hex_to_binary(char h)
{
	if (h == '0')
		return ("0000");
	if (h == '1')
		return ("0001");
	if (h == '2')
		return ("0010");
	if (h == '3')
		return ("0011");
	if (h == '4')
		return ("0100");
	if (h == '5')
		return ("0101");
	if (h == '6')
		return ("0110");
	if (h == '7')
		return ("0111");
	if (h == '8')
		return ("1000");
	if (h == '9')
		return ("1001");
	if (h == 'a')
		return ("1010");
	if (h == 'b')
		return ("1011");
	if (h == 'c')
		return ("1100");
	if (h == 'd')
		return ("1101");
	if (h == 'e')
		return ("1110");
	if (h == 'f')
		return ("1111");
	return ("error");
}

char	binary_to_hex(char *bi)
{
	if (ft_strncmp(bi, "0000", 4) == 0)
		return ('0');
	if (ft_strncmp(bi, "0001", 4) == 0)
		return ('1');
	if (ft_strncmp(bi, "0010", 4) == 0)
		return ('2');
	if (ft_strncmp(bi, "0011", 4) == 0)
		return ('3');
	if (ft_strncmp(bi, "0100", 4) == 0)
		return ('4');
	if (ft_strncmp(bi, "0101", 4) == 0)
		return ('5');
	if (ft_strncmp(bi, "0110", 4) == 0)
		return ('6');
	if (ft_strncmp(bi, "0111", 4) == 0)
		return ('7');
	if (ft_strncmp(bi, "1000", 4) == 0)
		return ('8');
	if (ft_strncmp(bi, "1001", 4) == 0)
		return ('9');
	if (ft_strncmp(bi, "1010", 4) == 0)
		return ('a');
	if (ft_strncmp(bi, "1011", 4) == 0)
		return ('b');
	if (ft_strncmp(bi, "1100", 4) == 0)
		return ('c');
	if (ft_strncmp(bi, "1101", 4) == 0)
		return ('d');
	if (ft_strncmp(bi, "1110", 4) == 0)
		return ('e');
	if (ft_strncmp(bi, "1111", 4) == 0)
		return ('f');
	return ('?');
}
int		ft_wstrlen_t(wchar_t *wstr_t)
{
	int		i;

	i = 0;
	if (wstr_t == NULL)
		return (0);
	while (wstr_t[i] != 0)
		i++;
	return (i);
}

char	*binary_conversion(char *hex)
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

char	*justify_zeros(char *small)
{
	int		i;
	char	*new;

	i = 0;
	while (small[i] == '0')
		i++;
	new = ft_strdup(&small[i]);
	free(small);
	return (new);
}

char	*add_zeros(char *small, int nb)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	len = ft_strlen(small);
	new = ft_strnew(nb);
	i = 0;
	while (i < nb - len)
	{
		new[i] = '0';
		i++;
	}
	j = 0;
	while (i < nb)
	{
		new[i] = small[j];
		i++;
		j++;
	}
	free(small);
	return (new);
}

char	*fill_bits(char *big, char *small)
{
	int		i;
	int		j;
	int		big_len;
	char	*new;

	i = 0;
	j = 0;
	big_len = ft_strlen(big);
	while (i < big_len)
	{
		if (big[i] == 'x')
			j++;
		i++;
	}
	small = add_zeros(small, j);
	new = ft_strnew(big_len);
	i = 0;
	j = 0;
	while (i < big_len)
	{
		if (big[i] == 'x')
		{
			new[i] = small[j];
			j++;
		}
		else
			new[i] = big[i];
		i++;
	}
	free(small);
	return(new);
}

char	*utf8_conversion(char *small)
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
	if (str[1] == 'a')
		c += 10;
	else if (str[1] == 'b')
		c += 11;
	else if (str[1] == 'c')
		c += 12;
	else if (str[1] == 'd')
		c += 13;
	else if (str[1] == 'e')
		c += 14;
	else if (str[1] == 'f')
		c += 15;
	else 
		c += (str[1] - '0');
	return (c);
}

void	print_wchar(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		c = str_to_hex(&str[i]);
		write(1, &c, 1);
		i += 2;
	}
}

int		print_warg(t_value value)
{
	char	*str;
	int		i;

	i = 0;
	while (i < ft_wstrlen_t(value.val.wstr))
	{
		str = conversion(value.val.wstr[i], 16);
		str = binary_conversion(str);
		str = utf8_conversion(str);
		print_wchar(str);
		i++;
	}
	return (i);
}
