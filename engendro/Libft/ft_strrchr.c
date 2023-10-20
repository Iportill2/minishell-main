/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:24 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:38 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_chr;

	last_chr = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_chr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_chr);
}
