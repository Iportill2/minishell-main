/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:30:08 by iportill          #+#    #+#             */
/*   Updated: 2023/11/27 15:28:58 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_putstr_custom(char *str, int n, t_data *d)
{
	int	i;
	int	spc;

	i = 0;
	spc = 0;
	while (str[i])
		write(1, &str[i++], 1);
	n++;
	if (str[0] != '\0')
	{
		while (d->array_input_clear[n])
		{
			if (d->array_input_clear[n][0] != '\0')
				spc = 1;
			n++;
		}
	}
	if (spc)
		write(1, " ", 1);
}

int	ft_echo(int i, t_data *d)
{
	if (d->not_writeable == 1)
	{
		d->not_writeable = 0;
		return (1);
	}
	d->echo_jump = 1;
	if (d->ar_only_com[i] && !ft_strcmp(d->ar_only_com[i], "-n"))
	{
		d->echo_jump = 0;
		i++;
	}
	while (d->ar_only_com[i])
	{
		ft_putstr_custom(d->ar_only_com[i], i, d);
		i++;
	}
	if (d->echo_jump == 1)
		write(1, "\n", 1);
	return (g_result = 0, 0);
}
