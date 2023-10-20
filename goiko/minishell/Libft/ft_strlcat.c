/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:58 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:22 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	len = 0;
	if (!dstsize)
		return (srclen);
	while (src[len] && (dstlen + len) < (dstsize - 1))
	{
		dst[dstlen + len] = src[len];
		len++;
	}
	dst[dstlen + len] = '\0';
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}
