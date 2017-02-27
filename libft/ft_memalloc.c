/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:10:56 by barnout           #+#    #+#             */
/*   Updated: 2016/11/27 16:58:11 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, size);
	return (dst);
}
