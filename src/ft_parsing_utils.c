/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:45:03 by iportill          #+#    #+#             */
/*   Updated: 2023/11/28 13:46:52 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_path(t_data *d)
{
	d->env_path = ft_getenv("PATH", d);
	if (d->env_path == NULL)
	{
		dup2(d->original_stdout, STDOUT_FILENO);
		d->s = d->ar_only_com[0];
		ft_error_iker(22, d);
		g_result = 127;
		return (1);
	}
	return (0);
}

void	ft_repair_path(t_data *d)
{
	int		i;
	char	*temp;

	i = 0;
	if (d->array_env)
		ft_free_array(&d->array_env);
	d->array_env = ft_split(d->env_path, ':');
	if (d->array_env[0] == NULL)
	{
		ft_error_iker(4, d);
		return ;
	}
	while (d->array_env[i])
	{
		temp = d->array_env[i];
		d->array_env[i] = ft_strjoin(d->array_env[i], "/");
		free(temp);
		i++;
	}
}
