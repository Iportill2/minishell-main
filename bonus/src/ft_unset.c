/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:31:54 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:15 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_unstet_imput_error(int i, t_data *g_data)
{
	int	j;

	j = 0;
	while (g_data->array_input_clear[i][j])
	{
		if ((!ft_isalnum(g_data->array_input_clear[i][j]) && \
		g_data->array_input_clear[i][j] != '_') ||
		g_data->array_input_clear[i][j] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int	ft_unset_exec(int j, t_data *d)
{
	int		i;
	int		k;
	char	**temp_env;

	i = 0;
	while (d->custom_env[i])
		i++;
	temp_env = malloc (sizeof(char *) * (i + 1));
	if (!temp_env)
		return (1);
	i = 0;
	k = 0;
	while (d->custom_env[i])
	{
		if (k != j)
			temp_env[i++] = ft_strdup(d->custom_env[k++]);
		else
			k++;
	}
	temp_env[i] = NULL;
	ft_free_array(&d->custom_env);
	d->custom_env = temp_env;
	return (0);
}

int	ft_unset(int i, t_data *d)
{
	int	j;

	if (d->pipe_check)
		return (0);
	while (d->ar_only_com[i] && d->ar_only_com[i][0] != '|')
	{
		j = 0;
		while (d->custom_env[j])
		{
			if (ft_unstet_imput_error(i, d))
				return (ft_error_iker(20, d), g_result = 1, 1);
			if (!ft_strncmp(d->ar_only_com[i], d->custom_env[j], \
			ft_strlen(d->ar_only_com[i])) && \
			d->custom_env[j][ft_strlen(d->ar_only_com[i])] == '=')
				return (ft_unset_exec(j, d), 0);
			j++;
		}
		i++;
	}
	return (0);
}
