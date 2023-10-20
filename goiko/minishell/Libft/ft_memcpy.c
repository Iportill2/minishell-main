/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:30:57 by iportill          #+#    #+#             */
/*   Updated: 2023/07/21 12:15:16 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	len;

	if (!dst && !src)
		return (0);
	len = 0;
	while (len < n)
	{
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		len++;
	}
	return (dst);
}
