/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:59:41 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:03:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Codigo  de error -1: %s\n", strerror(-1));
	printf("Codigo  de error 0: %s\n", strerror(0));
	printf("Codigo  de error 1: %s\n", strerror(1));
	printf("Codigo  de error 2: %s\n", strerror(2));
	return (0);
}