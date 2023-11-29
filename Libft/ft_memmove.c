/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:01 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:39:57 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*p_src;
	char		*p_dst;
	size_t		x;

	p_src = (char *)src;
	p_dst = (char *)dst;
	x = -1;
	if (!src && !dst)
		return (NULL);
	if (p_src < p_dst)
	{
		while (len-- > 0)
			p_dst[len] = p_src[len];
	}
	else
	{
		while (++x < len)
			p_dst[x] = p_src[x];
	}
	return (dst);
}
