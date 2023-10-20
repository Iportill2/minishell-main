/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:30:52 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:39:52 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			x;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	x = 0;
	while (x < n)
	{
		if (str1[x] != str2[x])
			return ((int)(str1[x] - str2[x]));
		x++;
	}
	return (0);
}
