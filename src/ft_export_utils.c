/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:01:05 by iportill          #+#    #+#             */
/*   Updated: 2023/11/27 12:09:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export_add(char *s, t_data *d)
{
	int		i;
	char	**temp;

	i = 0;
	while (d->custom_env[i])
		i++;
	temp = (char **) malloc (sizeof(char *) * (i + 2));
	if (!temp)
		return (ft_error_iker(4, d), 1);
	i = 0;
	while (d->custom_env[i])
	{
		temp[i] = ft_strdup(d->custom_env[i]);
		i++;
	}
	temp[i++] = ft_strdup(s);
	temp[i] = NULL;
	ft_free_array(&d->custom_env);
	d->custom_env = temp;
	return (0);
}

int	ft_export_change(int j, char *s, t_data *d)
{
	free(d->custom_env[j]);
	d->custom_env[j] = ft_strdup(s);
	return (0);
}

int	ft_export_exec(char *s, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	j = 0;
	while (d->custom_env[j])
	{
		if (!ft_strncmp(d->custom_env[j], s, i + 1))
			return (ft_export_change(j, s, d), 0);
		j++;
	}
	ft_export_add(s, d);
	return (0);
}

int	ft_export_error(char *s, t_data *d, int i)
{
	int	j;

	j = 0;
	if (s && s[j] == '=')
		return (d->int_export = i, ft_error_iker(16, d), g_result = 1, 1);
	while (s[j] && s[j] != '=')
	{
		if (s[j] == ' ' || (ft_isalnum(s[j]) == 0 && s[j] != '_'))
			return (d->int_export = i, ft_error_iker(16, d), g_result = 1, 1);
		j++;
	}
	if (s[j] != '=')
		return (g_result = 0, 2);
	return (0);
}

int	ft_export(int i, t_data *d)
{
	if (d->pipe_check && d->ar_only_com[1])
		return (0);
	if (!d->ar_only_com[1])
		return (ft_export_no_arg(d), 0);
	while (d->ar_only_com[i])
	{
		if (ft_export_error(d->ar_only_com[i], d, i) == 0)
			ft_export_exec(d->ar_only_com[i], d);
		i++;
	}
	return (0);
}
