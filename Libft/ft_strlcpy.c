/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:03 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:25 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	srcsize = ft_strlen(src);
	len = 0;
	if (dstsize != 0)
	{
		while (src[len] && len < (dstsize - 1))
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (srcsize);
}
