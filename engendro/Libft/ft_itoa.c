/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:29:56 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:39:11 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_alocate(long number, int len, char *str)
{
	while (number > 0)
	{
		str[len] = '0' + (number % 10);
		number = number / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	number;
	int		len;

	number = nb;
	len = nb_len(number);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (number == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	return (ft_alocate(number, len, str));
}
