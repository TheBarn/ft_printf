/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:44:03 by barnout           #+#    #+#             */
/*   Updated: 2017/02/22 14:19:33 by barnout          ###   ########.fr       */
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

static int				u_count_digit(unsigned int n)
{
	int				count;

	count = 1;
	while (n > 9)
	{
		n = (n - (n % 10)) / 10;
		count++;
	}
	return (count);
}

static int				umax_count_digit(uintmax_t n)
{
	int				count;

	count = 1;
	while (n > 9)
	{
		n = (n - (n % 10)) / 10;
		count++;
	}
	return (count);
}

char					*ft_utoa(unsigned int n)
{
	char			*dst;
	int				i;
	int				count;

	count = u_count_digit(n);
	dst = ft_strnew(count); 
	i = count - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 + 48;
		n = (n - (n % 10)) / 10;
		i--;
	}
	return (dst);
}

char					*ft_uimaxtoa(uintmax_t n)
{
	char			*dst;
	int				i;
	int				count;

	count = umax_count_digit(n);
	dst = ft_strnew(count); 
	i = count - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 + 48;
		n = (n - (n % 10)) / 10;
		i--;
	}
	return (dst);
}

static uintmax_t	imax_cast(intmax_t n)
{
	uintmax_t	nb;

	if (n < 0)
		nb = (uintmax_t)-n;
	else
		nb = (uintmax_t)n;
	return (nb);
}

static int				imaxcount_digit(intmax_t n)
{
	int					count;
	unsigned long long	nb;

	count = 1;
	if (n < 0)
		nb = (uintmax_t)-n;
	else
		nb = (uintmax_t)n;
	while (nb > 9)
	{
		nb = (nb - (nb % 10)) / 10;
		count++;
	}
	return (count);
}

char					*ft_imaxtoa(intmax_t n)
{
	char				*dst;
	int					toto;
	uintmax_t			nb;
	int					i;
	int					count;

	toto = 0;
	if (n < 0)
		toto = 1;
	count = imaxcount_digit(n);
	dst = (char *)malloc(count + toto + 1);
	if (dst == NULL)
		return (NULL);
	i = toto + count - 1;
	nb = imax_cast(n);
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
