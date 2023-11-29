/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:38:44 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/24 15:59:25 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_create_oldpwd(t_data *d)
{
	int		i;
	char	**temp_env;

	i = 0;
	while (d->custom_env[i])
		i++;
	temp_env = malloc (sizeof(char *) * (i + 2));
	if (!temp_env)
		return (1);
	i = 0;
	while (d->custom_env[i])
	{
		temp_env[i] = ft_strdup(d->custom_env[i]);
		i++;
	}
	temp_env[i++] = ft_strjoin("OLDPWD=", d->current_directory);
	temp_env[i] = NULL;
	ft_free_array(&d->custom_env);
	d->custom_env = temp_env;
	return (0);
}

int	ft_set_oldpwd(t_data *d)
{
	int	i;

	if (d->current_directory)
		free (d->current_directory);
	d->current_directory = NULL;
	d->current_directory = (char *)malloc(sizeof(char) * 1024);
	if (!d->current_directory)
		return (1);
	d->current_directory = getcwd(d->current_directory, 1024);
	i = 0;
	while (d->custom_env[i])
	{
		if (!ft_strncmp(d->custom_env[i], "OLDPWD=", 7))
		{
			free (d->custom_env[i]);
			d->custom_env[i] = ft_strjoin("OLDPWD=", d->current_directory);
			free (d->current_directory);
			d->current_directory = NULL;
			return (0);
		}
		i++;
	}
	return (ft_create_oldpwd(d));
}

int	ft_cd_diacritic(t_data *d)
{
	int	i;

	i = -1;
	while (d->custom_env[++i])
	{
		if (!ft_strncmp(d->custom_env[i], "HOME=", 5))
		{
			ft_set_oldpwd(d);
			g_result = 0;
			if (chdir(d->custom_env[i] + 5))
			{
				d->s = d->custom_env[i] + 5;
				return (ft_error_iker(22, d), g_result = 1, 1);
			}
		}
	}
	if (d->home)
	{
		ft_set_oldpwd(d);
		chdir(d->home);
		g_result = 0;
	}
	else
		printf("cd: wtf!, offenders arround\n");
	return (0);
}

int	ft_cd_hyphen(t_data *d)
{
	int		i;
	int		ok;
	char	*temp;

	i = 0;
	ok = 0;
	while (d->custom_env[i])
	{
		if (!ft_strncmp(d->custom_env[i], "OLDPWD=", 7))
		{
			temp = ft_strdup(d->custom_env[i] + 7);
			ft_set_oldpwd(d);
			chdir (temp);
			free (temp);
			ft_getcwd(d);
			ft_print_current_directory(d);
			ok = 1;
			break ;
		}
		i++;
	}
	if (!ok)
		return (printf("Minitxel: cd: OLDPWD not set\n"), \
		g_result = 1, 1);
	return (g_result = 0, 0);
}

int	ft_cd_home(t_data *d)
{
	int		i;

	i = 0;
	while (d->custom_env[i])
	{
		if (!ft_strncmp(d->custom_env[i], "HOME=", 5))
		{
			ft_set_oldpwd(d);
			g_result = 0;
			if (chdir(d->custom_env[i] + 5))
			{
				d->s = d->custom_env[i] + 5;
				return (ft_error_iker(22, d), g_result = 1, 1);
			}
			else
				return (0);
		}
		i++;
	}
	return (write(1, "cd: HOME not set\n", 17), g_result = 1, 1);
}
