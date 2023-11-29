/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:21:57 by iportill          #+#    #+#             */
/*   Updated: 2023/11/24 16:06:11 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_sort(char **ar)
{
	int		i;
	char	*temp;

	i = 0;
	while (ar && ar[i])
	{
		if (ar[i + 1] && ft_strcmp(ar[i], ar[i + 1]) > 0)
		{
			temp = ar[i];
			ar[i] = ar[i + 1];
			ar[i + 1] = temp;
		}
		i++;
	}
	return (0);
}

int	ft_check_sort(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (ar[i + 1] && ft_strcmp(ar[i], ar[i + 1]) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_export_no_arg(t_data *d)
{
	char	**temp;
	int		i;

	i = 0;
	while (d->custom_env[i])
		i++;
	temp = (char **) malloc (sizeof(char *) * (i + 1));
	if (!temp)
		return (ft_error_iker(4, d), 1);
	i = -1;
	while (d->custom_env[++i])
		temp[i] = ft_strdup(d->custom_env[i]);
	temp[i] = NULL;
	i = 0;
	while (ft_check_sort(temp))
		ft_sort(temp);
	i = 0;
	while (temp[i])
		printf("declare -x %s\n", temp[i++]);
	ft_free_array(&temp);
	return (0);
}
