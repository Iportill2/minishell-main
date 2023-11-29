/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:20 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:34 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[x] && x < len)
	{
		if (haystack[x] == needle[0])
		{
			y = 1;
			while (haystack[x + y] == needle[y] && (x + y) < len && needle[y])
				++y;
			if (needle[y] == '\0')
				return ((char *)&haystack[x]);
		}
		++x;
	}
	return (NULL);
}
