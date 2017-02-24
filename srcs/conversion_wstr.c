/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:09:25 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 11:10:47 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*hex_to_binary2(char h)
{
	if (h == '8')
		return ("1000");
	else if (h == '9')
		return ("1001");
	else if (h == 'a')
		return ("1010");
	else if (h == 'b')
		return ("1011");
	else if (h == 'c')
		return ("1100");
	else if (h == 'd')
		return ("1101");
	else if (h == 'e')
		return ("1110");
	else if (h == 'f')
		return ("1111");
	else
		return ("error");
}

char			*hex_to_binary(char h)
{
	if (h == '0')
		return ("0000");
	else if (h == '1')
		return ("0001");
	else if (h == '2')
		return ("0010");
	else if (h == '3')
		return ("0011");
	else if (h == '4')
		return ("0100");
	else if (h == '5')
		return ("0101");
	else if (h == '6')
		return ("0110");
	else if (h == '7')
		return ("0111");
	else
		return (hex_to_binary2(h));
}

static char		binary_to_hex2(char *bi)
{
	if (ft_strncmp(bi, "1000", 4) == 0)
		return ('8');
	else if (ft_strncmp(bi, "1001", 4) == 0)
		return ('9');
	else if (ft_strncmp(bi, "1010", 4) == 0)
		return ('a');
	else if (ft_strncmp(bi, "1011", 4) == 0)
		return ('b');
	else if (ft_strncmp(bi, "1100", 4) == 0)
		return ('c');
	else if (ft_strncmp(bi, "1101", 4) == 0)
		return ('d');
	else if (ft_strncmp(bi, "1110", 4) == 0)
		return ('e');
	else if (ft_strncmp(bi, "1111", 4) == 0)
		return ('f');
	else
		return ('?');
}

char			binary_to_hex(char *bi)
{
	if (ft_strncmp(bi, "0000", 4) == 0)
		return ('0');
	else if (ft_strncmp(bi, "0001", 4) == 0)
		return ('1');
	else if (ft_strncmp(bi, "0010", 4) == 0)
		return ('2');
	else if (ft_strncmp(bi, "0011", 4) == 0)
		return ('3');
	else if (ft_strncmp(bi, "0100", 4) == 0)
		return ('4');
	else if (ft_strncmp(bi, "0101", 4) == 0)
		return ('5');
	else if (ft_strncmp(bi, "0110", 4) == 0)
		return ('6');
	else if (ft_strncmp(bi, "0111", 4) == 0)
		return ('7');
	else
		return (binary_to_hex2(bi));
}
