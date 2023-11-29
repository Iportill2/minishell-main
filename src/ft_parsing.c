/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:18:46 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/29 10:35:58 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_access(t_data *d, int e)
{
	free(d->env_with_access);
	d->env_with_access = NULL;
	d->env_with_access = ft_strjoin(d->array_env[e], d->ar_only_com[0]);
	if (access(d->env_with_access, F_OK) == 0)
		return (d->cmd_not_access = 0, 0);
	else
		d->cmd_not_access = 1;
	free(d->env_with_access);
	d->env_with_access = NULL;
	return (1);
}

void	try_access_readable_writeable_executable(char *s, t_data *d)
{
	d->s = s;
	if (access(s, F_OK) == 0)
	{
		d->not_access = 0;
		if (access(s, W_OK) == 0)
			d->not_writeable = 0;
		else
			d->not_writeable = 1;
		if (access(s, R_OK) == 0)
			d->not_readable = 0;
		else
			d->not_readable = 1;
		if (access(s, X_OK) == 0)
			d->not_executable = 0;
		else
			d->not_executable = 1;
	}
	else
		d->not_access = 1;
}

int	ft_slash_check(char *s)
{
	int			i;
	struct stat	info;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
		{
			if (stat(s, &info) == 0)
			{
				if (S_ISDIR(info.st_mode))
					return (2);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_slash(t_data *d)
{
	if (ft_slash_check(d->ar_only_com[0]) == 1)
	{
		d->env_with_access = ft_strdup(d->ar_only_com[0]);
		if (access(d->env_with_access, F_OK) != 0)
		{
			ft_error_iker(26, d);
			free (d->env_with_access);
			d->env_with_access = NULL;
			return (g_result = 127, 1);
		}
		else
			return (2);
	}
	else if (ft_slash_check(d->ar_only_com[0]) == 2)
		return (ft_error_iker(25, d), g_result = 126, 1);
	return (0);
}

int	ft_try_path_access(t_data *d)
{
	int	e;
	int	j;	

	j = ft_slash(d);
	e = -1;
	while (d->array_env[++e])
	{
		if (j == 1)
			return (1);
		else if (j == 2)
			break ;
		if (ft_get_path(d) == 1)
			return (1);
		else
			ft_repair_path(d);
		if (ft_access(d, e) == 0)
			break ;
	}
	if (d->not_access == 0 && d->not_writeable == 0 && d->not_readable == 0)
		return (ft_pipe_with_sons(d), 0);
	else
		return (d->not_access = 0, d->not_readable = 0, \
		d->not_writeable = 0, 1);
}
