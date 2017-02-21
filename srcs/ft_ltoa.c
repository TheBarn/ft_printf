/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:44:03 by barnout           #+#    #+#             */
/*   Updated: 2016/11/27 18:24:47 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				count_digit(long n)
{
	int				count;
	unsigned long	nb;

	count = 1;
	if (n < 0)
		nb = (unsigned long)-n;
	else
		nb = (unsigned long)n;
	while (nb > 9)
	{
		nb = (nb - (nb % 10)) / 10;
		count++;
	}
	return (count);
}

static unsigned long	cast(long n)
{
	unsigned long	nb;

	if (n < 0)
		nb = (unsigned long)-n;
	else
		nb = (unsigned long)n;
	return (nb);
}

char					*ft_ltoa(long n)
{
	char			*dst;
	int				toto;
	unsigned long	nb;
	int				i;
	int				count;
	
	toto = 0;
	if (n < 0)
		toto = 1;
	count = count_digit(n);
	dst = (char *)malloc(count + toto + 1);
	if (dst == NULL)
		return (NULL);
	i = toto + count - 1;
	nb = cast(n);
	while (i >= toto)
	{
		dst[i] = nb % 10 + 48;
		nb = (nb - (nb % 10)) / 10;
		i--;
	}
	if (toto == 1)
		dst[0] = '-';
	dst[count + toto] = '\0';
	return (dst);
}
