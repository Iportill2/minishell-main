/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:05 by iportill          #+#    #+#             */
/*   Updated: 2023/11/27 16:11:08 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cleaning_oldpwd(t_data *d)
{
	int	i;

	i = 0;
	while (d->custom_env[i])
	{
		if (strncmp(d->custom_env[i], "OLDPWD=", 7) == 0)
		{
			ft_unset_exec(i, d);
			break ;
		}
		i++;
	}
}

int	ft_print_env(t_data *d)
{
	int	i;

	i = 0;
	while (d->custom_env && d->custom_env[i])
	{
		printf("%s\n", d->custom_env[i]);
		i++;
	}
	return (0);
}

void	ft_print_current_directory(t_data *d)
{
	printf("%s\n", d->current_directory);
	free(d->current_directory);
	d->current_directory = NULL;
}

void	ft_getcwd(t_data *d)
{
	d->current_directory = (char *)malloc(1024);
	if (d->current_directory == NULL)
	{
		perror("Error al asignar memoria para el búfer");
		return ;
	}
	d->current_directory = getcwd(d->current_directory, 1024);
}

void	ft_get_print_cwd(t_data *d)
{
	ft_getcwd(d);
	ft_print_current_directory(d);
	g_result = 0;
}
