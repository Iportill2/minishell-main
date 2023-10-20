/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:52 by iportill          #+#    #+#             */
/*   Updated: 2023/09/28 15:59:08 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 && !s2)
		return (0);
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ptr[len - 1] = '\0';
	ft_strlcpy(ptr, s1, len);
	ft_strlcat(ptr, s2, len);
	return (ptr);
}
