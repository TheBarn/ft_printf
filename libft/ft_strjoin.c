/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:37:22 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 17:26:21 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	size_t			i;
	size_t			len1;
	size_t			len2;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)ft_strnew(len1 + len2 + 1);
	i = 0;
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		dst[i] = s2[i - len1];
		i++;
	}
	return (dst);
}
